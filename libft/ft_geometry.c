/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_geometary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 12:05:01 by syoung            #+#    #+#             */
/*   Updated: 2017/08/24 12:05:05 by syoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline float 	deg_to_rad(float theta)
{
	return (theta * (180.0 / M_PI));
}

void			init_vec(t_vec3f *v)
{
	int i;

	i = -1;
	while (++i < 3)
		v->vec[i] = 0;
}

t_vec3f			vec_change_sign(t_vec3f v)
{
	int i;

	i = -1;
	while (++i < 3)
		v.vec[i] *= -1;
	return (v);
}

void	ft_solve_quad(t_quad *q)
{
	q->delta = pow(q->b, 2) - 4 * q->a * q->c;
	if (q->delta >= 0)
	{
		q->x0 = (-q->b - sqrt(q->delta)) / (2 * q->a);
		q->x1 = (-q->b + sqrt(q->delta)) / (2 * q->a);
	}
}