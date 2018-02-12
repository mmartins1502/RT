/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_rect_top.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 01:47:58 by itonoli-          #+#    #+#             */
/*   Updated: 2017/12/10 01:49:40 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void (*g_top_btn[])(t_env *e) =
{
	light_object,
	marble_object,
	switch_obj_tx,
	switch_tsp_tx,
	delete_object,
	switch_skybox,
	switch_filter,
	save_scene,
	set_render_edition_mode,
};

void		is_mouse_in_rect_top(t_env *e)
{
	int state;
	int btn_i;

	draw_all_button_top(e);
	btn_i = is_mouse_in_rect(e, e->bt_rect, 9);
	if (btn_i != -1)
	{
		state = e->event.type == SDL_MOUSEBUTTONDOWN ? CLICK : MOUSE;
		draw_button_top(e, btn_i, state);
		if (state == CLICK)
		{
			if (btn_i != 7)
				set_live_edition_mode(e);
			g_top_btn[btn_i](e);
		}
	}
}

void		is_mouse_in_rect_top_input(t_env *e)
{
	int state;
	int btn_i;

	btn_i = is_mouse_in_rect(e, e->topin_rect, 3);
	if (btn_i != -1)
	{
		if (btn_i != e->topin_actif)
		{
			state = e->event.type == SDL_MOUSEBUTTONDOWN ? CLICK : 0;
			if (state == CLICK)
			{
				draw_input_top(e, e->topin_actif, 0);
				e->topin_actif = btn_i;
				draw_input_top(e, btn_i, state);
			}
		}
		else if (e->event.type == SDL_MOUSEBUTTONDOWN)
		{
			draw_input_top(e, btn_i, 0);
			e->topin_actif = -1;
		}
	}
}
