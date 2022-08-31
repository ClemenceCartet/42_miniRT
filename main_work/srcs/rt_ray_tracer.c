/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:14:53 by ccartet           #+#    #+#             */
/*   Updated: 2022/08/28 14:51:59 by ccartet          ###   ########.fr       */
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
	// t_coord	test;

	// test.x = 0;
	// test.y = 0;
	// test.z = 1;
	new.origin = *cam.pos;
	new.dir.x = w - W * 0.5;
	new.dir.y = H * 0.5 - h; 
	new.dir.z = cam.focal;
	// rotate_y(cam.dir, 1);
	rt_norm_vector(&new.dir);
	// new.dir = rt_add_vec(new.dir, *cam.dir);
	// new.dir = rt_sub_vec(new.dir, test);
	// norm_vector(&new.dir);
	new.color = rt_init_ray_color();
	new.time = 0.0;
	new.object_id = 0;
	return (new);
}

bool	rt_intersect(t_obj_data *obj_data, t_ray *ray)
{
	size_t	n;
	int 	i;
	bool	(*fctHit[3])(t_ray*, t_object*);
	int		ret;

	ret = 0;
	fctHit[0] = &rt_hit_sphere;
	fctHit[1] = &rt_hit_plane;
	fctHit[2] = &rt_hit_cylinder;
	n = 0;
	while (n < obj_data->lst_size)
	{
		i = 1;
		while (i <= 3)
		{
			if (i == obj_data->objects[n]->id)
				if ((*fctHit[i - 1])(ray, obj_data->objects[n]))
					ret = 1;
			i++;
		}
		n++;
	}
	return (ret);
}	

void	rt_ray_tracer(t_master *master)
{
	t_ray	ray;
	int		h;
	int		w;
	//size_t	n;

	/*n = 0;
	while (n < master->obj_data->lst_size)
	{
		if (master->obj_data->objects[n]->id == 2)
		init_square(master->obj_data->objects[n]);
		n++;
	}*/
	h = 0;
	while (h < H)
	{	
		w = 0;
		while (w < W)
		{
			ray = rt_create_ray(*master->camera, w, h);
			if (rt_intersect(master->obj_data, &ray))
				ray.color = rt_set_color(ray, master);
			rt_put_pixel(w, h, ray.color, master->mlx);
			w++;
		}	
		h++;
	}
}
