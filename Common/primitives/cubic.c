/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 11:45:52 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 11:45:52 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_clu.h"

void	init_cubic(t_cubic *cu, double c[4])
{
	cu->a = c[2] / c[3];
	cu->b = c[1] / c[3];
	cu->c = c[0] / c[3];
	cu->sq_a = cu->a * cu->a;
	cu->p = 1.0 / 3 * (-1.0 / 3 * cu->sq_a + cu->b);
	cu->q = 1.0 / 2 * (2.0 / 27 * cu->a * cu->sq_a - 1.0 / 3
				* cu->a * cu->b + cu->c);
	cu->cb_p = cu->p * cu->p * cu->p;
	cu->d = cu->q * cu->q + cu->cb_p;
}

void	zero_d(t_cubic *cu, double s[3])
{
	double	u;

	if (ISZERO(cu->q))
	{
		s[0] = 0;
		cu->num = 1;
	}
	else
	{
		u = CBRT(-cu->q);
		s[0] = 2 * u;
		s[1] = -u;
		cu->num = 2;
	}
}

void	negative_d(t_cubic *cu, double s[3])
{
	double	phi;
	double	t;

	phi = 1.0 / 3 * acos(-cu->q / sqrt(-cu->cb_p));
	t = 2 * sqrt(-cu->p);
	s[0] = t * cos(phi);
	s[1] = -t * cos(phi + M_PI / 3);
	s[2] = -t * cos(phi - M_PI / 3);
	cu->num = 3;
}

void	positive_d(t_cubic *cu, double s[3])
{
	double	sqrt_d;
	double	u;
	double	v;

	sqrt_d = sqrt(cu->d);
	u = CBRT(sqrt_d - cu->q);
	v = -CBRT(sqrt_d + cu->q);
	s[0] = u + v;
	cu->num = 1;
}

int		solve_cubic(double c[4], double s[3])
{
	t_cubic	cu;

	if (ISZERO(c[3]))
		return (solve_quadric(c, s));
	init_cubic(&cu, c);
	if (ISZERO(cu.d))
		zero_d(&cu, s);
	else if (cu.d < 0)
		negative_d(&cu, s);
	else
		positive_d(&cu, s);
	cu.sub = 1.0 / 3 * cu.a;
	cu.i = -1;
	while (++cu.i < cu.num)
		s[cu.i] -= cu.sub;
	return (cu.num);
}
