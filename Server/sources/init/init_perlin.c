/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_perlin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 04:22:06 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	perlin_generate(t_env *e)
{
	int i;

	i = -1;
	while (++i < 256)
	{
		e->ranvec[i].x = -1.0 + (2.0 * randb());
		e->ranvec[i].y = -1.0 + (2.0 * randb());
		e->ranvec[i].z = -1.0 + (2.0 * randb());
		e->ranvec[i] = vector_normalize(e->ranvec[i]);
	}
}

void	permute(int *p, int n)
{
	int	i;
	int	target;
	int	tmp;

	i = n - 1;
	while (i > 0)
	{
		target = (int)(randb() * (i + 1));
		tmp = p[i];
		p[i] = p[target];
		p[target] = tmp;
		i--;
	}
}

void	perlin_generate_perm(int *p)
{
	int i;

	i = -1;
	while (++i < 256)
		p[i] = i;
	permute(p, 256);
}
