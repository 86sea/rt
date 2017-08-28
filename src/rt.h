/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 10:44:19 by syoung            #+#    #+#             */
/*   Updated: 2017/08/24 11:41:55 by syoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# define WIDTH 640
# define HEIGHT 480
# include "../libft/libft.h"
# include <mlx.h>
# include "../libft/get_next_line.h"
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

typedef struct	s_sphere
{
	t_vec3f		center;
	float		radius;
	int			color;
}				t_sphere;
typedef	struct	s_plane
{
	t_vec3f		vec;
	t_vec3f		dimension;
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
	t_vec3f		color;
}				t_shape;
typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
}				t_mlx;
typedef struct	s_scene
{
	int			width;
	int			height;
	float		x[4][4];
	t_mlx		mlx;
	float		fov;
	float		img_aspect_ratio;
	int			n;
}				t_scene;
typedef struct	s_ray
{
	t_vec3f		orig;
	t_vec3f		dir;
	t_vec3f		pixel;
	t_vec3f		phit;
	t_vec3f		nhit;
	t_vec3f		hitcolor;
	float		scale;
	int			i;
	int			j;
	float		t;
}				t_ray;

int				sphere_inter(t_shape shapearr, t_ray ray, float *t);
int				inter(t_ray *ray, t_shape *shape);
void			inter_sphere(t_ray *ray, t_shape *shape, int *hit);
int				trace(t_ray *ray, t_shape *shapes, t_scene *scene);
t_vec3f			castray(t_ray *ray, t_shape *shapes, t_scene *scene);
void			get_surface_data(t_ray *ray,
				t_vec3f center, t_vec2f *tex);
void			render(t_scene *scene, t_shape *shapes);


#endif
