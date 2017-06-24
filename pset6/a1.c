// Dominik Hillmann
// Programmierkurs C, Übung 6, Aufgabe 1

/* Siehe a1.pdf */

#include <stdio.h>
#include <stdlib.h>


int f1(int n)
{
  int r = 0;
  int zaehler = 0;
  
  for(int i = 1; i <= n; i++) 
  {
    
    for(int j = 1; j <= i; j++) 
    {
      for(int k = i; k > 0; k--)
      {
        printf("%d  %d  %d --> %d\n", i, j, k, r);
	
	r++;
      }
    }
  }
  return r;
}


f2(int n)
{
  int r = 0;
  
  for(int i = 2; i <= n / 2; i++)
  {
    int m = n, k = i;
    
    while (m > 0) 
    {
      m -= k; 
    }
    
    if (m == 0)
    {
      r++;
    }
    printf("%d - %d = %d\n", m, k, m - k);
  }
  return r;
}

int main(){
  // Test f1
  //int m = 5;
  //f1(5);
  // Test f2
  //int n = 24;
  //printf("f2(%d) = %d\n",n,f2(n));

  return EXIT_SUCCESS;
}


/*
  n = 5
  




*/
