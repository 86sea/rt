/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 12:14:39 by syoung            #+#    #+#             */
/*   Updated: 2017/08/22 12:14:42 by syoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec3f		ft_add_vectors(t_vec3f v0, t_vec3f v1)
{
	int		i;
	t_vec3f	v;

	i = -1;
	while (++i < 3)
		v.vec[i] = v0.vec[i] + v1.vec[i];
	return (v);
}

t_vec3f		ft_subtract_vectors(t_vec3f v0, t_vec3f v1)
{
	int		i;
	t_vec3f	v;

	i = -1;
	while (++i < 3)
		v.vec[i] = v0.vec[i] - v1.vec[i];
	return (v);
}

t_vec3f		ft_multi_vector(t_vec3f v, float t)
{
	int		i;

	i = -1;
	while (++i < 3)
		v.vec[i] *= t;
	return (v);
}

float		ft_magnitude(t_vec3f v)
{
	float		t;
	int			i;

	t = 0;
	i = -1;
	while (++i < 3)
		t += v.vec[i] * v.vec[i];
	return (sqrt(t));
}

float		ft_dot_prod(t_vec3f v0, t_vec3f v1)
{
	float	d;
	int		i;

	i = -1;
	d = 0;
	while (++i < 3)
		d += v0.vec[i] * v1.vec[i];
	return (d);
}
