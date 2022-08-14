#include <mini_rt.h>

void	set_hit_point(t_ray *ray)
{	
	ray->hit.x = ray->origin.x + ray->dir.x * ray->time;
	ray->hit.y = ray->origin.y + ray->dir.y * ray->time;
	ray->hit.z = ray->origin.z + ray->dir.z * ray->time;
}

bool	hit_plane(t_ray *ray, t_object *pl)
{
	float	d;
	float	distance;

	d = -(dot_product(*pl->dir, *pl->pos));
	distance = -(dot_product(*pl->dir, ray->origin) + d) 
		/ dot_product(*pl->dir, ray->dir);
	if (distance <= 0)
		return (0);
	if (ray->time == 0.0 || distance < ray->time)
		ray->time = distance;
	else
		return (0);
	set_hit_point(ray);
	return (1);
}

bool	hit_sphere(t_ray *ray, t_object *sp)
{
	t_coord	to_center;
	float	a;
	float	b;
	float	c;
	float	discriminant;
	float	time[3];

	to_center = find_vector(ray->origin, *sp->pos);
	a = vector_lenght_squared(ray->dir);
	b = 2 * dot_product(to_center, ray->dir);
	c = vector_lenght_squared(to_center) - sp->radius * sp->radius;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0.0)
		return (0);
	time[0] = (-b + sqrt(discriminant)) / 2 * a; // pas trop compris ce calcul...
	time[1] = (-b - sqrt(discriminant)) / 2 * a;
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
	ray->color = *sp->rgb;
	ray->object_id = SP;
	return (1);
}
