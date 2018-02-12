/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 02:51:04 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/10 13:33:38 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int			g_cli_socket;
char		*g_address;
int			g_port;
int			*g_buffer;
int			**g_frame_array;
t_vector	**g_color_array;
t_mem		g_mem;
t_window	g_win;
t_env		*g_e;

void	quit(int k)
{
	(void)k;
	close(g_cli_socket);
	exit(EXIT_SUCCESS);
}

void	copy_pixel_to_sdl(SDL_Surface *s, ssize_t x, ssize_t y)
{
	int			c;

	c = g_buffer[x * (int)F_HEIGHT + y];
	c |= 0xFF000000;
	*((int *)(s->pixels + y * s->pitch + x * s->format->BytesPerPixel)) = c;
}

void	show_frame(void)
{
	int	x;
	int	y;

	y = -1;
	while (++y < F_HEIGHT)
	{
		x = -1;
		while (++x < F_WIDTH)
		{
			copy_pixel_to_sdl(g_win.s_background, x, y);
		}
	}
	SDL_PollEvent(&g_win.event);
	if (g_win.event.window.event == SDL_WINDOWEVENT_CLOSE ||
									(g_win.event.type == SDL_KEYDOWN &&
									g_win.event.key.keysym.sym == SDLK_ESCAPE))
		quit(0);
	SDL_BlitSurface(g_win.s_background, &(SDL_Rect){0, 0, F_WIDTH, F_HEIGHT},
					g_win.s_background, &(SDL_Rect){0, 0, F_WIDTH, F_HEIGHT});
	SDL_UpdateWindowSurface(g_win.win);
}

void	loop(t_env *e)
{
	while (42)
	{
		sync_env(e);
		sync_objects(e, NULL);
		draw_screen(e);
		if (g_win.activate)
			show_frame();
		sync_buffer(e);
		release_obj(e);
	}
}

int		main(int argc, char **argv)
{
	t_env	*e;

	if (argc < 3 || !ft_str_is_number(argv[2]))
	{
		ft_printf("./client <addr> <port> --win\n");
		exit(EXIT_FAILURE);
	}
	g_win.activate = ft_strequ("--win", argv[3]);
	g_port = ft_atoi(argv[2]);
	g_address = argv[1];
	connect_to_server();
	signal(SIGTERM, quit);
	e = (t_env *)ft_memalloc(sizeof(t_env));
	g_e = e;
	init_globals();
	init_skyboxes_tx_sources();
	init_color_tx_sources();
	init_transparency_tx_sources();
	loop(e);
}
