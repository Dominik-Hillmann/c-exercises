// Dominik Hillmann
#include <stdio.h>
#include <stdlib.h>

int quersumme(unsigned int z);

void printBits(unsigned int z, int anzStellen);

int anzahlBits(unsigned int z);


/*  Aufgabenteil (a) */
int quersumme(unsigned int z)
{
  return (z < 10) ? z : (quersumme(z / 10) + (z % 10));
}

					   
/*  Aufgabenteil (b) */
void printBits(unsigned int z, int anzStellen)
{
  // irgendwas zurückgeben, um aus Rekursion zu kommen (ist ja egal was, da void)
  if(anzStellen == 0)
  {
    return 1;
  }
  else
  {
    printf("%d", (1 & z));
    printBits((z >> 1), (anzStellen - 1));
  }
}


/*  Aufgabenteil (c) */

// Hatte keine Idee, das rekursiv zu  lösen, wegen der Variable, die die Anzahl von außen zählen müsste, was ich mit nur einer Funktion nicht schaffe
int anzahlBits(unsigned int z)
{
  int zaehler = 0;
  for(int i = 0; i <= sizeof(z) * 8; ++i)
  {
    ((1 & z) == 1) ? (zaehler += 1) : (zaehler += 0);
    z = z >> 1;
  }
  return zaehler;  
}




int main()
{

  unsigned int a = 273;

  /* Test (a) */
  unsigned int qs = quersumme(a);
  printf("Die Quersumme von %u ist %u\n",a,qs);

  /* Test (b) */
  printf("%d als Binärzahl: ", a);
  printBits(a, sizeof(a)*8);
  printf("\n");
  
  /* Test (c) */
  int anPoszBits = anzahlBits(a);
  printf("Die Anzahl der Einser-Bits in %u ist %d.\n",a,anPoszBits);
 
  return EXIT_SUCCESS;
}
