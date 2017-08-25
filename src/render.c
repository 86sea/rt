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

static inline	t_vec3f	mix(t_vec3f a, t_vec3f b, float mixvalue)
{
	return (ft_add_vectors(ft_multi_vector(a, (1 - mixvalue)),
		ft_multi_vector(b, mixvalue)));
}
static void		init_ray(t_ray *ray)
{
	init_vec(&ray->orig);
	init_vec(&ray->dir);
	ray->dir.vec[2] = -1;
	init_vec(&ray->pixel);
	init_vec(&ray->phit);
	init_vec(&ray->nhit);
	init_vec(&ray->hitcolor);
	ray->t = 0;

}

void					render(t_scene *scene, t_shape *shapes)
{
	t_ray		ray;

	init_ray(&ray);
	ray.dir.vec[2] = -1;
	ray.scale = tan(deg_to_rad(scene->fov * 0.5));
	multi_vec_matrix(&ray.orig, &ray.orig, scene->x);
	ray.j = 0;
	while (ray.j < scene->height)
	{
		ray.i = 0;
		while (ray.i < scene->width)
		{
			ray.pixel.vec[0] = (2 * (ray.i + 0.5) / (float)scene->width - 1) * ray.scale;
			ray.pixel.vec[1] = (1 - 2 * (ray.j + 0.5) / (float)scene->height)
				* ray.scale * 1 / scene->img_aspect_ratio;
			ray.pixel.vec[2] = -1;
			multi_point_matrix(&ray.pixel, &ray.dir, scene->x);
			ray.dir = ft_unit_vector(ray.dir);
			ray.hitcolor = castray(&ray, shapes, scene);
			ray.i++;
		}
		ray.j++;
	}
}

t_vec3f					castray(t_ray *ray, t_shape *shapes, t_scene *scene)
{
	t_vec2f	tex;
	float	scale;
	float	pattern;
	t_vec3f	hitcolor;
	int 	i;

	init_vec(&hitcolor);
	if (trace(ray, shapes, scene, &i))
	{
		ray->phit = ft_add_vectors(ray->orig, ft_multi_vector(ray->dir, ray->t));
		get_surface_data(ray,
			shapes->shape.sphere.center, &tex);
		scale = 4;
		pattern = (fmodf(tex.vec[0] * scale, 1) > 0.5)
		^ (fmodf(tex.vec[1] * scale, 1) > 0.5);
		hitcolor =	ft_multi_vector(mix(shapes->color,
					ft_multi_vector(shapes->color, 0.8), pattern),
						fmaxf(0xf, ft_dot_prod(ray->nhit,
						vec_change_sign(ray->dir))));
	}
	return (hitcolor);
}

int						trace(t_ray *ray, t_shape *shapes, t_scene *scene, int *i)
{
	float	t;
	int		n;

	n = 0;
	t = 100000;
	ray->t = 100000;
	while (n < scene->n)
	{
		if ((inter(ray, &shapes[*i])) && ray->t < t)
		{
			mlx_pixel_put(scene->mlx.mlx, scene->mlx.win, ray->i, ray->j, 0x00ffaabb);
			*i = n;
			return (1);
		}
		n++;
	}
	return (0);
}

void					get_surface_data(t_ray *ray,
							t_vec3f center, t_vec2f *tex)
{
	ray->nhit = ft_subtract_vectors(ray->phit, center);
	ray->nhit = ft_unit_vector(ray->nhit);
	tex->vec[0] = (1 + atan2(ray->nhit.vec[2], ray->nhit.vec[0]) / M_PI) * 0.5;
	tex->vec[1] = acosf(ray->nhit.vec[2]) / M_PI;
}
