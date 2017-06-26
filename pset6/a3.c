/*
Dominik Hillmann
Uebung: OS/7
Aufgabe: 3
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>       
#include <math.h>

double PI = 3.1415926535;

/* liefert Pseudozufallszahl double-Zahl aus dem Intervall [0.0,1.0] */
double randomDouble()
{
  int rI = rand() % RAND_MAX ;
  double rD = (double) rI / (RAND_MAX - 1);
  return rD;
}


/* Aufgabenteil (a) */

// ermittelt (1/4)*PI
double approxViertelPi(unsigned int n)
{
  unsigned int inCounter = 0;
  unsigned int counter = 0;

  // Schleife zählt, wenn nach Gleichung ein zufaelliger Punkt in den Radius fällt
  for(unsigned int i = 0; i < n; i++)
  {
    if(pow(randomDouble(), 2) + pow(randomDouble(), 2) <= 1)
    {
      ++inCounter;
    }
    ++counter;
  }
  // Verhältnis ermitteln, das sich (1/4)*PI annähert
  return (double) inCounter / counter;
}

/* Aufgabenteil (b) */

// ermittelt mittlere Abweichung von Pi nach k Nutzungen mit n zufälligen Punkten
double mittlereAbweichPi(unsigned int n, unsigned int k)
{
  double abweichSammler = 0.0;
  
  for(unsigned int i = 0; i < k; i++)
  {
    // fabs() statt abs(), da abs() nur für ints
    abweichSammler += fabs(PI - (4.0 * approxViertelPi(n)));
  }
  return abweichSammler / (double) k;
}


int main()
{
  /* Zufallszahlengenerator initialisieren */
  srand (time(NULL));


  /* Aufruf ergaenzen */

  printf("Annäherungen:        %.15f, %.15f, %.15f\n", 4.0 * approxViertelPi(5),
	                                               4.0 * approxViertelPi(50),
	                                               4.0 * approxViertelPi(5000));
  printf("Mittlere Abweichung: %.15f, %.15f, %.15f\n", mittlereAbweichPi(5, 100),
	                                               mittlereAbweichPi(50, 100),
	                                               mittlereAbweichPi(5000, 100));
  

  return EXIT_SUCCESS;
}
