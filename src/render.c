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

void	render(t_scene *scene, t_shape *shapes)
{
	float		scale;
	float		img_aspect_ratio;
	int			i;
	int			j;
	t_ray		ray;

	ray.orig.vec[0] = 0;
	ray.orig.vec[1] = 0;
	ray.orig.vec[2] = 0;
	scale = tan(deg_to_rad(scene->fov * 0.5))
	img_aspect_ratio = HIEGHT / WIDTH;
	multi_vec_matrix(&orig, &orig, scene.x);
	j = 0;
	while (j < scene->height)
	{
		i = 0;
		while (i < scene->width)
		{
			ray.pixel.vec[0] = (2 * (i + 0.5) / (float)scene->width - 1) * scale;
			ray.pixel.vec[1] = (1 - 2 * (j + 0.5) / (float)scene->height)
				* scale * 1 / img_aspect_ratio;
			i++;
			ray.dir.vec[0] = x;
			ray.dir.vec[1] = y;
			ray.dir.vec[2] = -1;

			multi_point_matrix(&ray.dir, &ray.dir);
			// norm dir ????
		}
		j++;
	}
}