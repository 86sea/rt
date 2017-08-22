
#include "libft.h"

t_vec3f		ft_add_vectors(t_vec3f v0, t_vec3f v1)
{
	int i;

	i = -1;
	while (++i < 3)
		v.vec[i] = v0.vec[i] + v1.vec[i];

	return (v);
}

t_vec3f		ft_subtract_vectors(t_vec3f v0, t_vec3f v1)
{
	int i;

	i = -1;
	while (++i < 3)
		v.vec[i] = v0.vec[i] - v1.vec[i];
	return (v);
}

float		calc_m(t_vector v)
{
	float		t;
	int			i;

	t = 0;
	i = -1;
	while (++i < 3)
		t += v.vec[i] * v.vec[i];
	return(sqrt(t));
}