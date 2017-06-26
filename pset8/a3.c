// Dominik Hillmann
// Matrikelnr.: 1513306
// Uebung 9, Aufgabe 3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Hilfsfunktion fuer random int zwischen 1 und 9
int randInt()
{
   return (rand() % 9) + 1;
}

// ein Einmal-Eins-Spiel
void einmaleins()
{
   unsigned int n, a, b, erg;
   unsigned int counter = 0;
   printf("Wieviele Aufgaben: ");
   scanf("%i", &n);

   for(int i = 0; i < n; i++)
   {
      a = randInt();
      b = randInt();
      printf("%i * %i = ", a, b);
      scanf("%i", &erg);
    
      if(erg == (a * b))
      {
         printf("Richtig!\n");
         counter++;
      }
      else
      {
         printf("Falsch!\n");
      }
   }
   printf("%i von %i Richtige.\n", counter, n);
}


int main()
{
   srand(time(NULL));
   einmaleins();
  
   return EXIT_SUCCESS;
}
