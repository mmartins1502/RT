/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:13:22 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/11 17:09:46 by tdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void		reset_screen(t_env *e)
{
	int	i;
	int j;

	i = -1;
	while (++i < (int)F_WIDTH)
	{
		j = -1;
		while (++j < (int)F_HEIGHT)
		{
			e->frame_array[j][i] = 0;
			e->color_array[j][i].x = 0;
			e->color_array[j][i].y = 0;
			e->color_array[j][i].z = 0;
		}
	}
}

static void	write_buffer(t_env *e)
{
	int			i;
	int			j;
	t_vector	c;

	i = -1;
	while (++i < (int)F_WIDTH)
	{
		j = -1;
		while (++j < (int)F_HEIGHT)
		{
			c = e->color_array[j][i];
			c = adjust_color(c);
			g_buffer[(i * (int)F_HEIGHT) + j] =
			((int)c.x << 16) + ((int)c.y << 8) + (int)c.z;
		}
	}
}

void		draw_screen(t_env *e)
{
	pthread_t	tid[e->threads];
	int			i;
	t_env		*copy;

	reset_screen(e);
	copy = NULL;
	i = -1;
	while (++i < e->threads)
	{
		copy = (t_env *)ft_memalloc(sizeof(t_env));
		init_copy(e, copy, i);
		if (pthread_create(&tid[i], NULL, (void *)compute_block, copy) != 0)
		{
			printf("FATAL ERROR : Failed to create thread\n");
			exit(EXIT_FAILURE);
		}
	}
	i = -1;
	while (++i < e->threads)
		pthread_join(tid[i], NULL);
	write_buffer(e);
}
