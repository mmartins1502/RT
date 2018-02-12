/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 02:59:21 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/11 17:53:47 by tdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int				g_srv_socket;
int				g_port;
t_vector		*g_buffer;
t_env			*g_e;
pthread_mutex_t	g_mutex;

static void	*loop(void *data)
{
	int		cs;
	t_env	*e;

	e = g_e;
	cs = (int)data;
	while (42)
	{
		sync_env_obj(e, cs);
		sync_buffer(cs, e);
		display_buffer(e);
	}
	return (NULL);
}

static void	*wait_client(void *data)
{
	pthread_t	t;
	int64_t		cs;

	(void)data;
	while (42)
	{
		cs = connect_to_client();
		if (pthread_create(&t, NULL, loop, (void *)cs))
			fatal_quit("pthread_create");
	}
	return (NULL);
}

static void	launch_local_client(t_env *e)
{
	e->child = fork();
	if (e->child == -1)
		fatal_quit("fork");
	if (!e->child)
	{
		if (execlp("./rt_client", "rt_client",
					"127.0.0.1", ft_itoa(g_port), (char *)NULL) == -1)
			fatal_quit("execlp");
	}
}

int			main(int argc, char **argv)
{
	t_env		*e;
	pthread_t	t;

	e = (t_env *)ft_memalloc(sizeof(t_env));
	g_e = e;
	init_render_env(e);
	get_options(e, argc, argv);
	init_globals(e);
	init_master_socket();
	if (e->local_compute)
		launch_local_client(e);
	if (pthread_create(&t, NULL, wait_client, NULL))
		fatal_quit("pthread_create");
	start_interface(e);
}
