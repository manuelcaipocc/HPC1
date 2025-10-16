#include <stdio.h>
#include <stddef.h>
double g[8];

void init_vector(double *p, size_t len, ptrdiff_t str) 
	{
		for (size_t i=0;i<len;i++)
		{
			p[i*str]=i+1;
		}
	}

void print_vector(double *p,size_t len,ptrdiff_t str)
	{
		printf("Vector: ");
		for (size_t i=0;i<len;i++)
		{
			printf("[%f] ",p[i*str]);
		}
		printf("\n");
	}

int main()
{
	size_t maxlen = sizeof(g)/sizeof(g[0]);

	init_vector(&g[0],maxlen,1);
	print_vector(&g[0],maxlen,1);

	printf("Using the space for two vectors");
	size_t len = maxlen/2;
	double *y=g+len;

	init_vector(&g[0],4,1);
	init_vector(y,4,1);

	printf("x= ");print_vector(&g[0],4,1);
	printf("y= ");print_vector(y,4,1);
	printf("vector= "); print_vector(g,maxlen,1);	
	y=g+1;

	init_vector(&g[0],4,2);
	init_vector(y,4,2);

	printf("x= ");print_vector(&g[0],4,2);
	printf("y= ");print_vector(y,4,2);
	printf("vector= "); print_vector(g,maxlen,1);	


	y=g+1;

}
