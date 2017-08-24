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
}				t_shape;
typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
}				t_mlx;
typedef struct	s_scene
{
	float		width;
	float		height;
	float			x[4][4];
	t_mlx		mlx;
	float		fov;
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

#endif
