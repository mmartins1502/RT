/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:23:36 by itonoli-          #+#    #+#             */
/*   Updated: 2017/12/10 21:43:33 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void		start_render(t_env *e)
{
	init_rects(e);
	init_txt_rects(e);
	SDL_BlitSurface(e->s_ui, &(SDL_Rect){0, 0, e->win_w, e->win_h},
					e->s_background, &(SDL_Rect){0, 0, e->win_w, e->win_h});
	create_rect(e->s_raytracer,
				(SDL_Rect){0, 0, F_WIDTH, F_HEIGHT}, 0xFF2b2b2b);
	SDL_BlitSurface(e->s_raytracer, &(SDL_Rect){0, 0, F_WIDTH, F_HEIGHT},
					e->s_background, &(SDL_Rect){82, 72, F_WIDTH, F_HEIGHT});
	create_rect(e->s_background,
				(SDL_Rect){1126, 80, 160, 530}, 0xFF2b2b2b);
	write_top_text(e);
	e->loader = 0;
	e->render = 1;
}

void		handle_events(t_env *e)
{
	if (e->event.window.event == SDL_WINDOWEVENT_CLOSE ||
		(e->event.type == SDL_KEYDOWN && e->event.key.keysym.sym ==
	SDLK_ESCAPE))
		e->run = 0;
	if (e->event.type == SDL_KEYDOWN && e->event.key.keysym.sym != SDLK_ESCAPE)
	{
		if (e->loader == 1 && e->nb_cli > 0)
			start_render(e);
		else if (e->render == 1)
		{
			if (e->i_actif != -1 || e->topin_actif != -1)
				change_inputs(e);
			else
				keyboard(e->event.key.keysym.sym, e);
		}
	}
	if (e->render == 1)
	{
		e->mouse.x = e->event.motion.x;
		e->mouse.y = e->event.motion.y;
		where_is_mickey(e);
		exit_helper(e);
	}
}

int			free_elements(t_env *e)
{
	SDL_DestroyWindow(e->win);
	SDL_FreeCursor(e->cursor);
	SDL_FreeSurface(e->w_icon);
	SDL_FreeSurface(e->gui);
	free(e->font);
	e->font = NULL;
	TTF_Quit();
	SDL_Quit();
	kill(e->child, SIGTERM);
	close(g_srv_socket);
	exit(EXIT_SUCCESS);
	return (0);
}

int			global_loop(t_env *e)
{
	SDL_BlitSurface(e->s_loader, &(SDL_Rect){0, 0, e->win_w, e->win_h},
					e->s_background, &(SDL_Rect){0, 0, e->win_w, e->win_h});
	while (e->run)
	{
		SDL_UpdateWindowSurface(e->win);
		loader_wait(e);
		if (SDL_PollEvent(&e->event))
			handle_events(e);
	}
	return (free_elements(e));
}

void		start_interface(t_env *e)
{
	init_sdl_modules();
	init_sdl_env(e);
	init_sdl_interface(e);
	global_loop(e);
}
