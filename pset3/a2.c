// Dominik Hillmann
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printBool(bool b)
{
  printf("%s\n", b ? "true" : "false");
}


/* ***    Teilaufgabe (a) *** */
void println()
{
  printf("\n");
}


/* ***    Teilaufgabe (b) *** */
bool teilbar(int n, int k)
{
  return ((n % k) == 0) ? true : false;
}


/* ***    Teilaufgabe (c) *** */
bool teilbar_6(int n)
{
  return (teilbar(n, 3) && teilbar(n, 2)) ? true : false;
}


int main()
{
  /* ***    Test Teilaufgabe (d) *** */
  int k1 = 42;
  int k2 = 98;

  printf("%d ist durch 6 teilbar: ",k1);
  printBool(teilbar_6(k1));

  printf("%d ist durch 6 teilbar: ",k2);
  printBool(teilbar_6(k2));
  
  return EXIT_SUCCESS;
}
