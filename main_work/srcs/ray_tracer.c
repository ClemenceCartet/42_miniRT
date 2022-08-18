#include <mini_rt.h>

void	mlx_put_pixel(float x, float y, t_color color, t_mlx_data *mlx)
{
	int	i;

	i = (y * mlx->line_length) + (x * (mlx->bpp / 8));
	mlx->addr[i++] = color.b;
	mlx->addr[i++] = color.r;
	mlx->addr[i++] = color.g;
}

t_color	ray_color(t_color *cl, t_coord *normal)
{
	t_color	color;
	// float	t;
	(void)cl;

	if (normal == NULL)
	{
		color.r = 0;
		color.g = 100;
		color.b = 160;
	}
	else
	{
		color.r = (normal->x * 255 - 128) * 0.5;
		color.g = (normal->y * 255 - 128) * 0.7;
		color.b = (normal->z * 255 - 128) * 1.0;
	}	
	return (color);
}

t_ray	create_ray(t_camera cam, float w, float h)
{
	t_ray	new;

	new.origin.x = -cam.pos->x;
	new.origin.y = cam.pos->y;
	new.origin.z = -cam.pos->z;
	new.dir.x = (W * 0.5 - w) * cam.ratio_H;
	new.dir.y = -1.0;
	new.dir.z = (h - H * 0.5) * cam.ratio_V;
	new.dir = add_vectors(new.dir, *cam.dir);
	norm_vector(&new.dir);
	new.color = ray_color(NULL, NULL);
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
	bool	(*fctHit[2])(t_ray*, t_object*);

	fctHit[0] = &hit_sphere;
	fctHit[1] = &hit_plane;
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
				while (i <= 2)
				{
					if (i == master->obj_data->objects[n]->id)
					{
						(*fctHit[i - 1])(&ray, master->obj_data->objects[n]);
							// tmp = ray_color(&ray.color, &ray.normal);
					}
					i++;
				}
				// if (!hit_plane(&ray, master->obj_data->objects[n]))
				// ray.color = ray_color(ray.dir, &ray.normal);
				n++;
			}
			mlx_put_pixel(w, h, ray.color, master->mlx);
			w++;
		}	
		h++;
	}
}
