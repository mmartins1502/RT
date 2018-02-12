/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:12:52 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static int g_key[] =
{
	SDLK_w,
	SDLK_a,
	SDLK_s,
	SDLK_d,
	SDLK_q,
	SDLK_e,
	SDLK_SPACE,
	SDLK_c,
	SDLK_LEFT,
	SDLK_RIGHT,
	SDLK_UP,
	SDLK_DOWN,
	SDLK_KP_MINUS,
	SDLK_KP_PLUS,
	SDLK_KP_8,
	SDLK_KP_4,
	SDLK_KP_6,
	SDLK_KP_2,
	SDLK_KP_7,
	SDLK_KP_9,
	SDLK_RETURN,
	SDLK_m,
	0
};

static const int g_key_value[255] =
{
	['w'] = SDLK_w,
	['a'] = SDLK_a,
	['s'] = SDLK_s,
	['d'] = SDLK_d,
	['q'] = SDLK_q,
	['e'] = SDLK_e,
	[' '] = SDLK_SPACE,
	['c'] = SDLK_c,
	[127 + 'l'] = SDLK_LEFT,
	[127 + 'r'] = SDLK_RIGHT,
	[127 + 'u'] = SDLK_UP,
	[127 + 'd'] = SDLK_DOWN,
	[127 + 'm'] = SDLK_KP_MINUS,
	[127 + 'p'] = SDLK_KP_PLUS,
	[127 + '8'] = SDLK_KP_8,
	[127 + '4'] = SDLK_KP_4,
	[127 + '6'] = SDLK_KP_6,
	[127 + '2'] = SDLK_KP_2,
	[127 + '7'] = SDLK_KP_7,
	[127 + '9'] = SDLK_KP_9,
	[127 + 'R'] = SDLK_RETURN,
	['m'] = SDLK_m,
};

void	turn_left(t_env *e)
{
	keyboard(SDLK_d, e);
	keyboard(SDLK_d, e);
	keyboard(SDLK_LEFT, e);
}

void	turn_right(t_env *e)
{
	keyboard(SDLK_a, e);
	keyboard(SDLK_a, e);
	keyboard(SDLK_RIGHT, e);
}

static void (*g_key_func[255])(t_env *e) =
{
	['w'] = move_forward,
	['a'] = move_left,
	['s'] = move_backward,
	['d'] = move_right,
	['q'] = turn_right,
	['e'] = turn_left,
	[' '] = move_up,
	['c'] = move_down,
	[127 + 'l'] = yaw_left,
	[127 + 'r'] = yaw_right,
	[127 + 'u'] = pitch_up,
	[127 + 'd'] = pitch_down,
	[127 + 'm'] = move_ojbect_down,
	[127 + 'p'] = move_ojbect_up,
	[127 + '8'] = move_ojbect_forward,
	[127 + '4'] = move_ojbect_left,
	[127 + '6'] = move_ojbect_right,
	[127 + '2'] = move_ojbect_backward,
	[127 + '7'] = decrease_limit,
	[127 + '9'] = increase_limit,
	[127 + 'R'] = set_render_edition_mode,
	['m'] = switch_damier
};

int		is_acceptable_key(int key)
{
	int *all_keys;

	all_keys = g_key;
	while (*all_keys)
	{
		if (*all_keys == key)
			return (key);
		all_keys++;
	}
	return (0);
}

void	call_function(t_env *e, int key)
{
	int	i;

	if (!e->live)
		reset_screen();
	i = -1;
	while (++i < 255)
	{
		if (g_key_value[i] == key)
		{
			g_key_func[i](e);
			break ;
		}
	}
}

int		keyboard(int key, t_env *e)
{
	if (!is_acceptable_key(key))
		return (0);
	if (!e->live)
		switch_render_mode(e);
	call_function(e, key);
	return (0);
}
