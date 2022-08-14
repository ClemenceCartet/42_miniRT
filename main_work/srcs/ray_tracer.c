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

t_color	ray_color(t_coord ray)
{
	t_color	color;
	float			t;

	t = 255 * ray.z - 128;
	color.r = t * 0.5;
	color.g = t * 0.7;
	color.b = t * 1.0;
	return (color);
}

t_ray	create_ray(t_camera cam, float w, float h)
{
	t_ray	new;

	new.origin = *cam.pos;
	new.dir.x = (w - W * 0.5) * cam.ratio_H;
	new.dir.y = -1;
	new.dir.z = (H * 0.5 - h) * cam.ratio_V;
	norm_vector(cam.dir);
	// ajouter rotation de la caméra
	norm_vector(&new.dir);
	return (new);
}

void	ray_tracer(t_master *master)
{
	//t_coord	i_tmp;
	t_ray		ray;
	t_color	color;
	int			h;
	int			w;

	h = 0;
	while (h < H)
	{	
		w = 0;
		while (w < W)
		{
			ray = create_ray(*master->camera, w, h);
			if (hit_sphere(&ray, master->obj_data->lst->content))
				color = ray.color;
			//hit_pl(&ray, master->obj_data->lst->content);
			else
				color = ray_color(ray.dir);
			mlx_put_pixel(w, h, color, master->mlx);
			w++;
		}	
		h++;
	}
	//dprintf(2, "%d, %d, %d\n", color.r, color.g, color.b);
	//parcourir la liste chainée, tous les objets
	//si la distance entre la caméra et le point d'intersection est plus petite que la précédente changer i 
	//i_tmp = find_hit_test(master->camera, master->obj_data->lst->content);
}
