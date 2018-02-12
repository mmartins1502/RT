/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_clu.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 02:47:25 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/11 17:08:18 by tdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_CLU_H
# define RT_CLU_H

# include <math.h>
# include <errno.h>
# include <time.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>
# include <stdio.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <arpa/inet.h>
# include <netdb.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/types.h>

# include "frameworks/SDL2.framework/Headers/SDL.h"
# include "frameworks/SDL2_ttf.framework/Headers/SDL_ttf.h"
# include "frameworks/SDL2_image.framework/Headers/SDL_image.h"

# include "libft.h"
# include "rt_clu_structs.h"

# define WIN_W				1303
# define WIN_H				733
# define MID_W      		640
# define MID_H      		360

# define MOUSE				1
# define CLICK 				2

# define INCREASE			1
# define DECREASE			2
# define INCREASE_MAX       3
# define DECREASE_MAX       4

# define F_WIDTH			(double)1024
# define F_HEIGHT			(double)648
# define FOV				60

# define OBJ_UNDEF			0
# define OBJ_SPHERE			1
# define OBJ_PLANE			2
# define OBJ_CYL			3
# define OBJ_CONE			4
# define OBJ_TRI			5
# define OBJ_SQUARE		    6
# define OBJ_TORUS			7

# define MOVE_SPEED			e->move_speed
# define ROT_SPEED			e->rot_speed
# define PITCH				e->camera.dir.y
# define YAW				e->camera.dir.x

# define _A					(0xff000000)
# define _R					(0x00ff0000)
# define _G					(0x0000ff00)
# define _B					(0x000000ff)

# define MAGIC				1337

# define TOTAL_SKYBOX		12
# define TOTAL_TX			28
# define TOTAL_TSP			2

# define COLOR_BG           (SDL_Color){43, 43, 43, 255}
# define COLOR_BT           (SDL_Color){34, 34, 34, 255}
# define COLOR_LO           (SDL_Color){36, 36, 36, 255}
# define COLOR_TXT          (SDL_Color){60, 60, 60, 255}
# define COLOR_W            (SDL_Color){255, 255, 255, 255}
# define COLOR_Y            (SDL_Color){239, 236, 0, 255}

# define EQN_EPS			1e-9
# define ISZERO(x)			((x) > -EQN_EPS && (x) < EQN_EPS)

# define CBRT_R(x)			((x) < 0.0 ? -pow((double)-(x), 1.0/3.0) : 0.0))
# define CBRT(x)			((x) > 0.0 ? pow((double)(x), 1.0/3.0) : CBRT_R(x)

# define O_MODE				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH

# define POST(...)			ft_post_realloc_str(__VA_ARGS__)
# define PRE(...)			ft_pre_realloc_str(__VA_ARGS__)

# ifndef GLOBAL_CLU
#  define GLOBAL_CLU

extern const	t_texture_sources g_color_sources[];
extern const	t_texture_sources g_skybox_sources[];
extern const	t_texture_sources g_tsp_sources[];

# endif

/*
**	PRIMITIVES
*/

double		dist_priority(t_env *e, t_obj *obj, t_ray ray, double t);
void		size_interpretor(t_obj *obj, t_vector *v1, t_vector *v2);
double		get_distance(t_env *e, t_obj *obj, t_ray ray);
double		hit_sphere(t_env *e, t_obj *obj, t_ray ray);
double		hit_plane(t_env *e, t_obj *obj, t_ray ray);
double		hit_cyl(t_env *e, t_obj *obj, t_ray ray);
double		hit_cone(t_env *e, t_obj *obj, t_ray ray);
double		hit_tri(t_env *e, t_obj *obj, t_ray ray);
double		hit_torus(t_env *e, t_obj *obj, t_ray ray);
double		hit_square(t_env *e, t_obj *obj, t_ray ray);
int			solve_quartic(double c[5], double s[4]);
int			solve_cubic(double c[4], double s[3]);
int			solve_quadric(double c[3], double s[2]);

/*
**	LIBVECTOR
*/

t_vector	vector_add(t_vector a, t_vector b);
t_vector	vector_sub(t_vector a, t_vector b);
t_vector	vector_cross(t_vector a, t_vector b);
t_vector	vector_mul(t_vector a, t_vector b);
t_vector	vector_negative(t_vector a);
double		vector_dot(t_vector a, t_vector b);
double		vector_cos_angle(t_vector a, t_vector b);
double		vector_angle(t_vector a, t_vector b);
double		vector_magnitude(t_vector v);
t_vector	vector_scale(t_vector a, double scale);
t_vector	vector_factor(t_vector a, double factor, t_vector b);
t_vector	vector_new(double x, double y, double z);
t_vector	vector_normalize(t_vector a);
t_vector	vector_normal(t_env *e, t_obj *closest_obj, t_ray ray);
t_vector	normal_sphere(t_obj *closest_obj);
t_vector	normal_cone(t_obj *closest_obj);
t_vector	normal_plane(t_obj *closest_obj, t_ray ray);
t_vector	normal_cyl(t_obj *closest_obj);
t_vector	normal_torus(t_obj *closest_obj);
t_vector	normal_triangle(t_obj *obj, t_vector v1, t_vector v2);

#endif
