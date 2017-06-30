// Dominik Hillmann
// Matrikelnr. 1513306
// Uebung 10, Aufgabe 3

#include <stdio.h>
#include <stdlib.h>

/* *** Teilaufgabe (a) *** */

const int NUMROWS = 5;
const int NUMCOLS = 10;


/* *** Teilaufgabe (b) *** */

// befuellt Matrix in jeder Zeile fortlaufend mit -1, 0, 1
void fuellen(int inFeld[NUMROWS][NUMCOLS])
{
   int fueller[] = {-1, 0, 1};
   int f = 0;
  
   for(int i = 0; i < NUMROWS; i++)
   {
      for(int j = 0; j < NUMCOLS; j++)
      {
         inFeld[i][j] = fueller[f];

	 // zuruecksetzen, damit es durchlaufend befuellt wird
	 if(f >= 2)
         {
            f = 0;
         }
         else
         {
            f++;
         }
      }
   }
}


/* *** Teilaufgabe (c) *** */

// gibt eine Matrix aus
void ausgeben(int inFeld[NUMROWS][NUMCOLS])
{
   for(int i = 0; i < NUMROWS; i++)
   {
      for(int j = 0; j < NUMCOLS; j++)
      {
	 printf("%3d", inFeld[i][j]);
      }
      printf("\n");
   }
}


/* *** Teilaufgabe (d) *** */

// gibt Summen aller Zeilen und Spalten aus
void summen(int inFeld[NUMROWS][NUMCOLS])
{
   int zeilensumme;
   for(int i = 0; i < NUMROWS; i++)
   {
      zeilensumme = 0; 
      for(int j = 0; j < NUMCOLS; j++)
      {
	 zeilensumme += inFeld[i][j];
      }
      printf("Summe Zeile %i: %3i\n", i + 1, zeilensumme);
   }

   
   int spaltensumme;
   for(int j = 0; j < NUMCOLS; j++)
   {
      spaltensumme = 0;
      for(int i = 0; i < NUMROWS; i++)
      {
         spaltensumme += inFeld[i][j];
      }
      printf("Summe Spalte %i: %3i\n", j + 1, spaltensumme); 
   }
}


int main()
{
   /* *** Teilaufgabe (a) *** */

   int feld[NUMROWS][NUMCOLS];
   fuellen(feld);
   ausgeben(feld);
   summen(feld);
  
  return EXIT_SUCCESS;
}
