/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 01:40:57 by nsampre           #+#    #+#             */
/*   Updated: 2017/08/17 06:18:12 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_xtoa_fill(int width, int n, char *str)
{
	while (width--)
	{
		str[width] = (n % 16) + '0';
		if (str[width] >= 58 && str[width] <= 63)
			str[width] += 39;
		n /= 16;
	}
}

char			*ft_xtoa(int n)
{
	char	*str;
	int		n_bis;
	int		width;
	int		is_negativ;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	width = 1;
	is_negativ = 0;
	if (n < 0)
		is_negativ = 1;
	if (is_negativ)
		n = -n;
	n_bis = n;
	while ((n_bis /= 16) > 0)
		width++;
	if (is_negativ)
		width++;
	str = (char *)ft_memalloc(sizeof(char) * width + 1);
	str[width] = '\0';
	ft_xtoa_fill(width, n, str);
	if (is_negativ)
		str[0] = '-';
	return (str);
}
