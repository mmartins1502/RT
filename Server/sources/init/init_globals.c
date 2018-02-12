/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_globals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 02:57:27 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/08 22:28:24 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	init_globals(t_env *e)
{
	struct timeval t;

	g_e = e;
	g_buffer = (t_vector *)ft_memalloc(
							sizeof(t_vector) * (int)F_WIDTH * (int)F_HEIGHT);
	gettimeofday(&t, NULL);
	g_e->nb_cli = 0;
	srand(t.tv_usec);
}
