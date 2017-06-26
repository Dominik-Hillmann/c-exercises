// Dominik Hillmann
// Matrikelnr. 1513306
// Uebung 9, Aufgabe 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// gibt Kette aus, die mit > beginnt, danach abwechselnd - und *, und mit * endet
void f1(int n)
{
   // Zuerst Speicherbereich von n+1 Zeichen
   char *pChar = calloc((n + 1), sizeof(char));
  
   *pChar = '>';
   *(pChar + (n - 1)) = '<';
   for(int i = 1; i < (n - 1); i++)
   {
      if((i % 2) == 0)
      {
         *(pChar + i) = '*';
      }
      else
      {
         *(pChar + i) = '-';
      }
   }
  
   // ausgeben
   for(int i = 0; i < n; i++)
   {
      printf("%c", *(pChar + i));
   }
   printf("\n");
  
   // freigeben
   free(pChar);
}


// gibt String solange wiederholt aus, bis n characters ausgefuellt sind
void f2(int n, const char* text)
{
   // einspeichern
   unsigned int laenge = strlen(text);
   char *pStart = calloc((n + 1), sizeof(char));

   for(int i = 0; i < n; i++)
   {
      *(pStart + i) = *(text + (i % laenge));
   }

   // ausgeben
   for(int i = 0; i < n; i++)
   {
      printf("%c", *(pStart + i));
   }
   printf("\n");

   // freigeben
   free(pStart);
}


// gibt Muster aus - und > aus
void f3(int n)
{
   // speichern
   char *pStart = calloc((n + 1), sizeof(char));

   int filled = 0; // zaehlt genutzte Speicherplaetze
   int striche = 1; // zaehlt Striche
   while(filled < n)
   {
      for(int i = 0; i < striche; i++)
      {
         *(pStart + filled) = '-';
         filled++;
      }
      *(pStart + filled) = '>';
      filled++;
      striche++;
   }   

   // ausgeben
   for(int i = 0; i < n; i++)
   {
      printf("%c", *(pStart + i)); 
   }
   printf("\n");

   // freigeben
   free(pStart);
}

int main()
{
  f1(25);
  f2(50, "Test");
  f3(50);
  f2(100,"Test");
  f3(100);
  
  return EXIT_SUCCESS;
}
