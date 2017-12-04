/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:37:02 by nsampre           #+#    #+#             */
/*   Updated: 2017/08/17 06:18:12 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_display_big_nb(unsigned int nb)
{
	unsigned int width_nb;
	unsigned int nb_bis;

	width_nb = 1;
	nb_bis = nb;
	while ((nb_bis /= 10) > 0)
	{
		width_nb *= 10;
	}
	while (width_nb != 0)
	{
		ft_putchar((nb / width_nb) % 10 + '0');
		width_nb /= 10;
	}
}

void			ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	ft_display_big_nb(nb);
}
