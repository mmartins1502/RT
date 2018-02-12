/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 21:11:02 by itonoli-          #+#    #+#             */
/*   Updated: 2017/12/10 21:13:13 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void		right_text(t_env *e, char *str,
	SDL_Rect rect, SDL_Color color_back)
{
	e->s_tmp = TTF_RenderText_Shaded(e->font[2], str, COLOR_W, color_back);
	SDL_BlitSurface(e->s_tmp, &(SDL_Rect){0, 0, e->s_tmp->w,
		e->s_tmp->h}, e->s_background,
					&(SDL_Rect){rect.x + 41 - e->s_tmp->w, rect.y + 2,
						rect.w, rect.h});
	SDL_FreeSurface(e->s_tmp);
}

void		center_text(t_env *e, char *str,
						SDL_Rect rect, SDL_Color color_back)
{
	e->s_tmp = TTF_RenderText_Shaded(e->font[2], str, COLOR_W, color_back);
	SDL_BlitSurface(e->s_tmp, &(SDL_Rect){0, 0, e->s_tmp->w,
		e->s_tmp->h}, e->s_background,
					&(SDL_Rect){rect.x + 35 - e->s_tmp->w, rect.y + 2,
						rect.w, rect.h});
	SDL_FreeSurface(e->s_tmp);
}

void		write_top_text(t_env *e)
{
	int i;

	i = -1;
	sprintf(e->txt[0], " %.*f ", 2, e->rebond);
	sprintf(e->txt[1], " %.*f ", 2, e->rot_speed);
	sprintf(e->txt[2], " %.*f ", 1, e->move_speed);
	while (++i < 3)
	{
		create_rect(e->s_background, e->tt_rect[i], 0x3c3c3c);
		center_text(e, e->txt[i], e->tt_rect[i], COLOR_TXT);
	}
}
