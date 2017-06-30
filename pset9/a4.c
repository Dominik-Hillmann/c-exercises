// Dominik Hillmann
// Matrikelnr.: 1513306
// Uebung 10, Aufgabe 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* *** Aufgabenteil b *** */

// Indexoperator nutzen
void sort(char *inString)
{
   char halter;
   for(int n = (strlen(inString) - 1); n > 0; n--) // wichtig: strlen - 1, da Index ab 0 
   {
      for(int i = 0; i < n; i++)
      {
	if(inString[i] > inString[i + 1])
	 {
	     halter = inString[i + 1];
	     inString[i + 1] = inString[i];
	     inString[i] = halter;
	 }
      }
   }
}


// weil der Code sonst zwei mal in der main sein wuerde
void ausgeben(char *inString)
{
   for(int i = 0; i < strlen(inString); i++)
   {
      printf("%c", *(inString + i));
   }
   printf("\n");
}



int main(int argc, char* argv[])
{
   // Zeichen zaehlen
   unsigned int argCharCount = 0;
   for(int i = 1; i < argc; i++) // ab 1, weil Programmname nicht gezaehlt werden soll
   {
      argCharCount += strlen(*(argv + i));
   }
   
   printf("%i\n", argCharCount);


   // reinkopieren
   char *pString = calloc(argCharCount, sizeof(char)); // Speicherplatz
   int posCounter = 0;
   for(int i = 1; i < argc; i++) // fuer jedes Argument
   {
      for(int j = 0; j < strlen(*(argv + i)); j++) // fuer jeden Buchstaben
      {
	 *(pString + posCounter) = argv[i][j];
	 posCounter++;
      }
   }

   // ausgeben, siehe Funktion, da sonst mehrmals in main   
   ausgeben(pString);

   // Aufgabenteil b
   sort(pString); // nicht geschafft
   ausgeben(pString);

   // freigeben
   free(pString);
   
   return EXIT_SUCCESS;
}
