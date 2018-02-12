/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 22:49:35 by itonoli-          #+#    #+#             */
/*   Updated: 2017/12/10 21:40:15 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void		cli_arrived(t_env *e)
{
	create_rect(e->s_background,
				(SDL_Rect){490, 670 - 30, 500, 30}, 0x242424);
	if (e->nb_cli == 1)
		sprintf(e->txt[22],
			"%d CLIENT CONNECTED TO THE SERVER", e->nb_cli);
	else
		sprintf(e->txt[22],
			"%d CLIENTS CONNECTED TO THE SERVER", e->nb_cli);
	e->s_tmp = TTF_RenderText_Shaded(e->font[0], e->txt[22],
			COLOR_W, COLOR_LO);
	SDL_BlitSurface(e->s_tmp, &(SDL_Rect){0, 0, e->s_tmp->w,
		e->s_tmp->h}, e->s_background, &(SDL_Rect){490, 670 - 30,
			e->s_tmp->w, e->s_tmp->h});
	SDL_FreeSurface(e->s_tmp);
	e->s_tmp = TTF_RenderText_Shaded(e->font[2],
			"    YOU CAN PRESS ANY KEY TO START...    ",
			COLOR_Y, COLOR_LO);
	SDL_BlitSurface(e->s_tmp, &(SDL_Rect){0, 0, e->s_tmp->w,
		e->s_tmp->h}, e->s_background, &(SDL_Rect){540, 704 - 30,
			e->s_tmp->w, e->s_tmp->h});
	SDL_FreeSurface(e->s_tmp);
}

void		loader_wait(t_env *e)
{
	if (e->loader == 1)
	{
		SDL_BlitSurface(e->s_slave, &(SDL_Rect){0 + (120 * e->slave), 0, 120,
			190}, e->s_background, &(SDL_Rect){580, 490 - 30, 120, 190});
		e->slave++;
		if (e->slave == 13)
			e->slave = 0;
		if (e->nb_cli == 0)
		{
			e->s_tmp = TTF_RenderText_Shaded(e->font[1],
					"WAITING FOR CLIENTS TO CONNECT...", COLOR_W, COLOR_LO);
			SDL_BlitSurface(e->s_tmp, &(SDL_Rect){0, 0, e->s_tmp->w,
				e->s_tmp->h}, e->s_background, &(SDL_Rect){490, 670 - 30,
					e->s_tmp->w, e->s_tmp->h});
			SDL_FreeSurface(e->s_tmp);
		}
		else if (e->nb_cli > 0)
			cli_arrived(e);
	}
}
