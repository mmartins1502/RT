#ifndef LIBVECTOR_H
# define LIBVECTOR_H

# include "rt_structs.h"

t_vector		vector_add(t_vector a, t_vector b);
t_vector		vector_sub(t_vector a, t_vector b);
t_vector		vector_cross(t_vector a, t_vector b);
t_vector		vector_mul(t_vector a, t_vector b);
t_vector		vector_negative(t_vector a);
double			vector_dot(t_vector a, t_vector b);
double			vector_cos_angle(t_vector a, t_vector b);
double			vector_angle(t_vector a, t_vector b);
double			vector_magnitude(t_vector v);
t_vector		vector_scale(t_vector a, double scale);
t_vector		vector_factor(t_vector a, double factor, t_vector b);
t_vector		vector_new(double x, double y, double z);
t_vector		vector_normalize(t_vector a);
t_vector		vector_normal(t_env *e, t_obj *closest_obj, t_ray ray);
t_vector		normal_sphere(t_obj *closest_obj);
t_vector		normal_cone(t_obj *closest_obj);
t_vector		normal_plane(t_obj *closest_obj, t_ray ray);
t_vector		normal_cyl(t_obj *closest_obj);

#endif
