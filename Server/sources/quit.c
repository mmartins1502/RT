/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 02:53:18 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/10 15:00:50 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	quit(int sig)
{
	(void)sig;
	sleep(1);
	exit(EXIT_SUCCESS);
}

void	fatal_quit(char *msg)
{
	perror(msg);
	sleep(1);
	quit(0);
}

void	custom_quit(char *msg)
{
	if (msg)
		ft_dprintf(2, "\nFatal error : %s\n", msg);
	sleep(1);
	quit(0);
}

void	thread_quit(char *msg)
{
	if (msg)
		dprintf(STDERR_FILENO, "\nWarning : %s. Quiting thread.\n", msg);
	sleep(1);
	pthread_exit(NULL);
}
