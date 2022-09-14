/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray_tracer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:14:53 by ccartet           #+#    #+#             */
/*   Updated: 2022/09/14 15:21:32 by ccartet          ###   ########.fr       */
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

bool	check_rotation_cam(t_ray *ray, t_camera cam)
{
	if (cam.dir->x == 0.0 && cam.dir->y == 0.0)
	{
		if (cam.dir->z < 0.0)
		{
			ray->dir.x = -ray->dir.x;
			ray->dir.y = ray->dir.y;
			ray->dir.z = -ray->dir.z;
		}
		return (1);
	}
	return (0);
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
	if (!check_rotation_cam(&ray, cam)) // enlever cette condition ?
		ray.dir = rt_multiply_matrix_vector(cam.rotate, ray.dir);
	ray.inter = 0;
	ray.in_obj = 0;
	ray.hit.time = -1;
	ray.hit.cy_plane = 0;
	rt_norm_vector(&ray.dir);
	return (ray);
}

void	rt_ray_tracer(t_master *master)
{
	t_ray	ray;
	int		pxl_w;
	int		pxl_h;
	t_color	color;

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
				color = rt_create_color( 0.0, 0.0, 0.0);
			rt_put_pixel(pxl_w, pxl_h, color, master->mlx);
			pxl_w++;
		}
		pxl_h++;
	}
}
