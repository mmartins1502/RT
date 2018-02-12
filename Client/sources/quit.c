/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 02:50:08 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/11 17:10:10 by tdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	custom_quit(char *msg)
{
	if (msg)
		ft_dprintf(2, "\nFatal error : %s\n", msg);
	exit(EXIT_FAILURE);
}

void	fatal_quit(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}
