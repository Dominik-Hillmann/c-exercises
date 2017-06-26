// Dominik Hillmann
// Matrikelnr. 1513306
// Uebung 8, Aufgabe 2

#include <stdio.h>
#include <stdlib.h>

/* Werte von a, b und c sollen als Referenzen uebergeben werden, heisst: Adressen
 * in der Funktion soll Min in a gespeichert sein und Max in b */

void minmax(int *pa, int *pb, int *pc)
{  
  int puffer = *pa; // da das kleinste bei der ersten Abfrage in gespeichert wird
  
  if((*pa < *pb) && (*pa < *pc)) // wenn a das kleinste ist
  {
    if(*pb > *pc) // dazugehoeriges Max bestimmen
    {
      *pc = *pb;      
    }             // else nichts, da c schon am richtigen Platz
  }

  if((*pb < *pa) && (*pb < *pc)) // b kleinstes
  {
    *pa = *pb;
    if(puffer > *pc)
    {
      *pc = puffer;
    }              // else nichts, da c schon am richtigen Platz
  }

  if((*pc < *pa) && (*pc < *pb)) // wenn c das kleinste ist
  {
    *pa = *pc;
    if(*pb > puffer)
    {
      *pc = *pb;
    }
    else
    {
      *pc = puffer;
    }
  }
}








int main()
{
  int a = 33, b = 22, c = 11;
  printf("a = %d  b = %d  c = %d\n",a,b,c);
  // 1. minmax Aufruf einfuegen -->
  minmax(&a, &b, &c);  
  printf("Minimum: %d  Maximum: %d\n",a,c);

  a = 2; b = 1; c = 3;
  printf("a = %d  b = %d  c = %d\n",a,b,c);
  // 2. minmax Aufruf einfuegen -->
  minmax(&a, &b, &c);
  printf("Minimum: %d  Maximum: %d\n",a,c);

  a = -50; b = 50; c = 0;
  printf("a = %d  b = %d  c = %d\n",a,b,c);
  // 3. minmax Aufruf einfuegen -->
  minmax(&a, &b, &c);
  printf("Minimum: %d  Maximum: %d\n",a,c);

  return EXIT_SUCCESS;
}
