/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 09:42:33 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/28 10:13:26 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "../libft/includes/libft.h"
# include "../SDL2-2.0.5/include/SDL.h"
# include <stdio.h>
# include <math.h>
# include <limits.h>

# define F_WIDTH	(double)1000
# define F_HEIGHT	(double)1000
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define KEY_UP		126
# define KEY_DOWN	125
# define KEY_PLUS	69
# define KEY_MINUS	78
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_ESC	53
# define OBJ_UNDEF	0
# define OBJ_SPHERE	1
# define OBJ_PLANE	2
# define OBJ_CYL	3
# define OBJ_CONE	4
# define KEY e->event.key.keysym.sym

typedef	struct	s_xml
{
	int				tag;
	char			*value;
}				t_xml;

typedef struct	s_vector
{
	double			x;
	double			y;
	double			z;
}				t_vector;

typedef struct	s_color
{
	int				r;
	int				g;
	int				b;
}				t_color;

typedef struct	s_ray
{
	t_vector		ori;
	t_vector		dir;
}				t_ray;

typedef struct	s_cone_coef
{
	double			dot_a;
	t_vector		sca_a;
	t_vector		sub_a;
	double			dot_b;
	t_vector		sca_b;
	t_vector		sub_b;
	double			csq;
	double			ssq;
}				t_cone_coef;

typedef struct	s_light
{
	t_vector		ori;
	t_color			color;
	struct s_light	*next;
}				t_light;

typedef struct	s_obj
{
	int				type;
	t_vector		ori;
	t_vector		dir;
	double			radius;
	double			hauteur;
	double			a;
	double			b;
	double			c;
	double			d;
	double			t;
	double			t1;
	double			t2;
	t_color			color;
	t_vector		cross;
	double			cross_distance;
	struct s_obj	*next;
}				t_obj;

typedef struct	s_env
{
	char			*scene_file;
	char			*input;
	SDL_Renderer	*renderer;
	SDL_Window		*win;
	SDL_Event		event;
	int 			run;
	t_obj			camera;
	t_light			*lights;
	t_obj			*objects;
	t_color			color;
}				t_env;

t_obj			*new_obj(void);
t_light			*new_light(void);
void			obj_push_back(t_obj **list, t_obj *cur);
void			light_push_back(t_light **list, t_light *cur);

void			parse_error(char *msg);
void			parser(t_env *e);
void			get_input(t_env *e);
void			remove_ws(char **str);
char			*get_xml_tag(char *line, char **ptr, char **tag);
char			*get_xml_opening_tag(char *line);
char			*get_xml_closing_tag(char *line);
char			*closing_tag(char *opening);
void			parse_object(t_obj *obj, char *line);
void			parse_light(t_light *light, char *line);
void			parse_camera(t_env *e, char *line);
t_vector		parse_origin(char *content);
double			parse_radius(char *content);
t_color			parse_color(char *content);
double			parse_angle(char *content);
int				parse_type(char *content);
t_vector		parse_direction(char *content);

void			draw_screen(t_env *e);

void			get_distance(t_obj *obj, t_ray ray);
void			compute_objects(t_env *e, t_ray ray);
void			compute_closest_obj(t_env *e, t_obj *closest_obj);

t_vector		vector_new(double x, double y, double z);
t_vector		vector_negative(t_vector a);
t_vector		vector_add(t_vector a, t_vector b);
t_vector		vector_sub(t_vector a, t_vector b);
double			vector_cos_angle(t_vector a, t_vector b);
t_vector		vector_normal(t_obj *closest_obj, t_ray ray);
t_vector		vector_scale(t_vector a, double scale);
t_vector		vector_factor(t_vector a, double factor, t_vector b);
t_vector		vector_normalize(t_vector a);
double			vector_magnitude(t_vector v);
double			vector_dot(t_vector a, t_vector b);

void			quit(char *msg);
void			init_sdl(t_env *e);
void			init_env(t_env *e, char *scene_file);

void			sphere_distance(t_obj *obj, t_ray ray);
t_vector		sphere_normal(t_obj *closest_obj);

void			plane_distance(t_obj *obj, t_ray ray);
t_vector		plane_normal(t_obj *closest_obj, t_ray ray);

void			cyl_distance(t_obj *obj, t_ray ray);
t_vector		cyl_normal(t_obj *closest_obj);

void			cone_distance(t_obj *obj, t_ray ray);
t_vector		cone_normal(t_obj *closest_obj);

void			diffuse_color(t_env *e, t_color o, t_color l, double coef);
void			specular_color(t_env *e, t_color light_c, double coef);
void			plane_color(t_obj *closest_obj);
void			put_color(t_env *e, int i, int j);

#endif
