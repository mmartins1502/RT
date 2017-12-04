/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:16:28 by itonoli-          #+#    #+#             */
/*   Updated: 2017/12/04 16:24:50 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H


# include <math.h>
# include <errno.h>
# include <time.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>
# include <stdio.h>
# include <sys/time.h>
# include <sys/stat.h>


# include "../libraries/libft/includes/libft.h"

# include "../frameworks/SDL2.framework/Headers/SDL.h"
# include "../frameworks/SDL2_ttf.framework/Headers/SDL_ttf.h"
# include "../frameworks/SDL2_image.framework/Headers/SDL_image.h"

# include "rt_structs.h"
# include "libvector.h"

# define WIN_W				1303
# define WIN_H				733
# define MID_W      		640
# define MID_H      		360

# define F_WIDTH			(double)1024
# define F_HEIGHT			(double)648
# define FOV				60

# define OBJ_UNDEF			0
# define OBJ_SPHERE			1
# define OBJ_PLANE			2
# define OBJ_CYL			3
# define OBJ_CONE			4

# define MOVE_SPEED			(double)10.0
# define ROT_SPEED			(double)0.1
# define PITCH				e->camera.dir.y
# define YAW				e->camera.dir.x

# define ATENUATION			2

# define _R					(0x00ff0000)
# define _G					(0x0000ff00)
# define _B					(0x000000ff)
# define _A					(0xff000000)

/*
***********
**	GUI
***********
*/

int		global_loop(t_env *e);
void	create_rect(SDL_Surface *dst, SDL_Rect rect, int color);
void	init_rects(t_env *e);
void	is_mouse_in_rect_left(t_env *e);
void	is_mouse_in_rect_right(t_env *e);
void	is_mouse_in_rect_top(t_env *e);
void	is_mouse_in_render(t_env *e);

/*
*************
**	RENDER
*************
*/

void		init_render(t_env *e, int argc, char **argv);

/*
**	MISCELANEOUS
*/

double		randb(void);
t_vector	random_unit_sphere(void);
t_vector	adjust_color(t_vector c);
t_vector	diffuse_sky(t_env *e, double t);
void		damier(t_obj *closest_obj);

/*
**	INIT
*/

void		init_render_env(t_env *e);
void		init_skyboxes_tx_sources(t_env *e);
void		init_color_tx_sources(t_env *e);
void		init_transparency_tx_sources(t_env *e);

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
**	EVENT
*/

int			keyboard(int key, t_env *e);
void		select_obj(int x, int y, t_env *e);
void		print_scene(t_env *e);
void		move_up(t_env *e);
void		move_down(t_env *e);
void		move_left(t_env *e);
void		move_right(t_env *e);
void		move_forward(t_env *e);
void		move_backward(t_env *e);
void		pitch_up(t_env *e);
void		pitch_down(t_env *e);
void		yaw_left(t_env *e);
void		yaw_right(t_env *e);
void		move_ojbect_up(t_env *e);
void		move_ojbect_down(t_env *e);
void		move_ojbect_left(t_env *e);
void		move_ojbect_right(t_env *e);
void		move_ojbect_forward(t_env *e);
void		move_ojbect_backward(t_env *e);
void		switch_skybox(t_env *e);
void		switch_obj_tx(t_env *e);
void		switch_tsp_tx(t_env *e);
void		cube_with_spheres(t_env *e);
void    	create_sphere(t_env *e);
// void		cube_with_spheres(t_env *e, int x, int y);

/*
**	CALCULUS
*/

t_vector	compute_objects(t_env *e, t_ray ray);
t_vector	reflection(t_env *e, t_ray ray, t_obj *closest_obj);
t_vector	refraction(t_env *e, t_ray ray, t_obj *closest_obj);
t_vector	diffuse(t_env *e, t_ray ray, t_obj *closest_obj);

/*
**	PRIMITIVES
*/

double		get_distance(t_env *e, t_obj *obj, t_ray ray);
double		hit_sphere(t_env *e, t_obj *obj, t_ray ray);
double		hit_plane(t_env *e, t_obj *obj, t_ray ray);
double		hit_cyl(t_env *e, t_obj *obj, t_ray ray);
double		hit_cone(t_env *e, t_obj *obj, t_ray ray);

/*
**	MARBLE
*/

void		marble(t_env *e, t_vector *color, t_obj *closest_obj);
double		noise(t_env *e, t_vector cross);
double		turb(t_env *e, t_vector cross);
void		perlin_generate(t_env *e);
void		perlin_generate_perm(int *);

/*
**	MAPPING
*/

void		color_mapping(t_obj *closest_obj);

/*
**	PARSER
*/

void		random_spheres(t_env *e);
t_obj		*new_obj(void);
void		obj_push_back(t_obj **list, t_obj *cur);
void		parse_error(char *msg, char *tag, char *content);
void		parser(t_env *e);
void		get_input(t_env *e);
void		remove_ws(char **str);
char		*get_xml_tag(char *line, char **ptr, char **tag);
char		*get_xml_opening_tag(char *line);
char		*get_xml_closing_tag(char *line);
char		*closing_tag(char *opening);
void		parse_object(t_env *e, t_obj *obj, char *object_tag, char *line);
void		parse_camera(t_env *e, char *object_tag, char *line);
t_vector	parse_origin(char *content);
double		parse_radius(char *content);
t_vector	parse_color(char *content);
double		parse_angle(char *content);
int			parse_type(char *content);
t_vector	parse_direction(char *content);
double		parse_double(char *content);
void   		parse_skybox(t_env *e, char *content);

#endif
