/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 14:43:01 by itonoli-          #+#    #+#             */
/*   Updated: 2017/12/10 17:48:33 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void		(*g_top_input[])(t_env *e, int mode) =
{
	change_rebond,
	change_rot_speed,
	change_move_speed,
};

void			change_values_top_input(t_env *e)
{
	if (e->topin_actif != -1)
	{
		if (e->event.key.keysym.sym == SDLK_DOWN)
			g_top_input[(int)e->topin_actif](e, DECREASE);
		else if (e->event.key.keysym.sym == SDLK_UP)
			g_top_input[(int)e->topin_actif](e, INCREASE);
		else if (e->event.key.keysym.sym == SDLK_LEFT)
			g_top_input[(int)e->topin_actif](e, DECREASE_MAX);
		else if (e->event.key.keysym.sym == SDLK_RIGHT)
			g_top_input[(int)e->topin_actif](e, INCREASE_MAX);
	}
}

static void		(*g_right_top_input[])(t_env *e, int mode) =
{
	change_type,
	change_light,
	change_fuzz,
	change_reflection,
	change_refraction,
	change_radius_angle,
};

void			change_right_top_input(t_env *e)
{
	if (e->i_actif != -1 && e->i_actif < 6)
	{
		if (e->event.key.keysym.sym == SDLK_DOWN)
			g_right_top_input[(int)e->i_actif](e, DECREASE);
		else if (e->event.key.keysym.sym == SDLK_UP)
			g_right_top_input[(int)e->i_actif](e, INCREASE);
		else if (e->event.key.keysym.sym == SDLK_LEFT)
			g_right_top_input[(int)e->i_actif](e, DECREASE_MAX);
		else if (e->event.key.keysym.sym == SDLK_RIGHT)
			g_right_top_input[(int)e->i_actif](e, INCREASE_MAX);
		set_live_edition_mode(e);
	}
}

static void		(*g_right_input[])(t_env *e, int mode) =
{
	change_color_r,
	change_color_g,
	change_color_b,
	rotate_object_x,
	rotate_object_y,
	rotate_object_z,
	damier_marble_r,
	damier_marble_g,
	damier_marble_b,
	dam_two_color_r,
	dam_two_color_g,
	dam_two_color_b,
};

void			change_right_input(t_env *e)
{
	if (e->i_actif >= 6 && e->it_actif >= 6)
	{
		if (e->event.key.keysym.sym == SDLK_DOWN)
			g_right_input[(int)e->it_actif - 6](e, DECREASE);
		else if (e->event.key.keysym.sym == SDLK_UP)
			g_right_input[(int)e->it_actif - 6](e, INCREASE);
		else if (e->event.key.keysym.sym == SDLK_LEFT)
			g_right_input[(int)e->it_actif - 6](e, DECREASE_MAX);
		else if (e->event.key.keysym.sym == SDLK_RIGHT)
			g_right_input[(int)e->it_actif - 6](e, INCREASE_MAX);
		set_live_edition_mode(e);
	}
}

void			change_inputs(t_env *e)
{
	change_values_top_input(e);
	change_right_top_input(e);
	change_right_input(e);
	write_top_text(e);
}
