// Dominik Hillmann
#include <stdio.h>
#include <stdlib.h>

void printBits(unsigned int z)
{
  int n = 8 * sizeof(z);
  char* s = calloc(n+1, sizeof(char));
  for (int i=n-1;i>=0;i--)
  {
    *(s+i) = ((z%2) == 0) ? '0': '1';
    z /= 2;
  }
  for (int i=0;i<n;i++)
  {
    printf("%c",*(s+i));
    if ((i+1)%8 == 0)
    {
      printf(" ");
    }
  }
  printf("\n");
  free(s);
}

// Die Funktion gibt den Wert 1 zurück, wenn das k. Bit (von rechts) in 
// der Binärrepräsentation der Zahl n den Wert 1 hat und 0 sonst.
int checkBit(unsigned int n, int k);

// Die Funktion setzt das k. Bit (von rechts) in 
// der Binärrepräsentation der Zahl n auf den Wert 1
int setBit(unsigned int n, int k);

// Die Funktion setzt das k. Bit (von rechts) in 
// der Binärrepräsentation der Zahl n auf den Wert 0
int unsetBit(unsigned int n, int k);

// Die Funktion invertiert das k. Bit (von rechts) in 
// der Binärrepräsentation der Zahl n
int invertBit(unsigned int n, int k);



/* *** Teilaufgabe (a) *** */
int checkBit(unsigned int n, int k)
{
  return ((n & (1 << k)) == (1 << k)) ? 1 : 0;
}

/* *** Teilaufgabe (b) *** */
int setBit(unsigned int n, int k)
{
  return n | (1 << k);
}

/* *** Teilaufgabe (c) *** */
int unsetBit(unsigned int n, int k)
{
  return n & ~(1 << k);
}

/* *** Teilaufgabe (d) *** */
int invertBit(unsigned int n, int k)
{
  return n ^ (1 << k);
}


int main()
{
  unsigned int n = 261;

  printBits(n);
  n = setBit(n,3);
  printBits(n);
  n = unsetBit(n,2);
  printBits(n);
  n = invertBit(n,23);
  printBits(n);
  
  return EXIT_SUCCESS;
}
