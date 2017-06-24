// Dominik Hillmann
// Programmierkurs C, Übung 6, Aufgabe 4
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

/* Aufgabe a */
// Funktion, die obere Intevallgrenze berechnet und zurueckgibt
double intervGrenze(double x)
{
  double k = 1;
  while((k * k) <= x)
  {
    k += 1;
  }
  return k;
}

/* Aufgabe b und c */
// Funktion nähert sich immer weiter an ein Wurzel durch immer weitere Eingrenzung des möglichen Intervalls an
double approximation(double x)
{
  // bestimmt Abbruchsabstand zw. Intervallsgrenzen
  double epsilon = 0.000000000000001;
  // Intervall [untereG, obereG] == [a, b]
  double untereG = intervGrenze(x) - 1.0;
  double obereG = intervGrenze(x);
  double mitte;
  unsigned int rundenzaehler = 0;
  
  while((obereG - untereG) > epsilon)
  {
    rundenzaehler += 1;
    mitte = (untereG + obereG) / 2.0;
    
    if((mitte * mitte) < x)
    {
      untereG = mitte;
    }
    else // unter der Annahme, dass kein "="-Fall, weil dann nichts tun (?)
    {
      obereG = mitte;
    }
  }
  printf("%d Approximationsschritte\n", rundenzaehler);
  return mitte;
}


int main()
{
  double x = 2.0;
  printf("Approximation der Wurzel von %.3f: %.10f\n", x, approximation(x));

  return EXIT_SUCCESS;
}
