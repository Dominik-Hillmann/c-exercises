//Dominik Hillmann
// Programmierkurs C, Uebung 6, Aufgabe 2
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Aufgabenteil (a) */
// a0 wird abwechselnd negativ gemacht
// und abwechseld wird zum positiven Wert 1 addiert
void f1 (int a0, int n)
{
  for(int i = 1; i <= n; ++i)
  {
    printf("%d ", a0);
    if(!(i % 2) == 0)
    {
      a0 = a0 * -1;
    }
    else
    {
      a0 = abs(a0) + 1;
    }
  }
  printf("\n");
}


/* Aufgabenteil (b) */
// Mit jeder Iteration wird das Ergebnis zur 6 addiert, welche sich mit jeder Interation verdoppelt
void f2 (int a0, int n)
{
  int doppler = 6;
  
  for(int i = 1; i <=n; ++i)
  {
    printf("%d ", a0);
    a0 += doppler;
    doppler *= 2;
  }
  printf("\n");
}

/* Aufgabenteil (c) */
// abwechselnd wird zu a0 3 addiert oder 1 abgezogen
void f3 (int a0, int n)
{
  for(int i = 1; i <= n; ++i)
  {
    printf("%d ", a0);    
    if((i % 2) == 0)
    {
      a0 += -1;
    }
    else
    {
      a0 += 3;
    }
  }
  printf("\n");
}


/* Aufgabenteil (d) */
// Der Anfangswert wird zu einem Vielfache von 2 addiert
// Das Vielfache wird in jeder "Runde" mit 2 multipliziert, angefangen mit 1
void f4 (int a0,int n)
{
  int doppler = 1;
  
  for(int i = 0; i <= n; ++i)
  {
    printf("%d ", a0);
    a0 += doppler;
    doppler *= 2;
  }
  printf("\n");
}


int main()
{
  printf(" ************  (a) ************ \n");
  f1(3,9);
  printf(" ************  (b) ************ \n");
  f2(5,9);
  printf(" ************  (c) ************ \n");
  f3(12,9);
  printf(" ************  (d) ************ \n");
  f4(3,9);
  
  return EXIT_SUCCESS;
}
