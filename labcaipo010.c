#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>
#include <unistd.h>

/* return real time in seconds since start of the process */
double walltime() {
   static clock_t ticks_per_second = 0;
   if (!ticks_per_second) {
      ticks_per_second = sysconf(_SC_CLK_TCK);
   }
   struct tms timebuf;
   /* times returns the number of real time ticks passed since start */
   return (double) times(&timebuf) / ticks_per_second;
}

void init_vector(size_t len, double* v, ptrdiff_t incr) {
   for (size_t i = 0; i < len; ++i) {
      v[i*incr] = i + 1;
   }
}

#define MAX_LEN 134217728

int main() {
   printf("     len t1 (separate) t2 (interleaving)      t2/t1\n");
   for (size_t len = 8192; len <= MAX_LEN/2; len *= 2) {
      printf("%8zu", len);

      /* separate vectors */
      double* vector1 = malloc(sizeof(double) * len * 2);
      double* x = vector1;
      double* y = vector1 + len;
      double t0 = walltime();
      init_vector(len, x, 1);
      init_vector(len, y, 1);
      double t1 = walltime() - t0;
      printf(" %12.2lf", t1);

      /* interleaved vectors */
      double* vector2 = malloc(sizeof(double) * len * 2);
      x = vector2; y = vector2 + 1;
      t0 = walltime();
      init_vector(len, x, 2);
      init_vector(len, y, 2);
      double t2 = walltime() - t0;
      printf(" %12.2lf %16.2lf", t2, t2/t1);
      printf("\n");

      free(vector1); free(vector2);
   }
}
