/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadric.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 11:45:22 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/10 13:47:38 by tdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_clu.h"

int	solve_quadric(double c[3], double s[2])
{
	t_quadric	qd;

	if (ISZERO(c[2]))
	{
		if (ISZERO(c[1]))
			return (0);
		s[0] = -c[0] / c[1];
		return (1);
	}
	qd.p = c[1] / (2 * c[2]);
	qd.q = c[0] / c[2];
	qd.d = qd.p * qd.p - qd.q;
	if (ISZERO(qd.d))
		s[0] = -qd.p;
	if (ISZERO(qd.d))
		return (1);
	else if (qd.d < 0)
		return (0);
	else if (qd.d > 0)
	{
		s[0] = sqrt(qd.d) - qd.p;
		s[1] = -sqrt(qd.d) - qd.p;
		return (2);
	}
	return (0);
}
