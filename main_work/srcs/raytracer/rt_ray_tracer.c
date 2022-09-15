/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray_tracer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:14:53 by ccartet           #+#    #+#             */
/*   Updated: 2022/09/15 14:16:45 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

void	rt_put_pixel(int x, int y, t_color color, t_mlx_data *mlx)
{
	int	i;

	i = (y * mlx->line_length) + (x * (mlx->bpp / 8));
	mlx->addr[i++] = color.b * 255;
	mlx->addr[i++] = color.g * 255;
	mlx->addr[i++] = color.r * 255;
}

t_ray	rt_create_ray(t_camera cam, float w, float h)
{
	t_ray		ray;

	ft_memset(&ray, 0, sizeof(t_ray));
	ray.origin = *cam.pos;
	ray.dir.x = WIDTH * 0.5 - w;
	ray.dir.y = HEIGHT * 0.5 - h;
	ray.dir.z = cam.focal;
	rt_norm_vector(&ray.dir);
	ray.dir = rt_multiply_matrix_vector(cam.rotate, ray.dir);
	ray.inter = 0;
	ray.in_obj = 0;
	ray.hit.time = -1;
	ray.hit.cy_plane = 0;
	rt_norm_vector(&ray.dir);
	return (ray);
}

void	rt_set_new_rotate(t_master *master)
{
	t_matrix	newm_y;
	t_matrix	newm_x;

	newm_y = rt_matrix_rot_x(-asin(master->camera->dir->y));
	newm_x = rt_matrix_rot_y(atan2(master->camera->dir->x,
				master->camera->dir->z));
	master->camera->rotate = rt_multiply_matrix(newm_y, newm_x);
}

void	rt_ray_tracer(t_master *master, int pxl_w, int pxl_h)
{
	static int	first = 0;
	t_ray		ray;
	t_color		color;

	if (first)
		rt_set_new_rotate(master);
	pxl_h = 0;
	while (pxl_h < HEIGHT)
	{
		pxl_w = 0;
		while (pxl_w < WIDTH)
		{
			ray = rt_create_ray(*master->camera, pxl_w, pxl_h);
			rt_intersect(master->obj_data, &ray);
			if (ray.inter)
				color = rt_set_color(ray.hit, master);
			else
				color = rt_skybox_color(*master->ambient, ray.dir);
			rt_put_pixel(pxl_w, pxl_h, color, master->mlx);
			pxl_w++;
		}
		pxl_h++;
	}
	first = 1;
}
