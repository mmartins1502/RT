/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 23:35:47 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/11 17:32:43 by tdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	copy_pixel_to_sdl(t_env *e, SDL_Surface *s, ssize_t x, ssize_t y)
{
	int			c;
	t_vector	v_color;

	if (!e->sum)
		return ;
	v_color = vector_scale(g_buffer[x * (int)F_HEIGHT + y], 1 / (double)e->sum);
	if (e->filter == 1)
		sepia(&v_color);
	else if (e->filter == 2)
		black_and_white(&v_color);
	else if (e->filter == 3)
		negative(&v_color);
	c = 0xFF000000;
	c |= ((int)v_color.x << 16) + ((int)v_color.y << 8) + (int)v_color.z;
	*((int *)(s->pixels + y * s->pitch + x * s->format->BytesPerPixel)) = c;
}

void	display_buffer(t_env *e)
{
	ssize_t		x;
	ssize_t		y;

	y = -1;
	while (++y < F_HEIGHT)
	{
		x = -1;
		while (++x < F_WIDTH)
		{
			copy_pixel_to_sdl(e, e->s_raytracer, x, y);
		}
	}
	if (e->render == 1)
	{
		if (e->help_actif != 1 && e->credit_actif != 1)
			SDL_BlitSurface(e->s_raytracer,
			&(SDL_Rect){0, 0, F_WIDTH, F_HEIGHT}, e->s_background,
			&(SDL_Rect){82, 72, F_WIDTH, F_HEIGHT});
	}
}

void	reset_screen(void)
{
	int	i;
	int j;

	i = -1;
	while (++i < (int)F_WIDTH)
	{
		j = -1;
		while (++j < (int)F_HEIGHT)
		{
			g_buffer[j * (int)F_WIDTH + i] = (t_vector){0, 0, 0};
		}
	}
}
