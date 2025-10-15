#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

double sum(size_t len,double* x,ptrdiff_t incr)
    {
    double result =0;
    for (size_t i=0;i<len;++i)
       {
         	//Cada vez que sumo 1 a mi x, estos haciendo dir(x) + i * sizeof(tipo de varialbe utilizada)

		result =*(&x[0]+i*incr)+result;
	 
       }
    return result;
    }
int main()
{
    double x[8];
    //y sera una variable cuyo contenido sera una direccion de memoria donde hay un double
    double *y=&x[0];
    for (size_t i=0;i<8;++i)
    {
        x[i]=4;
	y[i]=5;
    	printf("Size of %zu ",sizeof(x[i]));
	printf("value %.f ",x[i]);
	printf("addresse %p\n",(void*)&x[i]);
    }
    double result=sum(8,&x[0],1);
    printf("Distance %td\n",(char*)(&x[1])-(char*)(&x[0]));
    printf("result %f\n",result);

    printf("Size of x %zu\n", sizeof(x));
    printf("Size of y %zu\n", sizeof(y));
    
}




