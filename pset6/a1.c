/*
Dominik Hillmann
Uebung: OS/7
Aufgabe: 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Aufgabenteil (a) */
// dreht die eingegebene Zahl um
unsigned int umkehr(unsigned int input)
{
  unsigned int umgedreht = 0;
  unsigned int letzteZahl = 0;
  // wird gebraucht, um zu wissen, wie gross die Zahl ist
  unsigned int inputGroesse = 1;
  unsigned int inputDummy = input;
  
  while(inputDummy > 10)
  {
    inputDummy /= 10;
    inputGroesse *= 10;
  }

  // Aufbau der umgedrehten Zahl mithilfe der drei Operationen
  for( ; inputGroesse > 0; inputGroesse /= 10)
  {
    letzteZahl = input % 10;    
    umgedreht += letzteZahl * inputGroesse;
    input /= 10;
  }
  
  return umgedreht;
}

/* Aufgabenteil (b) */

// listet alle Palindrome mit einer bestimmten Anzahl von Stellen auf
void palindromFinder(unsigned int anzahlStellen)
{
  // Feststellen der Intervallgrenzen
  unsigned int intervallStart = pow(10, anzahlStellen) / 10;
  unsigned int intervallEnde = (pow(10, anzahlStellen + 1) - 1) / 10;

  for( ; intervallStart <= intervallEnde; intervallStart++)
  {
    if(intervallStart == umkehr(intervallStart))
    {
      printf("%d ", intervallStart);
    }
  }
  printf("\n");
}



int main()
{
  int k=3;  // Anzahl der Stellen einer Zahl
  unsigned int test = 94267;
  
  /* Aufruf ergaenzen */
  printf("%d --> %d\n", test, umkehr(test));
  palindromFinder(2);
  palindromFinder(k);
  /* PROBLEM: fuer k = 5 werden die ersten im Ausschnitt aufgefuehrten Zahlen nicht gezeigt, aber
     ich konnte den Fehler nicht finden */  
  
  return EXIT_SUCCESS;
}
