/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quartic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 11:45:24 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/10 13:49:09 by tdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_clu.h"

int		init_quartic(t_quartic *q, double c[5])
{
	q->a = c[3] / c[4];
	q->b = c[2] / c[4];
	q->c = c[1] / c[4];
	q->d = c[0] / c[4];
	q->sq_a = q->a * q->a;
	q->p = -3.0 / 8 * q->sq_a + q->b;
	q->q = 1.0 / 8 * q->sq_a * q->a - 1.0 / 2 * q->a * q->b + q->c;
	q->r = -3.0 / 256 * q->sq_a * q->sq_a + 1.0 / 16 * q->sq_a * q->b
		- 1.0 / 4 * q->a * q->c + q->d;
	q->i = -1;
	return (1);
}

void	root_zero(t_quartic *q, double s[4])
{
	q->coeffs[0] = q->q;
	q->coeffs[1] = q->p;
	q->coeffs[2] = 0;
	q->coeffs[3] = 1;
	q->num = solve_cubic(q->coeffs, s);
	s[q->num++] = 0;
}

void	root_non_zero(t_quartic *q, double s[4])
{
	q->coeffs[0] = 1.0 / 2 * q->r * q->p - 1.0 / 8 * q->q * q->q;
	q->coeffs[1] = -q->r;
	q->coeffs[2] = -1.0 / 2 * q->p;
	q->coeffs[3] = 1;
	solve_cubic(q->coeffs, s);
	q->z = s[0];
	q->u = q->z * q->z - q->r;
	q->v = 2 * q->z - q->p;
}

void	solve_resolvant_quartic(t_quartic *q, double s[4])
{
	q->coeffs[0] = q->z - q->u;
	q->coeffs[1] = q->q < 0 ? -q->v : q->v;
	q->coeffs[2] = 1;
	q->num = solve_quadric(q->coeffs, s);
	q->coeffs[0] = q->z + q->u;
	q->coeffs[1] = q->q < 0 ? q->v : -q->v;
	q->coeffs[2] = 1;
	q->num += solve_quadric(q->coeffs, s + q->num);
}

int		solve_quartic(double c[5], double s[4])
{
	t_quartic	q;

	if (init_quartic(&q, c) && ISZERO(q.r))
		root_zero(&q, s);
	else
	{
		root_non_zero(&q, s);
		if (ISZERO(q.u))
			q.u = 0;
		else if (q.u > 0)
			q.u = sqrt(q.u);
		else
			return (0);
		if (ISZERO(q.v))
			q.v = 0;
		else if (q.v > 0)
			q.v = sqrt(q.v);
		else
			return (0);
		solve_resolvant_quartic(&q, s);
	}
	q.sub = 1.0 / 4 * q.a;
	while (++q.i < q.num)
		s[q.i] -= q.sub;
	return (q.num);
}
