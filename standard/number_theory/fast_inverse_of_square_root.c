#include "stdio.h"

int main()
{
	float x=0.25f;
	float xhalf = 0.5f * x;
	int i = *(int*)&x;
	i = 0x5f3759df - (i >> 1);
	x = *(float*)&i;
	x = x*(1.5f-(xhalf*x*x));
	printf("%f\n",x);
	return 0;
}
