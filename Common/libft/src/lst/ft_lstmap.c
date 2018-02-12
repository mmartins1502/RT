/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:37:02 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*mapped_lst;
	t_list	*begin_mapped_list;
	t_list	*new_elem;

	if (lst == NULL || f == NULL)
		return (NULL);
	new_elem = f(lst);
	mapped_lst = ft_lstnew(new_elem->content, new_elem->content_size);
	begin_mapped_list = mapped_lst;
	lst = lst->next;
	while (lst)
	{
		new_elem = f(lst);
		mapped_lst->next = ft_lstnew(new_elem->content, new_elem->content_size);
		mapped_lst = mapped_lst->next;
		lst = lst->next;
	}
	return (begin_mapped_list);
}
