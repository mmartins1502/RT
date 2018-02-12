/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   marble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 22:48:17 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	marble_object(t_env *e)
{
	if (!e->selected)
		return ;
	if (e->selected->marblesize == 0)
	{
		e->selected->marblesize = randb() / (double)1000.0;
		e->selected->marblecolor = (t_vector){randb(), randb(), randb()};
	}
	else
	{
		e->selected->marblesize = 0;
		e->selected->marblecolor = (t_vector){0, 0, 0};
	}
}
