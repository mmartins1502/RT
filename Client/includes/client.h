/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 02:50:14 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/01 02:50:14 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "rt_clu.h"

# ifndef GLOBAL_CLI
#  define GLOBAL_CLI

extern int		g_cli_socket;
extern char		*g_address;
extern int		g_port;
extern int		*g_buffer;
extern int		**g_frame_array;
extern t_vector	**g_color_array;
extern t_mem	g_mem;
extern t_window	g_win;
extern t_env	*g_e;

# endif

/*
**	QUIT
*/

void		custom_quit(char *msg);
void		fatal_quit(char *msg);

/*
**	INIT
*/

void		init_globals(void);
void		init_skyboxes_tx_sources(void);
void		init_color_tx_sources(void);
void		init_transparency_tx_sources(void);

/*
**	CONNEXION
*/

void		connect_to_server(void);
void		sync_env(t_env *e);
void		sync_objects(t_env *e, t_obj *obj);
void		sync_buffer(t_env *e);
void		release_obj(t_env *e);

/*
**	OBJECT ADD
*/

t_obj		*new_obj(void);
void		obj_push_back(t_obj **list, t_obj *cur);

/*
**	MISCELANEOUS
*/

double		randb(void);
t_vector	random_unit_sphere(void);
t_vector	adjust_color(t_vector c);
t_vector	diffuse_sky(t_env *e, double t);
void		damier(t_obj *closest_obj);

/*
**	DISPLAY
*/

void		reset_screen(t_env *e);
void		draw_screen(t_env *e);
void		*compute_block(void *data);
t_ray		cam_ray(t_env *e, double i, double j, double ratio);
void		init_copy(t_env *e, t_env *copy, int i);
void		release_copy(t_env **copy);

/*
**	CALCULUS
*/

t_vector	compute_objects(t_env *e, t_ray ray, double t);
t_vector	reflection(t_env *e, t_ray ray, t_obj *closest_obj);
t_vector	refraction(t_env *e, t_ray ray, t_obj *closest_obj);
t_vector	diffuse(t_env *e, t_ray ray, t_obj *closest_obj);
t_vector	live_preview(t_obj *closest_obj);

/*
**	MAPPING
*/

void		color_mapping(t_obj *closest_obj);

/*
**	MARBLE
*/

void		marble(t_env *e, t_obj *closest_obj);
double		noise(t_env *e, t_vector cross);
void		perlin_generate(t_env *e);
void		perlin_generate_perm(int *p);

#endif
