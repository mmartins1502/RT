/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:37:42 by nsampre           #+#    #+#             */
/*   Updated: 2017/08/17 06:18:12 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_trim_separator(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

static int		ft_begin_trim(char *s)
{
	int begin;

	begin = -1;
	while (s[++begin])
	{
		if (!(ft_trim_separator(s[begin])))
			break ;
	}
	return (begin);
}

static int		ft_end_trim(char *s)
{
	int end;

	end = (int)ft_strlen((char *)s);
	while (s[--end])
	{
		if (!(ft_trim_separator(s[end])))
			break ;
	}
	return (end);
}

char			*ft_strtrim(char const *s)
{
	char	*new_s;
	int		begin;
	int		end;
	int		j;
	int		len_final;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) == 1)
		return (ft_strdup(s));
	begin = ft_begin_trim((char *)s);
	end = ft_end_trim((char *)s);
	len_final = end - begin + 1;
	if (begin == end || begin > end)
		return (ft_strdup(""));
	if (!(new_s = ft_strnew(len_final)))
		return (NULL);
	j = 0;
	while (begin <= end)
		new_s[j++] = s[begin++];
	new_s[j] = '\0';
	return (new_s);
}
