/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 10:29:28 by syoung            #+#    #+#             */
/*   Updated: 2017/08/25 10:30:03 by syoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			inter(t_ray *ray, t_shape *shape)
{
	int hit;

	hit = 0;
//	if (shape->shapeid == sphere)
		inter_sphere(ray, shape, &hit);
	return (hit);
}

void		inter_sphere(t_ray *ray, t_shape *shape, int *hit)
{
	t_vec3f delta;
	t_quad	q;

	init_vec(&delta);
	q.a = 0;
	q.b = 0;
	q.c = 0;
	delta = ft_subtract_vectors(ray->orig, shape->shape.sphere.center);
	q.a = ft_dot_prod(ray->dir, ray->dir);
	q.b = 2 * ft_dot_prod(ray->dir, delta);
	q.c = ft_dot_prod(delta, delta) - pow(shape->shape.sphere.radius, 2);
	q.x0 = 0;
	q.x1 = 0;
	ft_solve_quad(&q);
	if (q.x0 < q.x1)
		q.x0 = q.x1;
	ray->t = q.x0;
	*hit = (int)q.x0;
}