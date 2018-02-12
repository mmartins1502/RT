/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas <tdelmas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:08:59 by tdelmas           #+#    #+#             */
/*   Updated: 2017/12/11 16:09:19 by tdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char		*g_filter[] =
{
	NULL,
	"sepia",
	"greyscale",
	"negative"
};

void		ft_save_filter(FILE *file)
{
	fprintf(file, "\t<filter>%s</filter>\n", g_filter[g_e->filter]);
}

void		ft_save_skybox(FILE *file)
{
	fprintf(file, "\t<skybox>%s</skybox>\n",
			g_skybox_sources[g_e->skybox_index].name);
}

void		ft_save_transparent(t_obj *obj, FILE *file)
{
	fprintf(file, "\t<transparent>%s</transparent>\n",
			g_tsp_sources[obj->tsp_index].name);
}

void		ft_save_texture(t_obj *obj, FILE *file)
{
	fprintf(file, "\t<texture>%s</texture>\n",
			g_color_sources[obj->texture_index].name);
}

void		ft_save_light(t_obj *obj, FILE *file)
{
	fprintf(file, "\t<light>%f</light>\n", obj->light);
}
