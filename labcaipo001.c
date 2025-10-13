#include <stdio.h>
#include <stdlib.h>
int main()
{
  double x[8];
  for (size_t i =0;
     i<8;
     ++i)
     {
     x[i]=42;
    printf("print test\n");
    if (i==0)
     {
         printf("First assignment\n");
     }
     }
}

