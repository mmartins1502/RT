/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:13:22 by nsampre           #+#    #+#             */
/*   Updated: 2017/11/28 22:58:45 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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
	if (e->render)
		SDL_BlitSurface(e->s_raytracer, &(SDL_Rect){0, 0, F_WIDTH, F_HEIGHT},
					e->s_background, &(SDL_Rect){82, 72, F_WIDTH, F_HEIGHT});
	e->sum = 1;
}

static void	print_screen(t_env *e)
{
	int			i;
	int			j;
	t_vector	c;
	SDL_Rect	pixel;

	i = -1;
	while (++i < (int)F_WIDTH)
	{
		j = -1;
		while (++j < (int)F_HEIGHT)
		{
			c = e->color_array[j][i];
			c = vector_scale(c, 1.0 / (double)e->sum);
			c = adjust_color(c);
			pixel = (SDL_Rect){.w = 1, .h = 1, .x = i, .y = j};
			SDL_FillRect(e->s_raytracer, &pixel,
						SDL_MapRGB(e->s_raytracer->format, c.x, c.y, c.z));
		}
	}
	if (e->render)
		SDL_BlitSurface(e->s_raytracer, &(SDL_Rect){0, 0, F_WIDTH, F_HEIGHT},
					e->s_background, &(SDL_Rect){82, 72, F_WIDTH, F_HEIGHT});
}

void		draw_screen(t_env *e)
{
	pthread_t	tid[e->threads];
	int			i;
	t_env		*copy;

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
	print_screen(e);
}
