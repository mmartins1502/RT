/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_transparency_sources.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 06:03:01 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:22 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	init_transparency_tx_sources(void)
{
	int i;

	g_mem.tsp_tx_total = 0;
	i = 0;
	while (g_tsp_sources[i].file_address)
	{
		if (!(g_mem.s_tsp_tx[i] = IMG_Load(g_tsp_sources[i].file_address)))
		{
			printf("FATAL : Failed to load transparency texture %s\n",
												g_tsp_sources[i].file_address);
			exit(EXIT_FAILURE);
		}
		i++;
		g_mem.tsp_tx_total++;
	}
}
