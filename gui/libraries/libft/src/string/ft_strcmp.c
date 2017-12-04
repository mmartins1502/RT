/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:37:01 by nsampre           #+#    #+#             */
/*   Updated: 2017/08/17 06:18:12 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *s1_bis;
	unsigned char *s2_bis;

	s1_bis = (unsigned char *)s1;
	s2_bis = (unsigned char *)s2;
	while (*s1_bis || *s2_bis)
	{
		if (*s1_bis != *s2_bis)
			return (*s1_bis - *s2_bis);
		s1_bis++;
		s2_bis++;
	}
	return (0);
}
