/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mickey_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 17:48:25 by itonoli-          #+#    #+#             */
/*   Updated: 2017/12/10 21:30:12 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void		where_is_mickey(t_env *e)
{
	if ((e->event.type == SDL_MOUSEMOTION ||
		e->event.type == SDL_MOUSEBUTTONDOWN))
	{
		is_mouse_in_rect_top_input(e);
		is_mouse_in_rect_left(e);
		is_mouse_in_rect_top(e);
		is_mouse_in_render(e);
		is_mouse_in_credit(e);
		if (e->credit_actif && e->event.type == SDL_MOUSEMOTION)
			e->credit_actif = 0;
	}
	draw_selected(e);
}

void		is_mouse_in_render(t_env *e)
{
	int i;
	int j;

	i = e->mouse.x;
	j = e->mouse.y;
	if (e->event.type == SDL_MOUSEBUTTONDOWN && e->help_actif != 1)
	{
		if (i > 82 && i < 82 + F_WIDTH && (j > 72 && j < 72 + F_WIDTH))
		{
			e->i_actif = -1;
			e->it_actif = -1;
			if (e->topin_actif != -1)
			{
				draw_input_top(e, e->topin_actif, 0);
				write_top_text(e);
				e->topin_actif = -1;
			}
			create_border(e, 1);
			select_obj(i - 82, j - 72, e);
		}
		else
			create_border(e, 0);
	}
}
