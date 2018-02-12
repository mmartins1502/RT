/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_rect_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 23:05:01 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/10 03:03:09 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int			is_mouse_in_rect(t_env *e, SDL_Rect *rect, int rect_len)
{
	int i;

	i = -1;
	while (++i < rect_len)
	{
		if (SDL_PointInRect(&e->mouse, &rect[i]))
			return (i);
	}
	return (-1);
}

static void (*g_left_btn[])(t_env *e) =
{
	create_sphere,
	create_cylinder,
	create_plane,
	create_torus,
	create_cone,
	create_cube,
	atom,
	dna,
	cube_with_spheres,
	set_helper,
};

void		is_mouse_in_rect_left(t_env *e)
{
	int state;
	int btn_i;

	btn_i = is_mouse_in_rect(e, e->b_rect, 10);
	draw_all_button_left(e);
	if (btn_i != -1)
	{
		state = e->event.type == SDL_MOUSEBUTTONDOWN ? CLICK : MOUSE;
		e->b_actif = (state == CLICK) ? btn_i : e->b_actif;
		draw_button_left(e, btn_i, state);
		if (state == CLICK)
		{
			set_live_edition_mode(e);
			g_left_btn[btn_i](e);
		}
	}
}
