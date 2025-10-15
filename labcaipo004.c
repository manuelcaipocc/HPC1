#include <stdio.h>
int main()
{
	double x[4]={1,2,3,4};
	double *p=&x[0];
	double *y=&x[0];
	double *g=&x[0];
	
	printf("Value origin *p %f\n",*p);
	
	//modifica el valor apuntado por p
	*p =*p+10;
	//modifica la direccion del puntero lo mueve a otro elemento
	g = g+1;
	//accede a dos posiciones adelante sin mover el puntero
	//*(y+2);
	
	printf("Value added:		 %f\n",*p);
	printf("value pointer modified:	 %f\n",*g);
	printf("value using pointer:	 %f\n",*(y+2));	
}

