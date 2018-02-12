/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 14:34:06 by itonoli-          #+#    #+#             */
/*   Updated: 2017/12/10 21:21:22 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char		*name_obj(int i)
{
	char *ret;

	ret = NULL;
	if (i == OBJ_SPHERE)
		ret = ft_strdup("   SPHERE");
	else if (i == OBJ_PLANE)
		ret = ft_strdup("       PLANE");
	else if (i == OBJ_CYL)
		ret = ft_strdup("CYLINDRE");
	else if (i == OBJ_CONE)
		ret = ft_strdup("         CONE");
	else if (i == OBJ_TRI)
		ret = ft_strdup("TRIANGLE");
	else if (i == OBJ_TORUS)
		ret = ft_strdup("    TORUS");
	else if (i == OBJ_SQUARE)
		ret = ft_strdup("   SQUARE");
	return (ret);
}

char		*yes_no(int i)
{
	char *ret;

	ret = NULL;
	if (i == 1)
		ret = ft_strdup("YES");
	else
		ret = ft_strdup("NO");
	return (ret);
}

void		write_right_text_top(t_env *e)
{
	int		i;
	char	*txt;

	i = -1;
	txt = name_obj(e->selected->type);
	sprintf(e->txt[3], " %s ", txt);
	ft_memdel((void *)&txt);
	if (e->selected->emit != 1)
		sprintf(e->txt[4], " - ");
	else
		sprintf(e->txt[4], " %.0f ", e->selected->light);
	sprintf(e->txt[5], " %.*f ", 2, e->selected->fuzz);
	txt = yes_no(e->selected->reflection);
	sprintf(e->txt[6], " %s ", txt);
	ft_memdel((void *)&txt);
	sprintf(e->txt[7], " %.*f ", 1, e->selected->refraction);
	if (e->selected->type == 6 || e->selected->type == 2)
		sprintf(e->txt[8], " - ");
	else
		sprintf(e->txt[8], " %.0f ", e->selected->radius);
	while (++i < 6)
	{
		create_rect(e->s_background, e->it_rect[i], 0x2b2b2b);
		right_text(e, e->txt[i + 3], e->it_rect[i], COLOR_BG);
	}
}
