// Dominik Hillmann
// Matrikelnr.: 1513306
// Uebung 8, Aufgabe 3

#include <stdio.h>
#include <stdlib.h>

unsigned int ggT(unsigned int a, unsigned int b)
{
  return (b == 0) ? a : ggT(b, a % b);
}

int kgV(unsigned int a, unsigned int b)
{
  return a * b / ggT(a,b);
}

/* *** Aufgabenteil (a) *** */
void kuerze(unsigned int *pz, unsigned int *pn)
{
  unsigned int teiler = ggT(*pz, *pn); // extra Variable, da Parameter nach naechster Zeile veraendert waren
  *pz = *pz / teiler;
  *pn = *pn / teiler;
}

/* *** Aufgabenteil (b) *** */
void mult(unsigned int *pz1, unsigned int *pz2, unsigned int *pn1, unsigned int *pn2)
{
  *pz1 = (*pz1) * (*pz2);
  *pn1 = (*pn1) * (*pn2);
}

/* *** Aufgabenteil (c) *** */
// Ergebnisse sollen in z2 und n2 gespeichert werden
void add(unsigned int *pz1, unsigned int *pz2, unsigned int *pn1, unsigned int *pn2)
{
  *pz1 = (*pz1 * (kgV(*pn1, *pn2) / (*pn1))) + (*pz2 * (kgV(*pn1, *pn2) / (*pn2)));
  *pn1 = kgV(*pn1, *pn2);
}


int main()
{

  unsigned int z1 = 154, n1 = 255;
  unsigned int z2 = 60, n2 = 143;
  unsigned int z3 = 2, n3 = 91;

  printf("1. Bruch: %u / %u\n",z1,n1);
  printf("2. Bruch: %u / %u\n",z2,n2);
  printf("3. Bruch: %u / %u\n",z3,n3);


  /* *** Aufgabenteil (b) *** */
  mult(&z1, &z2, &n1, &n2);
  printf("Produkt der Brueche z1/n1 * z2/n2 : %d / %d\n",z1,n1);
  
  /* *** Aufgabenteil (a) *** */
  kuerze(&z1, &n1);
  printf("gekuerztes Produkt: %d / %d\n",z1,n1);

  /* *** Aufgabenteil (c) *** */
  add(&z2, &z3, &n2, &n3);
  printf("Summe der Brueche z2/n2 und z3/n3 : %d / %d\n",z2,n2);
  
  /* *** Aufgabenteil (a) *** */
  kuerze(&z2, &n2);
  printf("gekuerztes Produkt: %d / %d\n",z2,n2);
  
  return EXIT_SUCCESS;
}
