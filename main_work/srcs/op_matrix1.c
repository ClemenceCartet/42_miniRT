#include <mini_rt.h>

t_matrix	mat_rot_x(float rad) // rotation up-down
{	
	t_matrix	new;

	new.x_x = 1;
	new.x_y = 0;
	new.x_z = 0;
	new.y_x = 0;
	new.y_y = cos(rad);
	new.y_z = - sin(rad);
	new.z_x = 0;
	new.z_y = sin(rad);
	new.z_z = cos(rad);
	return (new);
}

t_matrix	mat_rot_z(float rad) // rotation left-right
{	
	t_matrix	new;

	new.x_x = cos(rad);
	new.x_y = - sin(rad);
	new.x_z = 0;
	new.y_x = sin(rad);
	new.y_y = cos(rad);
	new.y_z = 0;
	new.z_x = 0;
	new.z_y = 0;
	new.z_z = 1;
	return (new);
}

t_coord	mat_x_vector(t_matrix m, t_coord v)
{	
	t_coord	new;

	new.x = m.x_x * v.x + m.x_y * v.y + m.x_z * v.z;
	new.y = m.y_x * v.x + m.y_y * v.y + m.y_z * v.z;
	new.z = m.z_x * v.x + m.z_y * v.y + m.z_z * v.z;
	return (new);
}

// matrice de translation ??
