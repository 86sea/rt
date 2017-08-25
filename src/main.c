/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 11:17:49 by syoung            #+#    #+#             */
/*   Updated: 2017/08/24 11:49:41 by syoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_matrix(t_scene *scene)
{
	scene->x[0][0] = 0.707107; 
	scene->x[0][1] = -0.331295;
	scene->x[0][2] = 0.624695;
	scene->x[0][3] = 0;
	scene->x[1][0] = 0;
	scene->x[1][1] = 0.883452;
	scene->x[1][2] = 0.468521;
	scene->x[1][3] = 0;
	scene->x[2][0] = -0.707107;
	scene->x[2][1] = -0.331295;
	scene->x[2][2] = 0.624695;
	scene->x[2][3] = 0;
	scene->x[3][0] = 0;
	scene->x[3][1] = 0;
	scene->x[3][2] = -6.404043;
	scene->x[3][3] = 1;
	scene->n = 3;
}

static void		init_mlx(t_scene *scene)
{
	scene->mlx.mlx = mlx_init();
	scene->mlx.win = mlx_new_window(scene->mlx.mlx, WIDTH, HEIGHT, "RT");
}
static void vec_init(t_vec3f *v, float x, float y, float z)
{
	v->vec[0] = x;
	v->vec[1] = y;
	v->vec[2] = z;
}
int		main(void)
{
	t_scene scene;
	t_shape *shapes;
	t_vec3f color;

	color.vec[0] = 50;
	color.vec[1] = 50;
	color.vec[1] = 50;
	scene.width = 640;
	scene.height = 480;
	scene.fov = 51.52;
	scene.img_aspect_ratio = HEIGHT / WIDTH;
	init_matrix(&scene);
	shapes = (t_shape *)malloc(sizeof(t_shape) * 3);
	vec_init(&shapes[0].shape.sphere.center, 0.1, 0.1, 0.1);
	shapes[0].shape.sphere.radius = 0.2;
	shapes[0].color = color;
	shapes[0].shapeid = sphere;
	vec_init(&shapes[1].shape.sphere.center, 0.2, 0.4, 0.2);
	shapes[1].shape.sphere.radius = 0.1;
	shapes[1].color = color;
	shapes[1].shapeid = sphere;
	vec_init(&shapes[2].shape.sphere.center, 0.1, 0.6, 0.3);
	shapes[2].shape.sphere.radius = 0.1;
	shapes[2].color = color;
	shapes[2].shapeid = sphere;
	
	render(&scene, shapes);
	mlx_loop(scene.mlx.mlx);
}
