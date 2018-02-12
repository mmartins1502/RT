/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connexion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 23:34:12 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/11 14:37:53 by tdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	init_master_socket(void)
{
	struct sockaddr_in	address;

	signal(SIGTERM, quit);
	signal(SIGQUIT, quit);
	signal(SIGINT, quit);
	signal(SIGPIPE, quit);
	if ((g_srv_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		fatal_quit("\nCreate server_socket");
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(g_port);
	if (bind(g_srv_socket, (struct sockaddr *)&address, sizeof(address)) < 0)
		fatal_quit("\nbind");
	if (listen(g_srv_socket, 4) < 0)
		fatal_quit("listen");
}

int		connect_to_client(void)
{
	socklen_t			cslen;
	struct sockaddr		csin;
	int					cs;

	if (g_e->nb_cli == 4)
		pthread_exit(NULL);
	ft_printf("\nWaiting for client...\n");
	cslen = sizeof(csin);
	if ((cs = accept(g_srv_socket, (struct sockaddr *)&csin, &cslen)) < 0)
		fatal_quit("\naccept");
	else
		g_e->nb_cli++;
	ft_printf("\nConnected to client\n");
	return (cs);
}

void	sync_env_obj(t_env *e, int cs)
{
	t_obj	*obj;

	if (send(cs, (void *)e, sizeof(t_env), 0) < 0)
		thread_quit("send");
	obj = e->objects;
	while (obj)
	{
		if (send(cs, (void *)obj, sizeof(t_obj), 0) < 0)
			thread_quit("send");
		obj = obj->next;
	}
}

void	write_global_buffer(int *local_buffer, t_env *e)
{
	ssize_t	x;
	ssize_t	y;
	int		color;

	pthread_mutex_lock(&g_mutex);
	y = -1;
	while (++y < F_HEIGHT)
	{
		x = -1;
		while (++x < F_WIDTH)
		{
			color = local_buffer[x * (int)F_HEIGHT + y];
			if (e->live == 1 || e->reset)
				g_buffer[x * (int)F_HEIGHT + y] = (t_vector)
				{(color >> 16) & 255, (color >> 8) & 255, color & 255};
			else
			{
				g_buffer[x * (int)F_HEIGHT + y].x += (color >> 16) & 255;
				g_buffer[x * (int)F_HEIGHT + y].y += (color >> 8) & 255;
				g_buffer[x * (int)F_HEIGHT + y].z += color & 255;
			}
		}
	}
	pthread_mutex_unlock(&g_mutex);
}

void	sync_buffer(int cs, t_env *e)
{
	ssize_t r;
	ssize_t os;
	int		*local_buffer;
	char	live;

	local_buffer = (int *)ft_memalloc(sizeof(int) * F_WIDTH * F_HEIGHT);
	os = 0;
	while (os < ((int)sizeof(int) * (int)F_WIDTH * (int)F_HEIGHT))
	{
		r = recv(cs, (void *)local_buffer + os,
						(sizeof(int) * (int)F_WIDTH * (int)F_HEIGHT) - os, 0);
		(r == -1) ? thread_quit("recv") : 0;
		os += r;
	}
	r = recv(cs, (void *)&live, sizeof(char), 0);
	(r == -1) ? thread_quit("recv") : 0;
	if (live == e->live)
	{
		write_global_buffer(local_buffer, e);
		(e->live == 1 || e->reset) ? e->sum = 1 : e->sum++;
		e->reset = 0;
	}
	free(local_buffer);
	local_buffer = NULL;
}
