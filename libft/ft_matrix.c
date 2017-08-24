/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 12:59:57 by syoung            #+#    #+#             */
/*   Updated: 2017/08/22 13:00:00 by syoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline double	dot(double *a, double *b, int len, int step)
{
	double r;

	r = 0.0;
	while (len--)
	{
		r += *a++ * *b;
		b += step;
	}
	return (r);
}

matrix			mat_new(int h, int w)
{
	matrix r;

	r = malloc(sizeof(t_matrix) + sizeof(double) * w * h);
	r->h = h;
	r->w = w;
	r->x = (double*)(r + 1);
	return (r);
}

matrix			mat_mul(matrix a, matrix b)
{
	matrix	r;
	double	*p;
	double	*pa;
	int		i;
	int		j;

	if (a->w != b->h)
		return (0);
	r = mat_new(a->h, b->w);
	p = r->x;
	for (pa = a->x, i = 0; i < a->h; i++, pa += a->w)
		for (j = 0; j < b->w; j++)
			*p++ = dot(pa, b->x + j, a->w, b->w);
	return (r);
}

void			multi_vec_matrix(t_vec3f *src, t_vec3f *dst, int **x)
{
	t_vec3f	tmp;
	float	w;
	int		i;

	i = -1;
	while (++i < 3)
		tmp.vec[i] = src->vec[0] * x[0][0] + src->vec[1]
			* x[1][0] + src->vec[2] * x[2][0];
	w = src->vec[0] * x[0][0] + src->vec[1] * x[1][0] + src->vec[2] * x[2][0];
	i = -1;
	while (++i < 3)
		dst->vec[i] = tmp.vec[i] / w;
}

void			multi_point_matrix(t_vec3f *src, t_vec3f *dst, int **x)
{
	t_vec3f	tmp;
	int		i;

	i = -1;
	while (++i < 3)
		tmp.vec[i] = src->vec[0] * x[0][i] + src->vec[1]
			+ src->vec[2] * x[2][i];
	i = -1;
	while (++i < 3)
		dst->vec[i] = tmp.vec[i];
}
/*void mat_show(matrix a)
{
	int i, j;
	double *p = a->x;
	for (i = 0; i < a->h; i++, putchar('\n'))
		for (j = 0; j < a->w; j++)
			printf("\t%7.3f", *p++);
	putchar('\n');
}
 */
/*
 ** USAGE
 **	double da[] = {	1, 1,  1,   1,
 **			2, 4,  8,  16,
 **			3, 9, 27,  81,
 **			4,16, 64, 256	};
 **	double db[] = {     4.0,   -3.0,  4.0/3,
 **			-13.0/3, 19.0/4, -7.0/3,
 **			  3.0/2,   -2.0,  7.0/6,
 **			 -1.0/6,  1.0/4, -1.0/6};
*/

/*
 **	t_matrix a = { 4, 4, da }, b = { 4, 3, db };
 **	matrix c = mat_mul(&a, &b);
*/
