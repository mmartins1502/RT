/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas <tdelmas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:15:40 by tdelmas           #+#    #+#             */
/*   Updated: 2017/12/11 16:15:41 by tdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void		ft_save_damier(t_obj *obj, FILE *file)
{
	fprintf(file, "\t<damier>%d</damier>\n\t<damier1>0x%.2X, 0x%.2X, 0x%.2X\
</damier1>\n\t<damier2>0x%.2X, 0x%.2X, 0x%.2X</damier2>\n",
	obj->damier, (int)(obj->damier1.x * 255.0),
	(int)(obj->damier1.y * 255.0), (int)(obj->damier1.z * 255.0),
	(int)(obj->damier2.x * 255.0), (int)(obj->damier2.y * 255.0),
	(int)(obj->damier2.z * 255.0));
}

void		ft_save_marble(t_obj *obj, FILE *file)
{
	fprintf(file, "\t<marblesize>%f</marblesize>\n\t<marblecolor>0x%.2X, \
0x%.2X, 0x%.2X</marblecolor>\n", obj->marblesize,
		(int)(obj->marblecolor.x * 255.0),
	(int)(obj->marblecolor.y * 255.0), (int)(obj->marblecolor.z * 255.0));
}

void		ft_save_fuzz(t_obj *obj, FILE *file)
{
	fprintf(file, "\t<fuzz>%f</fuzz>", obj->fuzz);
}

void		ft_save_refraction(t_obj *obj, FILE *file)
{
	fprintf(file, "\t<refraction>%f</refraction>", obj->refraction);
}

void		ft_save_reflection(t_obj *obj, FILE *file)
{
	fprintf(file, "\t<reflection>%d</reflection>\n", obj->reflection);
}
