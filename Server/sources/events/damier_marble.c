/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   damier_marble.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:19:01 by itonoli-          #+#    #+#             */
/*   Updated: 2017/12/10 01:01:09 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void		damier_marble_r(t_env *e, int mode)
{
	if (e->selected->marblesize == 0)
		dam_one_color_r(e, mode);
	else
		marble_color_r(e, mode);
}

void		damier_marble_g(t_env *e, int mode)
{
	if (e->selected->marblesize == 0)
		dam_one_color_g(e, mode);
	else
		marble_color_g(e, mode);
}

void		damier_marble_b(t_env *e, int mode)
{
	if (e->selected->marblesize == 0)
		dam_one_color_b(e, mode);
	else
		marble_color_b(e, mode);
}
