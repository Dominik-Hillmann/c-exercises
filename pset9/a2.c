// Dominik Hillmann
// Matrikelnr. 1513306
// Uebung 10, Aufgabe 2

#include <stdio.h>
#include <stdlib.h>

const int N = 8;

/* *** Teilaufgabe (a) *** */
void ausgeben(unsigned char feld[N])
{
   for(int i = 0; i < N; i++)
   {
      printf("%i ", feld[i]);
   }
   printf("\n");
}


/* *** Teilaufgabe (b) *** */
void mapZahl(unsigned char feld[N], unsigned char k)
{
   for(int i = 0; i < N; i++)
   {
      feld[i] = k % 2;
      k /= 2;
   }

   // nun die richtige Reihenfolge, also das Feld umdrehen
   int halter;
   for(int i = 0; i < ((N - 1) / 2); i++)
   {
      halter = feld[(N - 1) - i];
      feld[(N - 1) - i] =  feld[i];
      feld[i] = halter;
   }
}


/* *** Teilaufgabe (c) *** */
void rotateLeft(unsigned char feld[N])
{
   feld[N - 1] = feld[0];
   for(int i = 1; i < N - 1; i++)
   {
      feld[i - 1] = feld[i];
   }
}

void rotateRight(unsigned char feld[N])
{  
   int halter = feld[N - 1];
   for(int i = N - 2; i >= 0; i--)
   {
      feld[i + 1] = feld[i];
   }
   feld[0] = halter;
}

int main()
{
   unsigned char feld[N];

   mapZahl(feld,131);
   ausgeben(feld);
   rotateLeft(feld);
   ausgeben(feld);
   for(int i = 1; i <= 3; i++)
   {
      rotateRight(feld);
   }
   ausgeben(feld);
    
   return EXIT_SUCCESS;
}
