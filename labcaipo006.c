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
	init_vector(&g[0],8,1);
	print_vector(&g[0],8,1);

	init_vector(&g[0],4,1);
	init_vector(&g[4],4,1);

	print_vector(&g[0],4,1);
	print_vector(&g[4],4,1);
}
