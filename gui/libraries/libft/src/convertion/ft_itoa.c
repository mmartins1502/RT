/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:37:02 by nsampre           #+#    #+#             */
/*   Updated: 2017/08/17 06:18:12 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_itoa_fill(int width, int n, char *str)
{
	while (width--)
	{
		str[width] = (n % 10) + '0';
		n /= 10;
	}
}

char			*ft_itoa(int n)
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
	while ((n_bis /= 10) > 0)
		width++;
	if (is_negativ)
		width++;
	str = (char *)ft_memalloc(sizeof(char) * width + 1);
	str[width] = '\0';
	ft_itoa_fill(width, n, str);
	if (is_negativ)
		str[0] = '-';
	return (str);
}
