/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:23:36 by itonoli-          #+#    #+#             */
/*   Updated: 2017/12/04 13:21:08 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	handle_events(t_env *e)
{
	if (e->event.window.event == SDL_WINDOWEVENT_CLOSE || (e->event.type == SDL_KEYDOWN && e->event.key.keysym.sym == SDLK_ESCAPE))
	{
		//Stop, free and quit
		e->run = 0;
	}
	if (e->event.type == SDL_KEYDOWN && e->event.key.keysym.sym != SDLK_ESCAPE)
	{
		if (e->loader == 1)
		{
			//Place UI on main window
			SDL_BlitSurface(e->s_ui, 		 &(SDL_Rect){0, 0, e->win_w, e->win_h},
							e->s_background, &(SDL_Rect){0, 0, e->win_w, e->win_h});
			//Draw shit on render space
			create_rect(e->s_raytracer, (SDL_Rect){0, 0, F_WIDTH, F_HEIGHT}, 0xFF2b2b2b);
			SDL_BlitSurface(e->s_raytracer,  &(SDL_Rect){0, 0, F_WIDTH, F_HEIGHT},
							e->s_background, &(SDL_Rect){82, 72, F_WIDTH, F_HEIGHT});
			//Init interface buttons
			init_rects(e);

			//Loader step is done, go render shit nigga
			e->loader = 0;
			e->render = 1;
		}
		else if (e->render == 1)
		{
			keyboard(e->event.key.keysym.sym, e);
		}
	}
	if ((e->event.type == SDL_MOUSEMOTION || e->event.type == SDL_MOUSEBUTTONDOWN))
	{
		e->mouse.x = e->event.motion.x;
		e->mouse.y = e->event.motion.y;
//		printf("MOUSE x = %d\n", e->mouse.x);
//		printf("MOUSE y = %d\n", e->mouse.y);
		is_mouse_in_rect_right(e);
		is_mouse_in_rect_left(e);
		is_mouse_in_rect_top(e);
		if (e->event.type == SDL_MOUSEBUTTONDOWN)
			is_mouse_in_render(e);
		// if (e->event.type == SDL_MOUSEBUTTONDOWN && e->b_actif > -1)
		// {
		// 	if (e->b_actif == 7)
		// 		cube_with_spheres(e);
		// 		// place_for_object(e);

		// }
		
	}
	// if (e->event.type == 0x300)
	// 	handle_keyboard_down(env);
	// if (e->event.type == 0x301)
	// 	handle_keyboard_up(env);
}

int		free_elements(t_env *e)
{
	SDL_DestroyWindow(e->win);
	SDL_FreeCursor(e->cursor);
	SDL_FreeSurface(e->w_icon);
	SDL_FreeSurface(e->gui);
	free(e->font);
	e->font = NULL;
	TTF_Quit();
	SDL_Quit();
	exit(EXIT_SUCCESS);
	return (0);
}

int		global_loop(t_env *e)
{
	//Display loader
	SDL_BlitSurface(e->s_loader,     &(SDL_Rect){0, 0, e->win_w, e->win_h},
					e->s_background, &(SDL_Rect){0, 0, e->win_w, e->win_h});

	//While loop, two states :
	// - Loader
	// - Render
	while (e->run)
	{
		SDL_UpdateWindowSurface(e->win);
		if (SDL_PollEvent(&e->event))
			handle_events(e);
	}
	return (free_elements(e));
}

void	init_sdl(t_env *e)
{
	//Where do we create window
	//0 for not scalable and no options
	if (!(e->win = SDL_CreateWindow("RayTracer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, e->win_w, e->win_h, 0)))
		exit(EXIT_FAILURE);

	//Load and Set App icon
	if (!(e->w_icon = IMG_Load("./assets/images/icon.png")))
	{
		printf("Error Load icon");
		exit(EXIT_FAILURE);
	}
	SDL_SetWindowIcon(e->win, e->w_icon);

	//Load images and fonts
	e->s_loader = IMG_Load("./assets/images/loader.png");
	e->s_ui = IMG_Load("./assets/images/ui.png");
	e->font[0] = TTF_OpenFont("./assets/font/RobotoCondensed-Bold.ttf", 24);
	e->font[1] = TTF_OpenFont("./assets/font/RobotoCondensed-Regular.ttf", 22);
	e->font[2] = TTF_OpenFont("./assets/font/PressStart2P-Regular.ttf", 16);

	//Pointer to main window surface
	e->s_background = SDL_GetWindowSurface(e->win);

	//Create render surface with proper color mode
	e->s_raytracer = SDL_CreateRGBSurface(0, F_WIDTH, F_HEIGHT, 32, _R, _G, _B, _A);
}

void	init_gui_env(t_env *e)
{
	e->win_w = WIN_W; 	//Fenetre totale
	e->win_h = WIN_H;	//*
	e->run = 1;			//var SDL while(1) global loop
	e->b_actif = -1;	//Bouton actifs index
	e->i_actif = -1;	//Indice input actifs broite
	e->bt_actif = -1; 	//Tops
	e->help_actif = -1;	//Help showed
	e->loader = 1;		//loader
	e->render = 0;		//render, not activated
	if (!(e->font = (TTF_Font **)ft_memalloc(sizeof(TTF_Font *) * 3)))
	{
		printf("Memory allocation problem\n");
		exit(EXIT_FAILURE);
	}
}

int			main(int argc, char **argv)
{
	t_env	*e = malloc(sizeof(t_env));
	struct timeval t;

	gettimeofday(&t, NULL);
	srand(t.tv_usec);
	if (TTF_Init() == -1)
	{
		printf("TTF_Init: %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Error SDL Int");
		exit(EXIT_FAILURE);
	}
	init_gui_env(e);
	init_sdl(e);
	init_render(e, argc, argv);
	global_loop(e);
	return (0);
}
