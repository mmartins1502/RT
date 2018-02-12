/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_skyboxes_sources.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:12:02 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 09:05:20 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	init_skyboxes_tx_sources(void)
{
	int i;

	g_mem.skybox_total = 0;
	i = 0;
	while (g_skybox_sources[i].file_address)
	{
		if (!(g_mem.s_skybox[i] = IMG_Load(g_skybox_sources[i].file_address)))
		{
			dprintf(2, "FATAL : Failed to load skybox texture %s\n",
					g_skybox_sources[i].file_address);
			exit(EXIT_FAILURE);
		}
		i++;
		g_mem.skybox_total++;
	}
	g_mem.current_skybox = NULL;
	g_mem.skybox_index = -1;
}
