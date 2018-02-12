/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:47:13 by tdelmas           #+#    #+#             */
/*   Updated: 2017/12/11 19:03:11 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void			save_xml(t_env *e, char *base)
{
	FILE	*file_xml;
	t_obj	*obj;
	char	*name_xml;

	name_xml = PRE("./scenes/", POST(ft_strdup(base), ".xml"));
	if (!(file_xml = fopen(name_xml, "wb")))
	{
		perror("fopen");
		return ;
	}
	printf("XML - TRYING TO OPEN %s : %p\n", name_xml, file_xml);
	ft_save_camera(&e->camera, file_xml);
	fprintf(file_xml, "</camera>\n\n");
	obj = e->objects;
	while (obj)
	{
		g_print_obj[obj->type](obj, file_xml);
		fprintf(file_xml, "</object>\n\n");
		obj = obj->next;
	}
	fclose(file_xml);
}

void			write_image(t_env *e, FILE *file)
{
	int			x;
	int			y;
	t_vector	color;

	fprintf(file, "P3\n%d %d\n255\n", (int)F_WIDTH, (int)F_HEIGHT);
	y = -1;
	while (++y < F_HEIGHT)
	{
		x = -1;
		while (++x < F_WIDTH)
		{
			color = g_buffer[x * (int)F_HEIGHT + y];
			fprintf(file, "%d %d %d\n", (int)color.x / e->sum,
				(int)color.y / e->sum, (int)color.z / e->sum);
		}
	}
}

void			save_img(t_env *e, char *base)
{
	FILE	*file_img;
	char	*name_ppm;
	char	*name_png;
	char	*sys;

	name_ppm = PRE("./images/", POST(ft_strdup(base), ".ppm"));
	name_png = PRE("./images/", POST(base, ".png"));
	if ((file_img = fopen(name_ppm, "wb")) < 0)
	{
		perror("open");
		return ;
	}
	printf("IMG - TRYING TO OPEN %s : %p\n", name_ppm, (void *)file_img);
	write_image(e, file_img);
	asprintf(&sys, "sips -s format png %s --out %s >&- \
&& rm %s && echo \"File successfully saved.\"",
	name_ppm, name_png, name_ppm);
	system(sys);
	free(sys);
	sys = NULL;
}

void			save_scene(t_env *e)
{
	int		folder;
	char	*base_name;

	folder = mkdir("./scenes/", 0700);
	folder = mkdir("./images/", 0700);
	base_name = new_name();
	save_xml(e, base_name);
	save_img(e, base_name);
}
