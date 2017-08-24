/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 12:17:22 by syoung            #+#    #+#             */
/*   Updated: 2017/08/22 12:17:23 by syoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
float		ft_vector_dist(t_vec3f v0, t_vec3f a)
{
	return (ft_magnitude(ft_subtract_vectors(v0, a)));
}

t_vec3f		ft_unit_vector(t_vec3f v)
{
	t_vec3f	v0;
	float	m;
	int		i;

	m = ft_magnitude(v);
	i = -1;
	if (m > 0)
	{
		m = 1 / sqrt(m);
		while (++i < 3)
			v0.vec[i] = v.vec[i] * m;
	}
	return (v0);
}

t_vec3f		ft_norm_vector(t_vec3f v, t_vec3f a, t_vec3f b)
{
	float	theta;
	float	m;
	t_vec3f	p;
	t_vec3f	ab;

	ab = ft_subtract_vectors(b, a);
	m = ft_magnitude(ab);
	theta = ft_vector_angle(v, ab);
	m = m * cos(theta);
	p = ft_vec_to_point(a, b, m);
	return (ft_subtract_vectors(b, p));
}

t_vec3f		ft_vec_to_point(t_vec3f p, t_vec3f v, float m)
{
	t_vec3f	v0;
	float	d;
	int		i;

	i = -1;
	d = ft_magnitude(v);
	while (++i < 3)
		v0.vec[i] = p.vec[0] + v.vec[0] * (m / d);
	return (v0);
}

float		ft_vector_angle(t_vec3f a, t_vec3f b)
{
	float	theta;

	theta = acos((ft_dot_prod(a, b)) / (ft_magnitude(a) * ft_magnitude(b)));
	return (theta);
}