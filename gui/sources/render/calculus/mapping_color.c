#include "rt.h"

void	color_mapping(t_obj *closest_obj)
{
	if (closest_obj->type == OBJ_SPHERE && !closest_obj->marblesize && 1)
	{
		if (!closest_obj->current_texture)
			return ;
		int i = closest_obj->u * closest_obj->current_texture->w;
		int j = (double)(1.0 - closest_obj->v) * closest_obj->current_texture->h;

		//tourner les textures par rapport aux poles
		if (i > closest_obj->current_texture->w / 2)
			i -= closest_obj->current_texture->w / 2;
		else
			i += closest_obj->current_texture->w / 2;

		if (i < 0) i = 0;
		if (j < 0) j = 0;
		if (i > closest_obj->current_texture->w - 1) i = closest_obj->current_texture->w - 1;
		if (j > closest_obj->current_texture->h - 1) j = closest_obj->current_texture->h - 1;

		uint32_t *pixel_array = (uint32_t *)closest_obj->current_texture->pixels;

		double r = ((pixel_array[j * closest_obj->current_texture->w + i] >> 16) & 255) / (double)255.0;
		double g = ((pixel_array[j * closest_obj->current_texture->w + i] >> 8) & 255) / (double)255.0;
		double b = ((pixel_array[j * closest_obj->current_texture->w + i] >> 0) & 255) / (double)255.0;

		closest_obj->color.x = r;
		closest_obj->color.y = g;
		closest_obj->color.z = b;
	}
}
