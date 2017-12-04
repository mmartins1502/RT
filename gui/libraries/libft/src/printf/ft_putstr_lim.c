/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_lim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qselle <qselle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 15:28:14 by qselle            #+#    #+#             */
/*   Updated: 2017/05/07 15:28:14 by qselle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_lim(char const *str, int size)
{
	int	index;

	index = 0;
	if (str)
	{
		while (index != size && str[index])
		{
			ft_putchar(str[index]);
			index++;
		}
	}
}
