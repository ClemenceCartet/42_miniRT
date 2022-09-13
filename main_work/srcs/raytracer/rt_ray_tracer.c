/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray_tracer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:14:53 by ccartet           #+#    #+#             */
/*   Updated: 2022/09/13 14:53:04 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

t_color	ft_skybox_color(t_ambient amb, t_coord v)
{
	t_color	color;

	ft_memset(&color, 0, sizeof(t_color));
	if (fabs(v.x) >= fabs(v.y) && fabs(v.x) >= fabs(v.z))
		color.r = ((v.x + 1) / 2.0) * amb.rgb->r
			* amb.ratio;
	if (fabs(v.y) >= fabs(v.x) && fabs(v.y) >= fabs(v.z))
		color.g = ((v.y + 1) / 2.0) * amb.rgb->g
			* amb.ratio;
	if (fabs(v.z) >= fabs(v.x) && fabs(v.z) >= fabs(v.y))
		color.b = ((v.z + 1) / 2.0) * amb.rgb->b
			* amb.ratio;
	return (color);
}

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
		if (w == 50 && h == 50)
			dprintf(2, "%.2f, %.2f, %.2f\n", ray.dir.x, ray.dir.y, ray.dir.z);
	}
	rt_norm_vector(&ray.dir);
	//dprintf(2, "new_z:%.2f, %.2f, %.2f\n", ray.dir.x, ray.dir.y, ray.dir.z);
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
	master->camera->m_y = rt_matrix_rot_x(asin(master->camera->dir->y));
	master->camera->m_x = rt_matrix_rot_y(asin(master->camera->dir->x));
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
