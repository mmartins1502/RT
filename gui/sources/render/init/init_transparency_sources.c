#include "rt.h"

static const t_texture_sources g_tsp_sources[] =
{
	{"earth", "./textures/transparency/earth.png"},
	{NULL, NULL}
};

void	init_transparency_tx_sources(t_env *e)
{
	int i;

	e->tsp_tx_total = 0;
	i = 0;
	while (g_tsp_sources[i].file_address)
	{
		if (!(e->s_tsp_tx[i] = IMG_Load(g_tsp_sources[i].file_address)))
		{
			printf("FATAL : Failed to load transparency texture %s\n",
				   g_tsp_sources[i].file_address);
			exit(EXIT_FAILURE);
		}
		i++;
		e->tsp_tx_total++;
	}
}
