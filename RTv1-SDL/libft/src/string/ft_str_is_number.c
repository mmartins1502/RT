/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 18:32:46 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/19 22:10:28 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_number(char *input)
{
	int i;
	int	dot;

	dot = 0;
	i = 0;
	if (ft_strequ(input, "-"))
		return (0);
	if (input[i] == '-')
		i++;
	while (ft_isdigit(input[i]) || input[i] == '.')
	{
		if (input[i] == '.')
		{
			dot++;
			if (dot > 1)
				return (0);
		}
		i++;
	}
	return ((int)ft_strlen(input) == i);
}
