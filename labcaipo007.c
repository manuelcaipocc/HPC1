#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void init_vector(size_t len, double* v, ptrdiff_t incr)
{
	for (size_t i=0;i<len;i++)
	{
		v[i+incr]=i+1;
	}
}

double sum(size_t len, double *x, ptrdiff_t incr)
{
	double result =0;
	for (size_t i=0; i<len;i++)
	{
		result += x[i*incr];
	}
	return result;
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
printf("vector lenght: ");

size_t len;
if (scanf("%zu",&len) !=1) return 1;
printf("\nOk, vector lenght = %zu\n",len);
double* vector = (double*) malloc(sizeof(double)*len);
if (!vector)
	{
		printf("unable to allocate heap memoriy for %zu double values\n",len);
	return 1;
	}


init_vector(len,vector,1);
printf("sum =%lg\n", sum(len,vector,1));
print_vector(vector,len,1);
free(vector);
}
