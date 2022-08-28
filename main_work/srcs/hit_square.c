#include <mini_rt.h>

void	init_square(t_object *sq)
{
	t_coord x;
	t_coord	U;
	t_coord	V;

	x.x = 1.0;
	x.y = 0.0;
	x.z = 0.0;
	// trouver les deux autres vecteurs perpendiculaires à sq->dir
	U = rt_cross_vec(*sq->dir, x);
	if (!vector_length_squared(U))
		U.y = 1.0;
	V = rt_cross_vec(U, *sq->dir);
	// modifier les vecteurs à la taille souhaitée
	U = rt_scale_vec(U, 2);
 	V = rt_scale_vec(V, 4);
	// trouver les 4 coins du rectangle
	sq->c[0] = rt_add_vec(rt_add_vec(*sq->pos, U), V);
 	sq->c[1] = rt_sub_vec(rt_add_vec(*sq->pos, U), V);
	sq->c[2] = rt_add_vec(rt_sub_vec(*sq->pos, U), V);
	sq->c[3] = rt_sub_vec(rt_sub_vec(*sq->pos, U), V);
	// mesurer les 4 côtés du rectangle
	sq->gap[0] = rt_sub_vec(sq->c[0], sq->c[1]);
 	sq->gap[1] = rt_sub_vec(sq->c[3], sq->c[1]);
	sq->gap[2] = rt_sub_vec(sq->c[2], sq->c[0]);
	sq->gap[3] = rt_sub_vec(sq->c[2], sq->c[3]);
}	

bool	hit_square(t_ray *ray, t_object *sq)
{
 	float	a;
	float	b;
 	float	time;

 	a = rt_dot_prod(*sq->dir, ray->dir);
 	b = rt_dot_prod(*sq->dir, rt_sub_vec(*sq->pos, ray->origin));
	time = b / a; 
	if (time <= 0.0)
 		return (0);
 	if (ray->time == 0.0 || time < ray->time)
		ray->time = time;
	else
 		return (0);
 	set_hit_point(ray);
	if (!is_in_square(ray->hit, sq))
		return (0);
 	ray->color = *sq->rgb;
 	ray->object_id = SQ;
 	return (1);
}

bool	is_in_square(t_coord p, t_object *sq)
{
	t_coord	g[4];

	// trouver la distance entre notre point et chacun des coins du rectangle
	g[0] = rt_sub_vec(sq->c[0], p);
 	g[1] = rt_sub_vec(p, sq->c[1]);
	g[2] = rt_sub_vec(sq->c[2], p);
	g[3] = rt_sub_vec(p, sq->c[3]);
	// trouver la normale de ces deux vecteurs de distance et la comparer avec la normale du rectangle
	if (rt_dot_prod(*sq->dir, rt_cross_vec(sq->gap[0], g[0])) >= 0
		&& rt_dot_prod(*sq->dir, rt_cross_vec(sq->gap[1], g[1])) >= 0
		&& rt_dot_prod(*sq->dir, rt_cross_vec(sq->gap[2], g[2])) >= 0
		&& rt_dot_prod(*sq->dir, rt_cross_vec(sq->gap[3], g[3])) >= 0)
		return (1);
	return (0);
}
