#include "rt.h"

static const t_texture_sources g_color_sources[] =
{
	{"earth", "./textures/color/earth.png"},
	{"moon", "./textures/color/moon.jpg"},
	{"mars", "./textures/color/mars.jpg"},
	{"sun", "./textures/color/sun.jpg"},
	{"football", "./textures/color/football.jpg"},
	{NULL, NULL}
};

void	init_color_tx_sources(t_env *e)
{
	int i;

	e->obj_tx_total = 0;
	i = 0;
	while (g_color_sources[i].file_address)
	{
		if (!(e->s_obj_tx[i] = IMG_Load(g_color_sources[i].file_address)))
		{
			printf("FATAL : Failed to load color texture %s\n",
				   g_color_sources[i].file_address);
			exit(EXIT_FAILURE);
		}
		i++;
		e->obj_tx_total++;
	}
}
