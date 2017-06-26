#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main() {
   bool done = false;
   int j=0;
   int n = 1e8;

   while (!done) {
      int* a = (int*)malloc(n * sizeof(int));

      for (int i=0; i < n; i++)
         a[i] = i;

      printf("%d\n", j++);
    }

   return 0;
}
