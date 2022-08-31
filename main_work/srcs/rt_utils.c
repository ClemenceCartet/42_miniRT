#include <mini_rt.h>

void	rt_min_first(float *t1, float *t2)
{
	float	ret;

	if (t1 > t2)
	{
		ret = *t1;
		*t1 = *t2;
		*t2 = ret;
	}
}
