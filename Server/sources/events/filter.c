/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 22:36:00 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	sepia(t_vector *pixel)
{
	t_vector	sepia;

	sepia.x = 0.393 * pixel->x + 0.769 * pixel->y + 0.189 * pixel->z;
	sepia.y = 0.349 * pixel->x + 0.686 * pixel->y + 0.168 * pixel->z;
	sepia.z = 0.272 * pixel->x + 0.534 * pixel->y + 0.131 * pixel->z;
	pixel->x = (sepia.x > 255.0) ? 255.0 : sepia.x;
	pixel->y = (sepia.y > 255.0) ? 255.0 : sepia.y;
	pixel->z = (sepia.z > 255.0) ? 255.0 : sepia.z;
}

void	black_and_white(t_vector *pixel)
{
	t_vector	greyscale;

	greyscale.x = 0.2126 * pixel->x + 0.7152 * pixel->y + 0.0722 * pixel->z;
	greyscale.y = greyscale.x;
	greyscale.z = greyscale.x;
	pixel->x = (greyscale.x > 255.0) ? 255.0 : greyscale.x;
	pixel->y = (greyscale.y > 255.0) ? 255.0 : greyscale.y;
	pixel->z = (greyscale.z > 255.0) ? 255.0 : greyscale.z;
}

void	negative(t_vector *pixel)
{
	pixel->x = 255.0 - pixel->x;
	pixel->y = 255.0 - pixel->y;
	pixel->z = 255.0 - pixel->z;
}

void	switch_filter(t_env *e)
{
	e->filter++;
	if (e->filter == 4)
		e->filter = 0;
}
