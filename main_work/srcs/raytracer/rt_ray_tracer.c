/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray_tracer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:14:53 by ccartet           #+#    #+#             */
/*   Updated: 2022/09/13 17:22:07 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

void	rt_put_pixel(int x, int y, t_color color, t_mlx_data *mlx)
{
	int	i;

	i = (y * mlx->line_length) + (x * (mlx->bpp / 8));
	mlx->addr[i++] = ft_get_lowest((int)(color.b * 255), 255);
	mlx->addr[i++] = ft_get_lowest((int)(color.g * 255), 255);
	mlx->addr[i++] = ft_get_lowest((int)(color.r * 255), 255);
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

	ft_memset(&ray, 0, sizeof(t_ray));
	ray.origin = *cam.pos;
	ray.dir.x = WIDTH * 0.5 - w;
	ray.dir.y = HEIGHT * 0.5 - h;
	ray.dir.z = cam.focal;
	rt_norm_vector(&ray.dir);
	if (!check_rotation_cam(&ray, cam))
	{
		if (w == 50 && h == 50)
			dprintf(2, "%.2f, %.2f, %.2f\n", ray.dir.x, ray.dir.y, ray.dir.z);
		rot = rt_multiply_matrix(cam.m_y, cam.m_x);
		ray.dir = rt_multiply_matrix_vector(rot, ray.dir);
		// ray.dir = rt_multiply_matrix_vector(cam.m_y, ray.dir);
		if (w == 50 && h == 50)
			dprintf(2, "%.2f, %.2f, %.2f\n", ray.dir.x, ray.dir.y, ray.dir.z);
	}
	// rt_norm_vector(&ray.dir);
	//dprintf(2, "new_z:%.2f, %.2f, %.2f\n", ray.dir.x, ray.dir.y, ray.dir.z);
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
	master->camera->m_y = rt_matrix_rot_x(-asin(master->camera->dir->y));
	master->camera->m_x = rt_matrix_rot_y(atan2(master->camera->dir->x, master->camera->dir->z));
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
				color = ft_skybox_color(*master->ambient, ray.dir);
			rt_put_pixel(pxl_w, pxl_h, color, master->mlx);
			pxl_w++;
		}
		pxl_h++;
	}
}
