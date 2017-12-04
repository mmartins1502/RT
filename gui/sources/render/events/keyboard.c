/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:12:52 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/04 17:22:41 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"


void	create_cone(t_env *e)
{
	t_obj *obj;

	obj = new_obj();
	obj->type = OBJ_CONE;
	obj->color = (t_vector){randb(), randb(), randb()};
	obj->ori.x = e->camera.ori.x - (10.0 * MOVE_SPEED * cos(PITCH) * sin(YAW));
	obj->ori.y = e->camera.ori.y + (10.0 * MOVE_SPEED * sin(PITCH));
	obj->ori.z = e->camera.ori.z + (10.0 * MOVE_SPEED * cos(PITCH) * cos(YAW));
	obj->dir.x = 0;
	obj->dir.y = -1;
	obj->dir.z = 0;
	obj->radius = 3;
	obj_push_back(&e->objects, obj);
}


void	create_plane(t_env *e)
{
	t_obj *obj;

	obj = new_obj();
	obj->type = OBJ_PLANE;
	obj->color = (t_vector){randb(), randb(), randb()};
	obj->ori.x = e->camera.ori.x - (10.0 * MOVE_SPEED * cos(PITCH) * sin(YAW));
	obj->ori.y = e->camera.ori.y + (10.0 * MOVE_SPEED * sin(PITCH));
	obj->ori.z = e->camera.ori.z + (10.0 * MOVE_SPEED * cos(PITCH) * cos(YAW));
	obj->dir.x = 0;
	obj->dir.y = -1;
	obj->dir.z = 0;
	obj_push_back(&e->objects, obj);
}

void	create_cylinder(t_env *e)
{
	t_obj *obj;

	obj = new_obj();
	obj->type = OBJ_CYL;
	obj->radius = 30;
	obj->color = (t_vector){randb(), randb(), randb()};
	obj->ori.x = e->camera.ori.x - (10.0 * MOVE_SPEED * cos(PITCH) * sin(YAW));
	obj->ori.y = e->camera.ori.y + (10.0 * MOVE_SPEED * sin(PITCH));
	obj->ori.z = e->camera.ori.z + (10.0 * MOVE_SPEED * cos(PITCH) * cos(YAW));
	obj->dir.x = 0;
	obj->dir.y = 1;
	obj->dir.z = 0;
	obj_push_back(&e->objects, obj);
}

void	create_sphere(t_env *e)
{
	t_obj *obj;

	obj = new_obj();
	obj->type = OBJ_SPHERE;
	obj->radius = 100;
	obj->color = (t_vector){randb(), randb(), randb()};
	obj->ori.x = e->camera.ori.x - (10.0 * MOVE_SPEED * cos(PITCH) * sin(YAW));
	obj->ori.y = e->camera.ori.y + (10.0 * MOVE_SPEED * sin(PITCH));
	obj->ori.z = e->camera.ori.z + (10.0 * MOVE_SPEED * cos(PITCH) * cos(YAW));
	/////////////// LIGHT ///////////////
	// obj->color = (t_vector){255, 255, 255};
	obj->emit = 1;
	obj->light = (t_vector){255, 255, 255};
	obj_push_back(&e->objects, obj);
}

void	compute_frame(t_env *e)
{
	e->increment = 1;
	e->recursion = 10;
	draw_screen(e);
	e->sum++;
}

static int g_key[] =
{
	SDLK_y,
	// SDLK_b,
	SDLK_n,
	SDLK_m,
	SDLK_f,
	SDLK_p,
	SDLK_w,
	SDLK_a,
	SDLK_s,
	SDLK_d,
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
	0
};

static const int g_key_value[255] =
{
	['y'] = SDLK_y,
	// ['b'] = SDLK_b,
	['n'] = SDLK_n,
	['m'] = SDLK_m,
	['f'] = SDLK_f,
	['p'] = SDLK_p,
	['w'] = SDLK_w,
	['a'] = SDLK_a,
	['s'] = SDLK_s,
	['d'] = SDLK_d,
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
	[127 + '2'] = SDLK_KP_2
};

static void (*g_key_func[255])(t_env *e) =
{
	// ['y'] = cube_with_spheres,
	// ['b'] = create_object,
	['n'] = switch_obj_tx,
	['m'] = switch_tsp_tx,
	['f'] = compute_frame,
	['p'] = print_scene,
	['w'] = move_forward,
	['a'] = move_left,
	['s'] = move_backward,
	['d'] = move_right,
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
	[127 + '2'] = move_ojbect_backward
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

	if (e->increment != 1 || key != SDLK_f)
		reset_screen(e);
	if (key != SDLK_f)
	{
		e->sum = 1;
		e->increment = 4;
		e->recursion = 2;
		e->wait = 0.5;
	}
	else
		e->wait = 0;
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
	gettimeofday(&e->last_event, NULL);
	call_function(e, key);
	return (0);
}
