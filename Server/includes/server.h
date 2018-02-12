/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 02:58:15 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/11 17:05:13 by tdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "rt_clu.h"

# ifndef GLOBAL_SERVER
#  define GLOBAL_SERVER

extern int				g_srv_socket;
extern int				g_port;
extern t_vector			*g_buffer;
extern t_env			*g_e;
extern pthread_mutex_t	g_mutex;

# endif

/*
**	QUIT
*/

void		quit(int sig);
void		fatal_quit(char *msg);
void		custom_quit(char *msg);
void		thread_quit(char *msg);

/*
**	OPTIONS
*/

void		get_options(t_env *e, int argc, char **argv);

/*
**	CONNEXION
*/

void		init_master_socket(void);
int			connect_to_client(void);
void		sync_env_obj(t_env *e, int cs);
void		sync_buffer(int cs, t_env *e);

/*
**	DISPLAY
*/

void		display_buffer(t_env *e);
void		reset_screen();
void		draw_screen(t_env *e);

/*
**	INTERFACE
*/

void		loader_wait(t_env *e);
void		start_interface(t_env *e);
void		init_sdl_modules();
void		init_sdl_env(t_env *e);
void		init_sdl_interface(t_env *e);
int			global_loop(t_env *e);
void		create_rect(SDL_Surface *dst, SDL_Rect rect, int color);
void		create_txt_rect(t_env *e);
void		init_rects(t_env *e);
void		init_txt_rects(t_env *e);
void		draw_button_top(t_env *e, int bt_num, int state);
void		draw_button_left(t_env *e, int b_num, int state);
void		draw_input(t_env *e, int i_num, int state);
void		draw_input_top(t_env *e, int bt_num, int state);
int			is_mouse_in_rect(t_env *e, SDL_Rect *rect, int rect_len);
void		is_mouse_in_rect_left(t_env *e);
void		is_mouse_in_rect_right(t_env *e);
void		is_mouse_in_it_right(t_env *e);
void		is_mouse_in_rect_top(t_env *e);
void		is_mouse_in_rect_top_input(t_env *e);
void		is_mouse_in_render(t_env *e);
void		is_mouse_in_credit(t_env *e);
void		draw_all_button_top(t_env *e);
void		draw_all_button_left(t_env *e);
void		draw_selected(t_env *e);
void		create_border(t_env *e, int active);
void		create_rect(SDL_Surface *surf, SDL_Rect rect, int color);
void		create_b_rect(SDL_Surface *surf, SDL_Rect rect, int bg, int bord);
void		write_top_text(t_env *e);
void		write_right_text_top(t_env *e);
void		write_right_text(t_env *e);
void		where_is_mickey(t_env *e);
void		right_text(t_env *e, char *str, SDL_Rect rect,
	SDL_Color color_back);
void		center_text(t_env *e, char *str, SDL_Rect rect,
	SDL_Color color_back);

/*
**	EVENT
*/

void		change_rebond(t_env *e, int mode);
void		change_rot_speed(t_env *e, int mode);
void		change_move_speed(t_env *e, int mode);

void		atom(t_env *e);

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

void		change_color_r(t_env *e, int mode);
void		change_color_g(t_env *e, int mode);
void		change_color_b(t_env *e, int mode);

void		create_sphere(t_env *e);
void		create_plane(t_env *e);
void		create_cylinder(t_env *e);
void		create_cone(t_env *e);
void		create_torus(t_env *e);
void		atom(t_env *e);

void		create_cube(t_env *e);
void		face_d(t_env *e, double size);
void		face_e(t_env *e, double size);
void		face_f(t_env *e, double size);
void		scale_ori(t_env *e, t_obj *obj);

void		cube_with_spheres(t_env *e);

void		switch_damier(t_env *e);
void		dam_one_color_r(t_env *e, int mode);
void		dam_one_color_g(t_env *e, int mode);
void		dam_one_color_b(t_env *e, int mode);
void		dam_two_color_r(t_env *e, int mode);
void		dam_two_color_g(t_env *e, int mode);
void		dam_two_color_b(t_env *e, int mode);

void		delete_object(t_env *e);

void		dna(t_env *e);
void		sphere_mid(t_env *e, int row);
void		sphere_a(t_env *e, int row, double atcg);
void		sphere_b(t_env *e, int row, double atcg);
void		cyl_a(t_env *e, int row);

void		switch_filter(t_env *e);

void		change_fuzz(t_env *e, int mode);

