#include "rt.h"

void	create_rect(SDL_Surface *dst, SDL_Rect rect, int color)
{
	short	x;
	short	y;

	y = rect.y - 1;
	while (++y < rect.h)
	{
		x = (rect.x - 1);
		while (++x < rect.w)
		{
			*((unsigned *)(dst->pixels + y * dst->pitch + x *
			dst->format->BytesPerPixel)) = color;
		}
	}
	printf("created rect\n");
}

void		draw_button_top(t_env *e, int bt_num, int state)
{
	SDL_Rect rect;

	rect = e->bt_rect[bt_num];
	(state == 1) ? rect.y += 60 : 1;
	(state == 2) ? rect.y += 120 : 1;
	SDL_BlitSurface(e->s_ui, &rect, e->s_background, &e->bt_rect[bt_num]);
}

void		draw_button_left(t_env *e, int b_num, int state)
{
	SDL_Rect rect;

	rect = e->b_rect[b_num];
	(state == 1) ? rect.x += 82 : 1;
	(state == 2) ? rect.x += 162 : 1;
	SDL_BlitSurface(e->s_ui, &rect, e->s_background, &e->b_rect[b_num]);
}

void 		draw_input(t_env *e, int i_num, int state)
{
	SDL_Rect rect;

	rect = e->i_rect[i_num];
	(state == 1) ? rect.x -= 750 : 1;
	SDL_BlitSurface(e->s_ui, &rect, e->s_background, &e->i_rect[i_num]);
}

void		is_mouse_in_rect_top(t_env *e)
{
	int i;

	i = -1;
	while (++i < 8)
	{
		if (SDL_PointInRect(&e->mouse, &e->bt_rect[i]))
		{
			if (i != e->bt_actif)
			{
				draw_button_top(e, i, 1);
				if (e->event.type == SDL_MOUSEBUTTONDOWN)
				{
					printf("Imput clik %d\n", i);
					draw_button_top(e, i, 2);
					e->bt_actif = i;
					if (e->bt_actif == 0 || e->bt_actif == 1)
					{
						e->bt_actif == 0 ? light_object(e) : marble_object(e);
						e->bt_actif = -1;
					}
					if (e->bt_actif == 2 || e->bt_actif == 3)
					{
						e->bt_actif == 2 ? switch_obj_tx(e) : print_scene(e);
						e->bt_actif = -1;
					}
					if (e->bt_actif == 4 || e->bt_actif == 5)
					{
						e->bt_actif == 4 ? switch_skybox(e) : 0;
						e->bt_actif = -1;
					}
				}
			}
			else
			{
				if (e->event.type == SDL_MOUSEBUTTONDOWN)
				{
					draw_button_top(e, i, 1);
					e->bt_actif = -1;
				}
			}
		}
		else if (i != e->bt_actif)
			draw_button_top(e, i, 0);
	}
}

void		is_mouse_in_rect_right(t_env *e)
{
	int i;

	i = -1;
	while (++i < 9)
	{
		if (SDL_PointInRect(&e->mouse, &e->i_rect[i]))
		{
			if (i != e->i_actif)
			{
				draw_input(e, i, 0);
				if (e->event.type == SDL_MOUSEBUTTONDOWN)
				{
					printf("Imput clik %d\n", i);
					draw_input(e, i, 1);
					e->i_actif = i;
				}
			}
			else
			{
				if (e->event.type == SDL_MOUSEBUTTONDOWN)
				{
					draw_input(e, i, 0);
					e->i_actif = -1;
				}
			}

		}
		else if (i != e->i_actif)
			draw_input(e, i, 0);
	}
}

