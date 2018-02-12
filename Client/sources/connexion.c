/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connexion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 02:49:26 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/10 11:37:46 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	connect_to_server(void)
{
	struct sockaddr_in	address;

	ft_printf("Connecting to server\n");
	if ((g_cli_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
		fatal_quit("Create client_socket");
	address.sin_family = AF_INET;
	inet_pton(AF_INET, g_address, (void *)&address.sin_addr);
	address.sin_port = htons(g_port);
	if (connect(g_cli_socket, (struct sockaddr *)&address, sizeof(address)) < 0)
		fatal_quit("connect");
	ft_printf("Connected to server\n");
}

void	sync_env(t_env *e)
{
	ssize_t	r;
	size_t	os;

	os = 0;
	while (os < sizeof(t_env))
	{
		r = recv(g_cli_socket, (void *)e + os, sizeof(t_env) - os, 0);
		if (r == -1)
			fatal_quit("recv env structure");
		os += r;
	}
	if (e->magic != MAGIC)
		custom_quit("Corrupted env data received. Invalid magic.");
	e->color_array = g_color_array;
	e->frame_array = g_frame_array;
	if (e->skybox_index != -1)
		e->current_skybox = g_mem.s_skybox[e->skybox_index];
	else
		e->current_skybox = NULL;
	e->objects = NULL;
}

void	sync_objects(t_env *e, t_obj *obj)
{
	ssize_t	r;
	size_t	os;
	int		i;

	i = -1;
	while (++i < e->object_count)
	{
		obj = new_obj();
		os = 0;
		while (os < sizeof(t_obj))
		{
			r = recv(g_cli_socket, (void *)obj + os, sizeof(t_obj) - os, 0);
			(r == -1) ? fatal_quit("recv object structure") : 0;
			os += r;
		}
		obj->current_texture = NULL;
		if (obj->texture_index != -1)
			obj->current_texture = g_mem.s_obj_tx[obj->texture_index];
		obj->current_tsp = NULL;
		if (obj->tsp_index != -1)
			obj->current_tsp = g_mem.s_tsp_tx[obj->tsp_index];
		obj->next = NULL;
		obj_push_back(&e->objects, obj);
	}
}

void	sync_buffer(t_env *e)
{
	ssize_t	r;

	r = send(g_cli_socket, g_buffer,
							sizeof(int) * (int)F_WIDTH * (int)F_HEIGHT, 0);
	if (r == -1)
		fatal_quit("send buffer");
	send(g_cli_socket, (void *)&e->live, sizeof(char), 0);
	if (r == -1)
		fatal_quit("send buffer");
	ft_printf("\r%d frames computed yet...", ++g_mem.frames);
}

void	release_obj(t_env *e)
{
	t_obj *obj;
	t_obj *temp;

	obj = e->objects;
	while (obj)
	{
		temp = obj->next;
		free(obj);
		obj = temp;
	}
}
