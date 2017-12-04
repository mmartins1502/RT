/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 18:32:46 by nsampre           #+#    #+#             */
/*   Updated: 2017/08/17 06:21:50 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_number(char *input)
{
	int i;

	i = 0;
	if (ft_strequ(input, "-"))
		return (0);
	if (input[i] == '-')
		i++;
	while (ft_isdigit(input[i]))
		i++;
	return ((int)ft_strlen(input) == i);
}
