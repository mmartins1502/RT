/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 09:40:55 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/28 09:54:40 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	move_cam(SDL_Keycode key, t_env *e)
{
	if (key == SDLK_w && e->event.type == SDL_KEYDOWN)
		e->camera.ori = vector_factor(e->camera.ori, 50, e->camera.dir);
	draw_screen(e);
}

void	wait_event(t_env *e)
{
	while (e->run)
	{
		if (SDL_WaitEvent(&e->event))
		{
			if (e->event.window.event == SDL_WINDOWEVENT_CLOSE || KEY == SDLK_ESCAPE)
				e->run = 0;
			else if ((KEY == SDLK_w || KEY == SDLK_s || KEY == SDLK_a || KEY == SDLK_d) && e->event.type == SDL_KEYDOWN)
			{
				move_cam(KEY, e);
			}
			// else if ((KEY == SDLK_UP || KEY == SDLK_DOWN || KEY == SDLK_RIGHT || KEY == SDLK_LEFT) && e->event.type == SDL_KEYDOWN)
			// {

			// }
		}
	}
}

int		keyboard(int key)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

void	init_sdl(t_env *e)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		SDL_Quit();
		quit("Unable to init SDL");
	}
	e->win = SDL_CreateWindow("Ray Tracer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, F_WIDTH, F_HEIGHT, 0);
	if (e->win == NULL)
	{
		SDL_Quit();
		quit("Unable to create window");
	}
	e->renderer = SDL_CreateRenderer(e->win, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(e->renderer, 0, 0, 0, 255);
	SDL_RenderClear(e->renderer);
	e->run = 1;
	draw_screen(e);
	wait_event(e);
	// int	bits;
	// int	size;
	// int	end;
	// int i;

	// if (!(e->mlx = mlx_init()))
	// 	quit("Unable to start mlx server.");
	// if (!(e->win = mlx_new_window(e->mlx, F_WIDTH, F_HEIGHT, "RTv1")))
	// 	quit("Unable to start mlx window.");
	// if (!(e->frame_addr = mlx_new_image(e->mlx, F_WIDTH, F_HEIGHT)))
	// 	quit("Unable to get mlx new image.");
	// e->frame = (int *)mlx_get_data_addr(e->frame_addr, &bits, &size, &end);
	// e->frame_array = (int **)ft_memalloc(sizeof(int *) * F_HEIGHT);
	// i = -1;
	// while (++i < (int)F_HEIGHT)
	// 	e->frame_array[i] = &e->frame[i * (int)F_WIDTH];
	// mlx_hook(e->win, 2, (1L << 0), keyboard, NULL);
	// mlx_hook(e->win, 17, (1L << 0), (void *)quit, NULL);
}
