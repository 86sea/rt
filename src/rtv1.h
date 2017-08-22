/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 10:44:19 by syoung            #+#    #+#             */
/*   Updated: 2017/08/15 13:12:21 by syoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "../libft/libft.h"
# include <mlx.h>
# include "../libft/get_next_line.h"
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

typedef struct	s_vec3f
{
	float		vec[3];
}				t_vec3f;
typedef struct	s_vec2f
{
	float		vec[2];
}				t_vec2f;
typedef struct	s_vec3i
{
	int			vec[3];
}				t_vec3i;
typedef struct	s_sphere
{
	t_vec3f		center;
	float		radius;
	int			color;
}				t_sphere;
typedef	struct	s_plane
{
	t_vec3f		vec;
	t_vec2f		dimension;
	int			color;
}				t_plane;
typedef enum	e_shapeid
{
	sphere,
	plane,
	clone
}				t_shapeid;
typedef union	u_shapes
{
	t_sphere	sphere;
	t_plane		plane;
}				t_ushapes;
typedef struct	s_shape
{
	t_shapeid	shapeid;
	t_ushapes	shape;
}				t_shape;
typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
}				t_mlx;
typedef struct	s_scene
{
	t_vec3i		dimension;
	t_vec3f		camera;
	char		*framebuff;
	t_mlx		mlx;
	float		fov;
	t_vec3f		light;
	t_vec3f 	light_orgin;
}				t_scene;
typedef struct	s_ray
{
	t_vec3f		origin;
	t_vec3f		direction;
	t_vec3f		pixel;
}				t_ray;

void			init_scene(int fd, t_scene *scene);
void			init_sphere(int fd, t_shape *shapearr);
void			raytrace(t_shape *shapearr, t_scene *scene, t_ray ray, int n);
void			init_ray(int fd, t_ray *ray);
int				sphere_inter(t_shape shapearr, t_ray ray, float *t);
void			new_frame(t_scene *scene);
void			normalize(t_scene *scene, t_shape *shapearr, t_ray *ray);
void			vecnorm(t_vec3f *v);
float			dot_prod(t_vec3f *v);
t_vec3f			subtract_vectors(t_vec3f v0, t_vec3f v1);
int				solve_quad(float *a, float *b, float *c, float *x0, float *x1);
t_vec3f			add_vectors(t_vec3f v0, t_vec3f v1);
t_vec3f			norm2(t_vec3f v);
float			norm(t_vec3f v);
t_vec3f			multi_vector(t_vec3f v, float t);
void	pxl_putimg(t_scene *scene, int x, int y, unsigned int color);
#endif
