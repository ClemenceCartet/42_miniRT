#include <mini_rt.h>

float	vector_lenght(t_coord v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

float	vector_lenght_squared(t_coord v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

void	norm_vector(t_coord *v)
{
	float	lenght;

	lenght = vector_lenght(*v);
	v->x = v->x / lenght;
	v->y = v->y / lenght;
	v->z = v->z / lenght;
}
// normaliser un vecteur, c'est lui donner une magnitude de 1
// attention à la division par 0

t_coord	create_vector(float x, float y, float z)
{
	t_coord	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}
