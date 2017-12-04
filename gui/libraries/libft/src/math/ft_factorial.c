/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 00:11:31 by nsampre           #+#    #+#             */
/*   Updated: 2017/08/17 06:20:10 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_factorial(int nb)
{
	int nbrbis;
	int total;

	nbrbis = 1;
	total = 1;
	if (nb >= 0 && nb < 13)
	{
		while (nbrbis <= nb)
		{
			total = total * nbrbis;
			nbrbis++;
		}
		return (total);
	}
	return (0);
}
