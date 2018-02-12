/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_structures.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 06:23:59 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/01 07:08:49 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRUCTURES_H
# define LIBFT_STRUCTURES_H

# include "libft.h"

typedef struct	s_gnl
{
	int				fd;
	char			*buf_line;
	char			*buf_pos;
}				t_gnl;

int				get_next_line(const int fd, char **line);

typedef	struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_strrepace
{
	int				len_rep;
	int				len_with;
	int				len_front;
	int				count;
}				t_strreplace;

#endif
