/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas <tdelmas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 15:36:14 by tdelmas           #+#    #+#             */
/*   Updated: 2017/12/11 00:50:47 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_clu.h"

const t_texture_sources	g_color_sources[] =
{
	{"earth", "./textures/color/earth.png"},
	{"moon", "./textures/color/moon.jpg"},
	{"mars", "./textures/color/mars.jpg"},
	{"sun", "./textures/color/sun.jpg"},
	{"football", "./textures/color/football.jpg"},
	{"baseball", "./textures/color/baseball.jpeg"},
	{"brick1", "./textures/color/brick1.jpg"},
	{"floor1", "./textures/color/floor1.jpg"},
	{"floor2", "./textures/color/floor2.png"},
	{"Metal(31)", "./textures/color/Metal(31).jpg"},
	{"Metal(32)", "./textures/color/Metal(32).jpg"},
	{"Metal(33)", "./textures/color/Metal(33).jpg"},
	{"Metal(34)", "./textures/color/Metal(34).jpg"},
	{"Metal(35)", "./textures/color/Metal(35).jpg"},
	{"Metal(36)", "./textures/color/Metal(36).jpg"},
	{"pavement2", "./textures/color/pavement2.jpg"},
	{"pavement3", "./textures/color/pavement3.jpg"},
	{"punisher", "./textures/color/punisher.jpeg"},
	{"raytracer", "./textures/color/raytracer.png"},
	{"rayure", "./textures/color/rayure.jpeg"},
	{"stone1", "./textures/color/stone1.jpg"},
	{"stone2", "./textures/color/stone2.jpg"},
	{"stone3", "./textures/color/stone3.jpg"},
	{"stone4", "./textures/color/stone4.jpg"},
	{"stone5", "./textures/color/stone5.jpg"},
	{"stone6", "./textures/color/stone6.jpg"},
	{"wood5", "./textures/color/wood5.jpg"},
	{"zebra", "./textures/color/zebra.jpeg"},
	{NULL, NULL}
};

const t_texture_sources g_skybox_sources[] =
{
	{"appartment", "./textures/skybox/appartment.jpg"},
	{"bar", "./textures/skybox/bar.jpg"},
	{"bedroom", "./textures/skybox/bedroom.jpg"},
	{"clouds", "./textures/skybox/clouds.jpg"},
	{"fractale", "./textures/skybox/fractale.jpg"},
	{"snow", "./textures/skybox/snow.jpg"},
	{"universe", "./textures/skybox/universe.png"},
	{"aurore", "./textures/skybox/aurore.jpg"},
	{"Notre-Dame", "./textures/skybox/Notre-Dame.jpg"},
	{"mountain", "./textures/skybox/mountain.jpg"},
	{"galaxy", "./textures/skybox/galaxy.jpg"},
	{NULL, NULL}
};

const t_texture_sources g_tsp_sources[] =
{
	{"earth", "./textures/transparency/earth.png"},
	{"zebra", "./textures/transparency/zebra.jpeg"},
	{NULL, NULL}
};
