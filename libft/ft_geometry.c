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

inline float deg_to_rad(float theta)
{
	return (theta * (180.0 / M_PI));
}

inline void init_vec(t_vec3f *v)
{
	int i;

	i = -1;
	while (++i < 3)
		v->vec[i] = 0;
}

inline	t_vec3f	vec_change_sign(t_vec3f v)
{
	int i;

	i = -1;

	while (++i < 3)
		v.vec[i] *= -1;
	return (v);
}