void		is_mouse_in_rect_left(t_env *e)
{
	int i;

	i = -1;
	while (++i < 8)
	{
		if (SDL_PointInRect(&e->mouse, &e->b_rect[i]))
		{
			if (i != e->b_actif)
			{
				draw_button_left(e, i, 1);
				if (e->event.type == SDL_MOUSEBUTTONDOWN)
				{
					printf("Bouton clik %d\n", i);
					draw_button_left(e, i, 2);
					e->b_actif = i;
				}
			}
			else
			{
				if (e->event.type == SDL_MOUSEBUTTONDOWN)
				{
					draw_button_left(e, i, 1);
					e->b_actif = -1;
				}
			}

		}
		else if (i != e->b_actif)
			draw_button_left(e, i, 0);

	}
	if (SDL_PointInRect(&e->mouse, &e->b_rect[8]) && e->event.type == SDL_MOUSEBUTTONDOWN)
	{
		printf("HELP!!\n");
		e->help_actif = 1;
		SDL_BlitSurface(e->s_ui, &e->help_rect, e->s_background, &(SDL_Rect){405, 190, 350, 400});
	}
}

void	is_mouse_in_render(t_env *e)
{
	int i;
	int j;

	i = e->mouse.x;
	j = e->mouse.y;
	if (i > 82 && i < 82 + F_WIDTH)
		if (j > 72 && j < 72 + F_WIDTH)
		{
			// create_rect(e->s_ui, (SDL_Rect){80, 70, F_WIDTH + 4, 2}, 0xFFFF0000);
			// create_rect(e->s_ui, (SDL_Rect){80, 70, 40, F_HEIGHT + 4}, 0xFFFF00FF);
			//create_rect(e->s_background, (SDL_Rect){0, 0, F_WIDTH, F_HEIGHT}, 0xFF2b2b2b);
			//create_rect(e->s_background, (SDL_Rect){0, 0, F_WIDTH, F_HEIGHT}, 0xFF2b2b2b);
			if (e->b_actif == 0 || e->b_actif == 1)
			{
				e->b_actif == 0 ? create_sphere(e) : create_cylinder(e);
				e->b_actif = -1;
			}
			if (e->b_actif == 2 || e->b_actif == 3)
			{
				e->b_actif == 2 ? create_plane(e) : 0;//create_torus(e);
				e->b_actif = -1;
			}
			if (e->b_actif == 4 || e->b_actif == 5)
			{
				e->b_actif == 4 ? create_cone(e) : 0;//create_solar(e);
				e->b_actif = -1;
			}
			if (e->b_actif == 6 || e->b_actif == 7)
			{
				e->b_actif == 6 ? 0 : cube_with_spheres(e); //ADN
				e->b_actif = -1;
			}
			else
				select_obj(i - 82, j - 72, e);
		}
}

void init_bt_rect(t_env *e)
{
	int i;

	i = -1;
	while (++i < 8)
	{
			e->bt_rect[i].x = 588 + (67 * i);
			e->bt_rect[i].y = 16;
			e->bt_rect[i].w = 44;
			e->bt_rect[i].h = 42;

	}
	e->bt_rect[i].x = 1135;
	e->bt_rect[i].y = 16;
	e->bt_rect[i].w = 142;
	e->bt_rect[i].h = 42;
}

void init_b_rect(t_env *e)
{
	// The buttons w = 50px et h = 47px
	int i;

	i = -1;
	while (++i < 8)
	{
			e->b_rect[i].x = 15;
			e->b_rect[i].w = 50;
			e->b_rect[i].h = 47;
			if (i < 5)
				e->b_rect[i].y = 116 + (59 * i);
			else
				e->b_rect[i].y = 128 + (59 * i);
	}
	e->b_rect[i].x = 23;
	e->b_rect[i].y = 670;
	e->b_rect[i].w = 35;
	e->b_rect[i].h = 35;
}

void init_i_rect(t_env *e)
{
	// Input w = 143 h = 25px
	int i;

	i = -1;
	while (++i < 10)
	{
		e->i_rect[i].x = 1134;
		e->i_rect[i].w = 143;
		if (i < 6)
		{
			e->i_rect[i].y = 120 + (37 * i);
			e->i_rect[i].h = 25;
		}
		else
		{
			e->i_rect[i].y = 349 + (66 * (i - 6));
			e->i_rect[i].h = 46;
		}
	}
}


void init_rects(t_env *e)
{
	init_b_rect(e);
	init_bt_rect(e);
	init_i_rect(e);
	e->help_rect = (SDL_Rect){707,294, 350, 400};
}
