/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray_tracer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:14:53 by ccartet           #+#    #+#             */
/*   Updated: 2022/09/03 13:41:49 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

void	rt_put_pixel(float x, float y, t_color color, t_mlx_data *mlx)
{
	int	i;

	i = (y * mlx->line_length) + (x * (mlx->bpp / 8)); // sert à cacluler le memory offset
	mlx->addr[i++] = color.b * 255;
	mlx->addr[i++] = color.g * 255;
	mlx->addr[i++] = color.r * 255;
}

//Création d'un rayon tracé depuis la caméra vers le viewplane
t_ray	rt_create_ray(t_camera cam, float w, float h)
{
	t_ray	ray;

	ray.origin = *cam.pos;
	ray.dir.x = w - WIDTH * 0.5;
	ray.dir.y = HEIGHT * 0.5 - h;
	ray.dir.z = cam.focal;
	rt_norm_vector(&ray.dir);
	ray.inter = 0;
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
			pxl_w++;
		}
		pxl_h++;
	}
}
