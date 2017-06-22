// Dominik Hillmann
// WICHTIG: es gab einen Fehler in der Kompilerung: aus irgendeinem Grund kompilert der Code nicht ohne -lm flag ("nicht definiert Verweis auf ’sqrt’ und ’pow’").
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double PI = 3.14159265358979323846;

/* 
   Zur Übersichtlichkeit und für kürzere Variablennamen: 
   A heißt Fläche, 
   ob heißt oben, 
   un heißt unten,
   ka heißt Kante.
*/

// Stumpf: Hilfsfunktionen
double rechteckA(double seiteA, double seiteB)
{
  return seiteA * seiteB;
}

double trapezA(double kaUn, double kaOb, double hoehe)
{
  return (kaUn + kaOb) * hoehe;
}

double seitenhoehe(double gesamthoehe, double kaOb, double kaUn)
{
  return sqrt(pow(gesamthoehe, 2) + (pow(kaUn - kaOb, 2) / 4));
}


// Stumpf: Funktionen Berechnung Oberfläche und Volumen
double volumenStumpf(double hoehe, double kaOb1, double kaOb2, double kaUn1, double kaUn2)
{
  double grundA = rechteckA(kaOb1, kaOb2);
  double deckA = rechteckA(kaUn1, kaUn2);
  return (1.0 / 3.0) * hoehe * (grundA + sqrt(grundA * deckA) + deckA);
}

double oberflaecheStumpf(double hoehe, double kaOb1, double kaOb2, double kaUn1, double kaUn2)
{
  double mantelFlaeche = (kaUn1 + kaOb1) * seitenhoehe(hoehe, kaOb1, kaUn1) + (kaUn2 + kaOb2) * seitenhoehe(hoehe, kaOb2, kaUn2);
  double grundA = rechteckA(kaOb1, kaOb2);
  double deckA = rechteckA(kaUn1, kaUn2);
  return mantelFlaeche + grundA + deckA;
}




// Quader
double volumenQuader(double breite, double tiefe, double laenge)
{
  return breite * tiefe * laenge;
}

double oberflaecheQuader(double breite, double tiefe, double laenge)
{
  return 2 * (breite * tiefe + breite * laenge + tiefe * laenge);
}



// Zylinder
double oberflaecheZylinder(double r, double h){
  return 2 * PI + (r * r) + 2 * PI * r * h;
}

double volumenZylinder(double r, double h){
  return PI * (r * r) * h;
}



int main()
{
  /* Test Zylinder */
  double r = 3.7;          // Radius Grundfläche
  double hz = 12.2;        // Hoehe
  printf("\n");
  
  printf("Zylinder: \n");
  
  printf("Radius:       %f\n",r); 
  printf("Hoehe:        %f\n",hz);
  
  printf("Flaeche:      %f\n",oberflaecheZylinder(r,hz)); 
  printf("Volumen:      %f\n",volumenZylinder(r,hz));
  
  printf("\n");

  
  /* Test Quader */
  double laenge = 4.0, breite = 3.0, tiefe = 2.0;
  printf("Quader:\n");
  
  printf("Laenge:       %f\n", laenge);
  printf("Breite:       %f\n", breite);
  printf("Tiefe:        %f\n", tiefe);
  
  printf("Flaeche:      %f\n", oberflaecheQuader(laenge, breite, tiefe));
  printf("Volumen:      %f\n", volumenQuader(laenge, breite, tiefe));
  
  printf("\n");

  
  /* Test Pyramidenstumpf */
  double hoehe = 5.0, kanteOben1 = 2.0, kanteOben2 = 3.0, kanteUnten1 = 4.0, kanteUnten2 = 5.0;
  printf("Pyramidenstumpf mit rechteckiger Grundflaeche:\n");

  printf("Kanten oben:  %f, %f\n", kanteOben1, kanteOben2);
  printf("Kanten unten: %f, %f\n", kanteUnten1, kanteUnten2);
  printf("Hoehe:        %f\n", hoehe);
  
  printf("Flaeche:      %f\n", oberflaecheStumpf(hoehe, kanteOben1, kanteOben2, kanteUnten1, kanteUnten2));
  printf("Volumen:      %f\n", volumenStumpf(hoehe, kanteOben1, kanteOben2, kanteUnten1, kanteUnten2));
  
  printf("\n");

  return EXIT_SUCCESS;
}
