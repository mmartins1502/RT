/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_buttons.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 22:43:16 by itonoli-          #+#    #+#             */
/*   Updated: 2017/12/10 23:15:51 by tdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void		draw_button_left(t_env *e, int b_num, int state)
{
	SDL_Rect rect;

	if (b_num != 9)
	{
		rect = e->b_rect[b_num];
		(state == 1) ? rect.x += 82 : 0;
		(state == 2) ? rect.x += 162 : 0;
		SDL_BlitSurface(e->s_ui, &rect, e->s_background, &e->b_rect[b_num]);
	}
}

void		draw_input(t_env *e, int i_num, int state)
{
	SDL_Rect rect;

	rect = e->i_rect[i_num];
	(state == 2) ? rect.x -= 750 : 0;
	SDL_BlitSurface(e->s_ui, &rect, e->s_background, &e->i_rect[i_num]);
}

void		draw_all_button_left(t_env *e)
{
	int i;

	i = -1;
	while (++i < 9)
	{
		SDL_BlitSurface(e->s_ui, &e->b_rect[i], e->s_background, &e->b_rect[i]);
	}
}
