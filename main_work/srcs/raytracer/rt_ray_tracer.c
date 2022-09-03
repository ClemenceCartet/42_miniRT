/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray_tracer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:14:53 by ccartet           #+#    #+#             */
/*   Updated: 2022/09/03 10:49:38 by ljohnson         ###   ########lyon.fr   */
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

// on trace un rayon entre le pixel du viewplane et la cam
t_ray	rt_create_ray(t_camera cam, float w, float h)
{
	t_ray	new;

	new.origin = *cam.pos;
	new.dir.x = w - W * 0.5;
	new.dir.y = H * 0.5 - h;
	new.dir.z = cam.focal;
	rt_norm_vector(&new.dir);
	new.inter = 0;
	return (new);
}

void	rt_intersect(t_obj_data *obj_data, t_ray *ray)
{
	size_t		n;
	int			i;
	t_fcthit	fct[2];

	fct[0] = &rt_inter_sphere;
	fct[1] = &rt_inter_plane;
	//fct[2] = &rt_inter_cylinder;
	n = -1;
	while (++n < obj_data->lst_size)
	{
		i = 0;
		while (++i <= 2)
		{
			if (i == obj_data->objects[n]->id)
				(*fct[i - 1])(ray, obj_data->objects[n], 1);
		}
	}
}	

void	rt_ray_tracer(t_master *master)
{
	t_ray	ray;
	int		h;
	int		w;
	t_color	color;
	//size_t	n;

	/*n = 0;
	while (n < master->obj_data->lst_size)
	{
		if (master->obj_data->objects[n]->id == 2)
		init_square(master->obj_data->objects[n]);
		n++;
	}*/
	h = -1;
	while (++h < H)
	{	
		w = -1;
		while (++w < W)
		{
			ray = rt_create_ray(*master->camera, w, h);
			rt_intersect(master->obj_data, &ray);
			if (ray.inter)
				color = rt_set_color(ray.hit, master);
			else
				color = rt_color_bkg();
			rt_put_pixel(w, h, color, master->mlx);
		}	
	}
}
