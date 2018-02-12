/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 18:43:22 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	*ft_strlowcase(char *str)
{
	int count;

	count = 0;
	while (str[count] != '\0')
	{
		if ((str[count] >= 'A') && (str[count] <= 'Z'))
		{
			str[count] = str[count] - 'A' + 'a';
		}
		count++;
	}
	return (str);
}

char		*ft_strcapitalize(char *str)
{
	int count;

	str = ft_strlowcase(str);
	count = 0;
	while (str[count] != '\0')
	{
		if (str[count] >= 'A' && str[count] <= 'Z')
			str[count] = str[count] - 'A' + 'a';
		count++;
	}
	if ((str[0] >= 'a') && (str[0] <= 'z'))
		str[0] = str[0] - 'a' + 'A';
	count = 0;
	while (str[count] != '\0')
	{
		if ((str[count] >= 00) && (str[count] <= 46))
		{
			if ((str[count + 1] >= 'a') && (str[count + 1] <= 'z'))
				str[count + 1] = str[count + 1] - 'a' + 'A';
		}
		count++;
	}
	return (str);
}
