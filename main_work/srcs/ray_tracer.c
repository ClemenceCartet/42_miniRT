/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:14:53 by ccartet           #+#    #+#             */
/*   Updated: 2022/08/25 10:49:02 by ccartet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

void	mlx_put_pixel(float x, float y, t_color color, t_mlx_data *mlx)
{
	int	i;

	i = (y * mlx->line_length) + (x * (mlx->bpp / 8)); // sert à cacluler le memory offset
	mlx->addr[i++] = color.b;
	mlx->addr[i++] = color.g;
	mlx->addr[i++] = color.r;
}

t_color	ray_color(void)
{
	t_color	color;

	color.r = 255;
	color.g = 255;
	color.b = 255;
	return (color);
}

// on trace un rayon entre le pixel du viewplane et la cam
t_ray	create_ray(t_camera cam, float w, float h)
{
	t_ray	new;
	t_coord	test;

	test.x = 0;
	test.y = 0;
	test.z = 1;
	new.origin = *cam.pos;
	new.dir.x = w - W * 0.5;
	new.dir.y = H * 0.5 - h; 
	new.dir.z = cam.focal;
	// rotate_y(cam.dir, 1);
	norm_vector(&new.dir);
	new.dir = add_vectors(new.dir, *cam.dir);
	new.dir = sub_vectors(new.dir, test);
	norm_vector(&new.dir);
	new.color = ray_color();
	new.time = 0.0;
	new.object_id = 0;
	return (new);
}

void	ray_tracer(t_master *master)
{
	t_ray	ray;
	int		h;
	int		w;
	size_t	n;
	int		i;
	bool	(*fctHit[3])(t_ray*, t_object*);

	fctHit[0] = &hit_sphere;
	fctHit[1] = &hit_plane;
	fctHit[2] = &hit_cylinder;
	h = 0;
	while (h < H)
	{	
		w = 0;
		while (w < W)
		{
			n = 0;
			ray = create_ray(*master->camera, w, h);
			while (n < master->obj_data->lst_size)
			{
				i = 1;
				while (i <= 3)
				{
					if (i == master->obj_data->objects[n]->id)
						(*fctHit[i - 1])(&ray, master->obj_data->objects[n]);
					i++;
				}
				n++;
			}
			mlx_put_pixel(w, h, ray.color, master->mlx);
			w++;
		}	
		h++;
	}
}
