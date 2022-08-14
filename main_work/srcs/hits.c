#include <mini_rt.h>

void	set_hit_point(t_ray *ray)
{	
	ray->hit.x = ray->origin.x + ray->dir.x * ray->time;
	ray->hit.y = ray->origin.y + ray->dir.y * ray->time;
	ray->hit.z = ray->origin.z + ray->dir.z * ray->time;
}

bool	hit_plane(t_ray *ray, t_object *pl)
{
	float	a;
	float	b;
	float	time;

	a = dot_product(*pl->dir, ray->dir);
	b = dot_product(*pl->dir, find_vector(ray->origin, *pl->pos));
	time = b / a; 
	if (time <= 0)
		return (0);
	if (ray->time == 0.0 || time < ray->time)
		ray->time = time;
	else
		return (0);
	set_hit_point(ray);
	ray->color = *pl->rgb;
	ray->object_id = PL;
	return (1);
}

bool	hit_sphere(t_ray *ray, t_object *sp)
{
	t_coord	to_center;
	float	a;
	float	half_b;
	float	c;
	float	discriminant;
	float	time[3];

	to_center = find_vector(ray->origin, *sp->pos);
	a = vector_lenght_squared(ray->dir);
	half_b = dot_product(to_center, ray->dir);
	c = vector_lenght_squared(to_center) - sp->radius * sp->radius;
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0.0)
		return (0);
	time[0] = (-half_b + sqrt(discriminant)) * a; // pas trop compris ce calcul...
	time[1] = (-half_b - sqrt(discriminant)) * a;
	if (time[0] < time[1])
		time[2] = time[0];
	else
		time[2] = time[1];
	if (time[2] > 0.0 && ray->time == 0.0)
		ray->time = time[2];
	else if (time[2] > 0.0 && time[2] < ray->time)
		ray->time = time[2];
	else
		return (0);
	set_hit_point(ray);
	ray->normal = find_vector(*sp->pos, ray->hit);
	ray->color = *sp->rgb;
	ray->object_id = SP;
	return (1);
}
