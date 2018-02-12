/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_text2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 21:15:13 by itonoli-          #+#    #+#             */
/*   Updated: 2017/12/10 21:27:30 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void		all_null(t_env *e)
{
	sprintf(e->txt[15], " -    ");
	sprintf(e->txt[16], " -    ");
	sprintf(e->txt[17], " -    ");
	sprintf(e->txt[18], " -    ");
	sprintf(e->txt[19], " -    ");
	sprintf(e->txt[20], " -    ");
}

void		select_marble_damier(t_env *e)
{
	if (e->selected->marblesize != 0)
	{
		sprintf(e->txt[15], " %.0f  ", e->selected->marblecolor.x * 255);
		sprintf(e->txt[16], " %.0f  ", e->selected->marblecolor.y * 255);
		sprintf(e->txt[17], " %.0f  ", e->selected->marblecolor.z * 255);
		sprintf(e->txt[18], " -    ");
		sprintf(e->txt[19], " -    ");
		sprintf(e->txt[20], " -    ");
	}
	else if (e->selected->damier)
	{
		sprintf(e->txt[15], " %.0f  ", e->selected->damier1.x * 255);
		sprintf(e->txt[16], " %.0f  ", e->selected->damier1.y * 255);
		sprintf(e->txt[17], " %.0f  ", e->selected->damier1.z * 255);
		sprintf(e->txt[18], " %.0f  ", e->selected->damier2.x * 255);
		sprintf(e->txt[19], " %.0f  ", e->selected->damier2.y * 255);
		sprintf(e->txt[20], " %.0f  ", e->selected->damier2.z * 255);
	}
	else
		all_null(e);
}

void		write_right_text(t_env *e)
{
	int i;

	i = 5;
	sprintf(e->txt[9], " %.0f  ", e->selected->color.x * 255);
	sprintf(e->txt[10], " %.0f  ", e->selected->color.y * 255);
	sprintf(e->txt[11], " %.0f  ", e->selected->color.z * 255);
	sprintf(e->txt[12], " %.1f  ", e->selected->dir.x);
	sprintf(e->txt[13], " %.1f  ", e->selected->dir.y);
	sprintf(e->txt[14], " %.1f  ", e->selected->dir.z);
	select_marble_damier(e);
	while (++i < 18)
	{
		if (i == e->it_actif)
			create_b_rect(e->s_background, e->it_rect[(int)e->it_actif],
				0x3c3c3c, 0x5bc4e6);
		else
			create_rect(e->s_background, e->it_rect[i], 0x3c3c3c);
		center_text(e, e->txt[i + 3], e->it_rect[i], COLOR_TXT);
	}
}
