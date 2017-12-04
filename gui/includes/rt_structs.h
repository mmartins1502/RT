#ifndef RT_STRUCTS_H
# define RT_STRUCTS_H

typedef struct 	s_texture_sources
{
	char		*name;
	char		*file_address;
}				t_texture_sources;

typedef	struct	s_xml
{
	int			tag;
	char		*value;
}				t_xml;

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct	s_ray
{
	t_vector	ori;
	t_vector	dir;
}				t_ray;

typedef struct	s_cone_coef
{
	double		dot_a;
	t_vector	sca_a;
	t_vector	sub_a;
	double		dot_b;
	t_vector	sca_b;
	t_vector	sub_b;
	double		csq;
	double		ssq;
}				t_cone_coef;

typedef struct	s_obj
{
	int				type;
	t_vector		ori;
	t_vector		dir;
	double			radius;
	double			reflection;
	double			refraction;
	double			marblesize;
	double			marblecoef;
	t_vector		marblecolor;
	int				damier;
	t_vector		damier1;
	t_vector		damier2;
	double			a;
	double			b;
	double			c;
	double			d;
	double			e;
	double			t;
	double			u;
	double			v;
	double			t1;
	double			t2;
	t_vector		color;
	t_vector		cross;
	double			cross_distance;
	t_vector		normal;
	double			fuzz;
	int				emit;
	t_vector		light;

	char			*tx_selected;
	SDL_Surface		*current_texture;
	int				texture_index;

	char			*tsp_selected;
	SDL_Surface		*current_tsp;
	int				tsp_index;

	struct s_obj	*next;
}				t_obj;

typedef struct	s_env
{
	SDL_Event     	event;
	SDL_Cursor		*cursor;
	SDL_Window		*win;
	SDL_Surface		*s_background;
	SDL_Surface		*w_icon;
	SDL_Surface		*s_tmp;
	SDL_Surface		*s_t2;
	SDL_Surface		*s_ui;
	SDL_Surface		*s_loader;
	SDL_Surface		*s_versus;
	SDL_Surface		*s_title;
	SDL_Surface		*s_raytracer;
	TTF_Font		**font;
	SDL_Rect		b_rect[9];
	SDL_Rect		bt_rect[9];
	SDL_Rect		i_rect[10];
	SDL_Rect		help_rect;
	SDL_Point		mouse;
	void	        *img;
	int		        *img_data;
	void	        *gui;
	int		        *gui_data;
	int		        win_w;
	int		        win_h;
	int		        x;
	int		        y;
	char			loader;
	char			render;
	char			b_actif;
	char			i_actif;
	char			help_actif;
	char			bt_actif;
	char			run;

	//LIVE PREVIEW
	struct timeval	last_event;
	double			wait;
	int				increment;

	//MULTITHREADING
	int				threads;
	int				i;
	int				sum;

	//PARSER
	char			*scene_file;
	char			*input;

	//MAIN STORAGE DATA
	int				**frame_array;
	t_vector		**color_array;
	t_obj			camera;
	t_obj			*objects;

	//CALCULUS
	t_obj			*avoid;
	double			t_min;
	double			t_max;
	double			ni_nt;
	int				depth;
	int				recursion;

	//LIVE EDITION
	t_obj			*selected;

	//PERLIN NOISE
	t_vector		ranvec[256];
	double			randouble[256];
	int				perm_x[256];
	int				perm_y[256];
	int				perm_z[256];

	//SKYDIFFUSE
	double			vpos;

	//SKYBOX TEXTURES
	int				skybox;
	char			*skybox_selected;
	SDL_Surface		*s_skybox[12];
	SDL_Surface		*current_skybox;
	int				skybox_index;
	int				skybox_total;

	//OBJECTS TEXTURES
	SDL_Surface		*s_obj_tx[12];
	int				obj_tx_total;

	//TRANSPARENCY TEXTURES
	SDL_Surface		*s_tsp_tx[12];
	int				tsp_tx_total;
}				t_env;

typedef struct	s_key_value
{

}				t_key;

#endif
