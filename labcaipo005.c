#include <stdio.h>
#include <stddef.h>
double sum(size_t len, double* x, ptrdiff_t incr)
{	
	double *p=x;
	double output = 0; 
	int i=0;
	while(i<len)
		{
			output=output+*p;
			p=p+incr;
			i++;	
		}
	return output;
}
int  main()
{
	double x[4]={1,2,3,4};
	double output =sum(4,&x[0],1);

	printf("output %f :\n",output);
	size_t len=sizeof(x)/sizeof(x[0]);
 	for (size_t i=0;i<len;i++)
	{
		printf(" x[%zu] value x %f\n",i,x[i]);
	}	
}

