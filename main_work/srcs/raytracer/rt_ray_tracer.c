/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray_tracer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:14:53 by ccartet           #+#    #+#             */
/*   Updated: 2022/09/07 09:30:45 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

void	rt_put_pixel(float x, float y, t_color color, t_mlx_data *mlx)
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

//Création d'un rayon tracé depuis la caméra vers le viewplane
t_ray	rt_create_ray(t_camera cam, float w, float h)
{
	t_ray		ray;
	t_matrix	rot;

	ray.origin = *cam.pos;
	ray.dir.x = w - WIDTH * 0.5;
	ray.dir.y = HEIGHT * 0.5 - h;
	ray.dir.z = cam.focal;
	if (!check_rotation_cam(&ray, cam))
	{
		rot = rt_matrix_rotate(*cam.dir);
		ray.dir = rt_multiply_matrix_vector(rot, ray.dir);
	}
	//dprintf(2, "new_z:%.2f, %.2f, %.2f\n", ray.dir.x, ray.dir.y, ray.dir.z);
	rt_norm_vector(&ray.dir);
	ray.inter = 0;
	ray.in_obj = 0;
	ray.hit.time = -1;
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
				color = rt_color_bkg();
			rt_put_pixel(pxl_w, pxl_h, color, master->mlx);
			pxl_w++;
		}
		pxl_h++;
	}
}
