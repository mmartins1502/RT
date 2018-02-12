/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 13:50:15 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/10 14:27:24 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

double	p_loop(t_perlin p, t_vector c[2][2][2])
{
	int i;
	int j;
	int k;

	i = -1;
	while (++i < 2)
	{
		j = -1;
		while (++j < 2)
		{
			k = -1;
			while (++k < 2)
			{
				p.weight.x = p.u - i;
				p.weight.y = p.v - j;
				p.weight.z = p.w - k;
				p.accum += (i * p.uu + (1 - i) * (1 - p.uu))
						* (j * p.vv + (1 - j) * (1 - p.vv))
						* (k * p.ww + (1 - k) * (1 - p.ww))
						* vector_dot(c[i][j][k], p.weight);
			}
		}
	}
	return (p.accum);
}

double	trilinear_interp(t_vector c[2][2][2], double u, double v, double w)
{
	t_perlin	p;

	p.accum = 0;
	p.uu = u * u * (3.0 - (2.0 * u));
	p.vv = v * v * (3.0 - (2.0 * v));
	p.ww = w * w * (3.0 - (2.0 * w));
	p.u = u;
	p.v = v;
	p.w = w;
	return (p_loop(p, c));
}

double	noise(t_env *e, t_vector cross)
{
	t_perlin	p;
	t_vector	c[2][2][2];
	int			di;
	int			dj;
	int			dk;

	p = (t_perlin){floor(cross.x), floor(cross.y), floor(cross.z),
		cross.x - floor(cross.x), cross.y - floor(cross.y),
		cross.z - floor(cross.z), 0, 0, 0, 0, (t_vector){0, 0, 0}};
	di = -1;
	while (++di < 2)
	{
		dj = -1;
		while (++dj < 2)
		{
			dk = -1;
			while (++dk < 2)
			{
				c[di][dj][dk] = e->ranvec[e->perm_x[(p.i + di) & 255]
				^ e->perm_y[(p.j + dj) & 255] ^ e->perm_z[(p.k + dk) & 255]];
			}
		}
	}
	return (trilinear_interp(c, p.u, p.v, p.w));
}
