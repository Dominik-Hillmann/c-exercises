// Dominik Hillmann
// Matrikelnummer 1513306

#include <stdio.h>
#include <stdlib.h>

int main()
{
  // 1l repäsentiert die 1 im Dezimalsystem.
  // Das Suffix l zeigt, dass sie ein long int ist.
  long int nummerEins = 1l;
  printf("%ld \n", nummerEins);
  
  // 02.3f repräsentiert die 2.3 im Dezimalsystem.
  // Das Suffix f zeigt, dass sie ein float ist.
  // Recherche: es gibt in C keine oktalen floats, weshalb die Null am Anfang ignoriert wird.
  float nummerZwei = 02.3f;
  printf("%f \n", nummerZwei);
  
  // 512UL repäsentiert die 512 im Dezimalsystem.
  // Das Suffix "UL" zeigt, dass es ein unsigned long int ist (kein negatives Vorzeichen möglich).
  unsigned long int nummerDrei = 512UL;
  printf("%lu \n", nummerDrei);
  
  // '0' soll die Zahl 0 als character/Zeichen repräsentieren.
  // Die '' geben an, dass die 0 nicht als Zeile 0 in der ASCII-Tabelle interpretiert werden soll, sondern als die 0.
  char nummerVier = '0';
  printf("%c \n", nummerVier);
  
  // 0111 ist die Zahl 73 im Dezimalsystem.
  // Die 0 als Präfix zeigt, dass sie eine Oktalzahl ist und damit ein int.
  int nummerFuenf = 0111;
  printf("%d \n", nummerFuenf);
  
  // 0xFL ist die 15 in Dezimalzahlform.
  // Präfix 0x: es ist eine Hexadezimalzahl.
  // Suffix L: es ist ein long int.
  int nummerSechs = 0xFL;
  printf("%d \n", nummerSechs);



  return EXIT_SUCCESS;
}
