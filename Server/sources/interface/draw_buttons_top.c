/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_buttons_top.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 14:24:23 by itonoli-          #+#    #+#             */
/*   Updated: 2017/12/10 03:01:22 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void		draw_input_top(t_env *e, int bt_num, int state)
{
	SDL_Rect rect;

	rect = e->topin_rect[bt_num];
	(state == 2) ? rect.y += 60 : 0;
	SDL_BlitSurface(e->s_ui, &rect, e->s_background, &e->topin_rect[bt_num]);
	write_top_text(e);
}

void		draw_button_top(t_env *e, int bt_num, int state)
{
	SDL_Rect rect;

	if (bt_num != 8)
	{
		rect = e->bt_rect[bt_num];
		(state == 1) ? rect.y += 60 : 0;
		(state == 2) ? rect.y += 120 : 0;
		SDL_BlitSurface(e->s_ui, &rect, e->s_background, &e->bt_rect[bt_num]);
	}
	else
	{
		rect = e->bt_rect[bt_num];
		(state == 1) ? rect.x -= 200 : 0;
		(state == 1) ? rect.y += 200 : 0;
		(state == 2) ? rect.x -= 400 : 0;
		(state == 2) ? rect.y += 200 : 0;
		SDL_BlitSurface(e->s_ui, &rect, e->s_background, &e->bt_rect[bt_num]);
	}
}

void		draw_all_button_top(t_env *e)
{
	int i;

	i = -1;
	while (++i < 9)
	{
		SDL_BlitSurface(e->s_ui, &e->bt_rect[i], e->s_background,
			&e->bt_rect[i]);
	}
}
