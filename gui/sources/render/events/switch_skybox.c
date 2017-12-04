#include "rt.h"

void	switch_skybox(t_env *e)
{
	e->skybox_index++;
	if (e->skybox_index == e->skybox_total)
	{
		e->skybox_index = -1;
		e->current_skybox = NULL;
	}
	else
		e->current_skybox = e->s_skybox[e->skybox_index];
	draw_screen(e);
}
