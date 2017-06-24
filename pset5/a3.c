// Dominik Hillmann
// Programmierkurs C, Uebung 6, Aufgabe 3
#include <stdio.h>
#include <stdlib.h>

void zahlen()
{
  int mengePrinted = 0;
  int zahl = 0;

  while(mengePrinted < 100)
  {
    if(!((zahl % 2 == 0) || (zahl % 3 == 0) || (zahl % 5 == 0)))
    {
      if(zahl < 10)
      {
	printf("  %d ", zahl);
      }
      else if(zahl < 100)
      {
	printf(" %d ", zahl);
      }
      else
      {
	printf("%d ", zahl);
      }
      
      mengePrinted += 1;
      zahl += 1;

      if((mengePrinted % 10) == 0)
      {
	printf("\n");
      }
      
    }
    else
    {
      zahl += 1;  
    }
  }
  return 1; // void, es muss irgendwas zurueckgegeben werden
}

int main()
{
  zahlen(); // Zum Testen Kommentar entfernen
  return EXIT_SUCCESS;
}
