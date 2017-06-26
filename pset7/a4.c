// Dominik Hillmann
// Matrikelnr.:1513306
// Uebung 8, Aufgabe 4

#include <stdio.h>
#include <stdlib.h>

void f1()
{
  int x = 0;
  int *px = &x;
  int **ppx = &px;

  printf("x = %i, Adresse von x: %p\n", x, &x);
  printf("px = %p, Adresse von px: %p\n", px, &px);
  printf("ppx = %p, Adresse von ppx: %p\n", ppx, &ppx); 
}


void f2()
{
  int x = 0;
  
  int *px;
  px = malloc(sizeof(int));
  *px = x;

  int **ppx;
  ppx = malloc(sizeof(int*));

  printf("x = %i, Adresse von x: %p\n", x, &x);
  printf("px = %p, Adresse von px: %p\n", px, &px);
  printf("ppx = %p, Adresse von ppx: %p\n", ppx, &ppx);   
}

int main()
{
  f1();
  printf("\n");
  f2();
  
  return EXIT_SUCCESS;
}
