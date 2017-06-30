#include <stdlib.h>

const int N = 1000;

int main(){
  int *pI = calloc(N,sizeof(int));

  for (int i=0;i<N;i++){
    *(pI++) = (i+1);
  }

  free(pI);

  return EXIT_SUCCESS;
}
