#include <mini_rt.h>

/*bool	hit_plane(t_ray *ray, t_object *pl)
{
	float	d;
	float	distance;

	d = -(dot_product(*pl->dir, *pl->pos));
	distance = -(dot_product(*pl->dir, ray->origin) + d) 
		/ dot_product(*pl->dir, ray->dir);
	if (distance <= 0)
		return (0);
	if (ray->distance == 0.0 || distance < ray->distance)
		ray->distance = distance;
	else
		return (0);
	ray->hit.x = ray->origin.x + ray->dir.x * distance;
	if ()
	ray->hit.y = ray->origin.y + ray->dir.y * distance;
	ray->hit.z = ray->origin.z + ray->dir.z * distance;
	return (1);
}*/

bool	hit_sphere(t_ray *ray, t_object *sp)
{
	t_coord	to_center;
	float	distance;
	float	opposit;
	float	radius;

	radius = sp->diameter * 0.5;
	to_center = find_vector(ray->origin, *sp->pos);
	distance = dot_product(to_center, ray->dir);
	opposit = vector_lenght(to_center) * vector_lenght(to_center) - distance * distance;
	if (opposit < (radius * radius))
	{
		dprintf(2, "blop");
		ray->color = *sp->rgb;
		return (1);
	}
	return (0);
}
