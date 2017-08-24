/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 11:52:54 by syoung            #+#    #+#             */
/*   Updated: 2017/08/24 11:52:57 by syoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

inline	t_vec3f	mix(t_vec3f a, t_vec3f b, float mixvalue)
{
	return (ft_add_vectors(ft_multi_vector(a, (1 - mixvalue)),
		ft_multi_vector(b, mixvalue)))
}
void			render(t_scene *scene, t_shape *shapes)
{
	t_ray		ray;

	init_vec(&ray.orig);
	ray.scale = tan(deg_to_rad(scene->fov * 0.5))
	multi_vec_matrix(&orig, &orig, scene.x);
	ray.j = 0;
	while (ray.j < scene->height)
	{
		ray.i = 0;
		while (ray.i < scene->width)
		{
			ray.pixel.vec[0] = (2 * (i + 0.5) / (float)scene->width - 1) * ray.scale;
			ray.pixel.vec[1] = (1 - 2 * (j + 0.5) / (float)scene->height)
				* ray.scale * 1 / scene->img_aspect_ratio;
			ray.pixel.vec[2] = -1;
			multi_point_matrix(&ray.pixel, &ray.dir);
			ray.dir = ft_unit_vector(ray.dir);
			ray.hitcolor = castray(&ray, shapes);
			ray.i++;
		}
		ray.j++;
	}
}

t_vec3f		castray(t_ray *ray, t_shape *shapes)
{
	t_vec2f	tex;
	float	scale;
	float	pattern;
	t_vec3f	hitcolor;

	init_vec(&hitcolor);
	hitobject = NULL;
	if (trace(ray, shapes, hitobject))
	{
		ray.phit = ft_add_vectors(ray->orig, ft_multi_vec(ray->dir, ray->t));
		shape->color = get_surface_data(ray, tex);
		scale = 4;
		pattern = (fmodf(tex.vec[0] * scale, 1) > 0.5) ^ (fmodf(tex.vec[1] * scale, 1) > 0.5);
		hitcolor =	ft_multi_vector(mix(shape->color,
					ft_multi_vector(shape->color, 0.8, pattern)),
						maxf(0xf, ft_dot_prod(ray->nhit,
						vec_change_sign(ray.dir))));
	}
	return (hitcolor);
}