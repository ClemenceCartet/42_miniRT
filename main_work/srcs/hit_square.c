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
	U = cross_vectors(*sq->dir, x);
	if (!vector_length_squared(U))
		U.y = 1.0;
	V = cross_vectors(U, *sq->dir);
	// modifier les vecteurs à la taille souhaitée
	U = scale_vectors_bis(U, 2);
 	V = scale_vectors_bis(V, 4);
	// trouver les 4 coins du rectangle
	sq->c[0] = add_vectors(add_vectors(*sq->pos, U), V);
 	sq->c[1] = find_vector(V, add_vectors(*sq->pos, U));
	sq->c[2] = add_vectors(find_vector(U, *sq->pos), V);
	sq->c[3] = find_vector(V, find_vector(U, *sq->pos));
	// mesurer les 4 côtés du rectangle
	sq->gap[0] = find_vector(sq->c[1], sq->c[0]);
 	sq->gap[1] = find_vector(sq->c[1], sq->c[3]);
	sq->gap[2] = find_vector(sq->c[0], sq->c[2]);
	sq->gap[3] = find_vector(sq->c[3], sq->c[2]);
}	

bool	hit_square(t_ray *ray, t_object *sq)
{
 	float	a;
	float	b;
 	float	time;

 	a = dot_product(*sq->dir, ray->dir);
 	b = dot_product(*sq->dir, find_vector(ray->origin, *sq->pos));
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
	g[0] = find_vector(p, sq->c[0]);
 	g[1] = find_vector(sq->c[1], p);
	g[2] = find_vector(p, sq->c[2]);
	g[3] = find_vector(sq->c[3], p);
	// trouver la normale de ces deux vecteurs de distance et la comparer avec la normale du rectangle
	if (dot_product(*sq->dir, cross_vectors(sq->gap[0], g[0])) >= 0
		&& dot_product(*sq->dir, cross_vectors(sq->gap[1], g[1])) >= 0
		&& dot_product(*sq->dir, cross_vectors(sq->gap[2], g[2])) >= 0
		&& dot_product(*sq->dir, cross_vectors(sq->gap[3], g[3])) >= 0)
		return (1);
	return (0);
}
