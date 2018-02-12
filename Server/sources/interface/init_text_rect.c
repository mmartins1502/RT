/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_text_rect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 14:33:50 by itonoli-          #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void		init_top_txt_rect_right(t_env *e)
{
	int i;

	i = -1;
	while (++i < 6)
	{
		e->it_rect[i].x = 1232;
		e->it_rect[i].y = 123 + (i * 37);
		e->it_rect[i].w = 42;
		e->it_rect[i].h = 19;
	}
}

void		init_txt_rect_right(t_env *e)
{
	int i;
	int y;

	i = 6;
	while (i < 18)
	{
		if (i % 3 == 0)
		{
			e->it_rect[i].x = 1138;
			y = 371 + (66 * (i - 6) / 3);
		}
		else if ((i + 1) % 3 == 0)
			e->it_rect[i].x = 1232;
		else
			e->it_rect[i].x = 1185;
		e->it_rect[i].y = y;
		e->it_rect[i].w = 42;
		e->it_rect[i++].h = 19;
	}
}

void		init_txt_rect_top(t_env *e)
{
	int i;

	i = -1;
	while (++i < 3)
	{
		e->tt_rect[i].x = 306 + (i * 98);
		e->tt_rect[i].y = 27;
		e->tt_rect[i].w = 42;
		e->tt_rect[i].h = 19;
	}
}

void		init_txt_rects(t_env *e)
{
	init_top_txt_rect_right(e);
	init_txt_rect_right(e);
	init_txt_rect_top(e);
}
