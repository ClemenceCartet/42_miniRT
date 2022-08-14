#include <mini_rt.h>

void	mlx_put_pixel(float x, float y, t_color color, t_mlx_data *mlx)
{
	int	i;

	i = (y * mlx->line_length) + (x * (mlx->bpp / 8));
	mlx->addr[i] = 0;
	mlx->addr[i++] = color.r;
	mlx->addr[i++] = color.g;
	mlx->addr[i++] = color.b;
}

t_color	ray_color(t_coord ray, t_coord *normal)
{
	t_color	color;
	float	t;

	if (normal == NULL)
	{
		t = 255 * ray.z - 128;
		color.r = t * 0.5;
		color.g = t * 0.7;
		color.b = t * 1.0;
	}
	else
	{
		color.r = normal->x * 255;
		color.g = normal->y * 255;
		color.b = normal->z * 255;
	}	
	return (color);
}

t_ray	create_ray(t_camera cam, float w, float h)
{
	t_ray	new;

	new.origin.x = -cam.pos->x;
	new.origin.y = cam.pos->y;
	new.origin.z = -cam.pos->z;
	new.dir.x = (w - W * 0.5) * cam.ratio_H;
	new.dir.y = -1.0;
	new.dir.z = (H * 0.5 - h) * cam.ratio_V;
	new.dir = add_vectors(new.dir, *cam.dir);
	norm_vector(&new.dir);
	new.time = 0.0;
	new.object_id = 0;
	return (new);
}

void	ray_tracer(t_master *master)
{
	t_ray	ray;
	int		h;
	int		w;	

	h = 0;
	while (h < H)
	{	
		w = 0;
		while (w < W)
		{
			ray = create_ray(*master->camera, w, h);
			if (hit_sphere(&ray, master->obj_data->lst->content))
			//if (!hit_plane(&ray, master->obj_data->lst->content))
				ray.color = ray_color(ray.dir, &ray.normal);
			else
				ray.color = ray_color(ray.dir, NULL);
			mlx_put_pixel(w, h, ray.color, master->mlx);
			w++;
		}	
		h++;
	}
}