int			keyboard(int key, t_env *e);

void		light_object(t_env *e);
void		change_light(t_env *e, int mode);

void		decrease_limit(t_env *e);
void		increase_limit(t_env *e);

void		damier_marble_r(t_env *e, int mode);
void		damier_marble_g(t_env *e, int mode);
void		damier_marble_b(t_env *e, int mode);

void		marble_color_r(t_env *e, int mode);
void		marble_color_g(t_env *e, int mode);
void		marble_color_b(t_env *e, int mode);

void		marble_object(t_env *e);

void		set_live_edition_mode(t_env *e);
void		set_render_edition_mode(t_env *e);
void		switch_render_mode(t_env *e);

void		move_ojbect_up(t_env *e);
void		move_ojbect_down(t_env *e);
void		move_ojbect_left(t_env *e);
void		move_ojbect_right(t_env *e);
void		move_ojbect_forward(t_env *e);
void		move_ojbect_backward(t_env *e);

void		print_scene(t_env *e);
void		print_light(t_obj *obj);
void		print_damier(t_obj *obj);
void		print_radius_angle(t_obj *obj);
void		print_basics_obj(t_obj *obj, t_vector o, t_vector d);
void		print_marble(t_obj *obj);

void		save_scene(t_env *e);

void		ft_save_filter(FILE *file);
void		ft_save_skybox(FILE *file);
void		ft_save_transparent(t_obj *obj, FILE *file);
void		ft_save_texture(t_obj *obj, FILE *file);
void		ft_save_light(t_obj *obj, FILE *file);

void		ft_save_damier(t_obj *obj, FILE *file);
void		ft_save_marble(t_obj *obj, FILE *file);
void		ft_save_fuzz(t_obj *obj, FILE *file);
void		ft_save_refraction(t_obj *obj, FILE *file);
void		ft_save_reflection(t_obj *obj, FILE *file);

void		ft_save_square(t_obj *obj, FILE *file);
void		ft_save_triangle(t_obj *obj, FILE *file);
void		ft_save_cone(t_obj *obj, FILE *file);
void		ft_save_cylinder(t_obj *obj, FILE *file);
void		ft_save_torus(t_obj *obj, FILE *file);

void		ft_save_plane(t_obj *obj, FILE *file);
void		ft_save_sphere(t_obj *obj, FILE *file);
void		ft_save_camera(t_obj *cam, FILE *file);
char		*new_name(void);
void		(*g_print_obj[255])(t_obj *obj, FILE *file);

void		change_radius_angle(t_env *e, int mode);
void		change_radius(t_env *e, int mode);
void		change_angle(t_env *e, int mode);

void		change_refraction(t_env *e, int sense);
void		change_reflection(t_env *e, int sense);

void		set_helper(t_env *e);
void		exit_helper(t_env *e);

void		rotate_object_x(t_env *e, int mode);
void		rotate_object_y(t_env *e, int mode);
void		rotate_object_z(t_env *e, int mode);

void		select_obj(int x, int y, t_env *e);

void		switch_obj_tx(t_env *e);
void		switch_skybox(t_env *e);
void		switch_tsp_tx(t_env *e);

void		change_type(t_env *e, int mode);

void		change_inputs(t_env *e);

/*
**	MISCELANEOUS
*/

double		randb(void);

/*
**	INIT
*/

void		init_render_env(t_env *e);
void		init_globals(t_env *e);

/*
**	MARBLE
*/

void		marble(t_env *e, t_vector *color, t_obj *closest_obj);
double		noise(t_env *e, t_vector cross);
double		turb(t_env *e, t_vector cross);
void		perlin_generate(t_env *e);
void		perlin_generate_perm(int *p);

/*
**	FILTER
*/

void		sepia(t_vector *pixel);
void		black_and_white(t_vector *pixel);
void		negative(t_vector *pixel);

/*
**	CALCULUS
*/

t_ray		cam_ray(t_env *e, double i, double j, double ratio);

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
void		parse_object(t_obj *obj, char *line);
void		parse_camera(t_env *e, char *line);
t_vector	parse_origin(char *content);
double		parse_radius(char *content);
double		parse_radius(char *content);
t_vector	parse_color(char *content);
double		parse_angle(char *content);
int			parse_type(char *content);
t_vector	parse_direction(char *content);
double		parse_double(char *content);
void		parse_skybox(t_env *e, char *content);
int			parse_texture(char *content);
int			parse_tsp(char *content);
int			parse_filter(char *content);

#endif
