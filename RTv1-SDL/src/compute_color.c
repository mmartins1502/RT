/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 09:40:05 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/28 09:54:40 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	diffuse_color(t_env *e, t_color obj_c, t_color light_c, double coef)
{
	e->color.r += obj_c.r * coef * (double)(light_c.r / (double)0xFF);
	e->color.g += obj_c.g * coef * (double)(light_c.g / (double)0xFF);
	e->color.b += obj_c.b * coef * (double)(light_c.b / (double)0xFF);
	(e->color.r > 0xFF) ? (e->color.r = 0xFF) : 0;
	(e->color.g > 0xFF) ? (e->color.g = 0xFF) : 0;
	(e->color.b > 0xFF) ? (e->color.b = 0xFF) : 0;
}

void	specular_color(t_env *e, t_color light_c, double coef)
{
	e->color.r += light_c.r * coef;
	e->color.g += light_c.g * coef;
	e->color.b += light_c.b * coef;
	(e->color.r > 0xFF) ? (e->color.r = 0xFF) : 0;
	(e->color.g > 0xFF) ? (e->color.g = 0xFF) : 0;
	(e->color.b > 0xFF) ? (e->color.b = 0xFF) : 0;
}
