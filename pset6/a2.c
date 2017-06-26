/* 
Dominik Hillmann 
Uebung: OS/7
Aufgabe: 2
*/
#include <stdio.h>
#include <stdlib.h>
#include "prim.h"

const int MAX_K = 168;

unsigned int primzahl(unsigned int k)
{
  if ((k > 0) && (k <= MAX_K))
  {
    return primzahlen[k-1]; // nimmt sich Zahl aus Auflistung in prim.h
  }
  else
  {
    printf("%d ist nicht im gueltigen Bereich (1 <= k <= %d)",k,MAX_K);
    return -1; // ungueltiger Wert
  }
}

// findet und printet alle Goldbach-Primzahlkombination im Intervall [a,b]
// getroffene Annahmen: 2 < a < b, b <= 168
void goldbach(unsigned int a, unsigned int b)
{
  // Parameter aendern, falls nicht gerade
  if((a % 2) != 0)
  {
    a += 1;
  }

  if((b % 2) != 0)
  {
    b -= 1;
  }

  // Schleife und if-statement gehen durch alle geraden Zahlen im Intervall [a,b]
  for(int intervZahl = a; intervZahl <= b; intervZahl++)
  {
    if((intervZahl % 2) == 0)
    {
      // Schleife setzt den ersten Summanden der beiden Primzahlen (als Index für Primzahl-Funktion)
      for(int summand1 = 1; summand1 <= MAX_K; summand1++)
      {
	// Schleife setzt zweiten Summanden (als Index für Primzahl-Funktion)
	for(int summand2 = 1; summand2 <= MAX_K; summand2++)
	{
	  // zweiter Teil nach &&: damit keine Dopplungen wie z.B. "10=3+7" und "10=7+3" entstehen
	  if(((primzahl(summand1) + primzahl(summand2)) == intervZahl) && (primzahl(summand1) <= primzahl(summand2))) 
	  {
	    printf("%d = %d + %d\n", intervZahl, primzahl(summand1), primzahl(summand2));
	  }
	}
      }
      
    }
    else
    {
      continue;
    }
    
  }
}

int main()
{
  goldbach(4, 10);
  printf("\n");
  goldbach(167, 169);
  
  return EXIT_SUCCESS;
}
