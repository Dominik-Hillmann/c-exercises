/*
Dominik Hillmann
Uebung: OS/7
Aufgabe: 4
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int z1,z2,z3,z4;  // geheime Zahlen 
int r1,r2,r3,r4;  // vom User geratene Zahlen  
int count = 0; 

/* Initialisierung der geheimen Zahlen z1 - z4
   mit 4 verschiedenen Werten zwischen 0 und 9    */
void init()
{
  z1 = rand() % 10;
  do
  {
    z2 = rand() % 10;
  }
  while (z2 == z1);
  
  do
  {
    z3 = rand() % 10;
  }
  while ((z3 == z2) || (z3 == z1));
  
  do
  {
    z4 = rand() % 10;
  }
  while ((z4 == z1) || (z4 == z2) || (z4 == z3));
}
 

/*  Aufgabenteil (a) */
bool alleRUnterschiedlich()
{
  if(r1 != r2)
  {
    if(r2 != r3)
    {
      if(r3 != r4)
      {
	return true;
      }
      else { return false; }
    }
    else { return false; }
  }
  else { return false; }
}

/*  Aufgabenteil (b) */
int countAnzRichtigePlaetze()
{
  int count = 0;
  
  if(r1 == z1)
    count++;
  
  if(r2 == z2)
    count++;
  
  if(r3 == z3)
    count++;
  
  if(r4 == z4)
    count++;
  
  return count;
}


/*  Aufgabenteil (c) */

// wollte eigentlich switch verwenden, aber Warnmeldungen und Internet meinen, dass das eine Konstante sein muss und man das nicht direkt an einer Variable ueberpruefen kann
int countAnzRichtigeZahlen()
{
  if((r1 == z1) || (r1 == z2) || (r1 == z3) || (r1 == z4))
  {
    count++;
    if((r2 == z1) || (r2 == z2) || (r2 == z3) || (r2 == z4))
    {
      count++;
      if((r3 == z1) || (r3 == z2) || (r3 == z3) || (r3 == z4))
      {
	count++;
	if((r4 == z1) || (r4 == z2) || (r4 == z3) || (r4 == z4))
	{
	  count++;
	}
      }
    }
  }
  return count;
}


/* Einlesen der 4 zu ratenden Zahlen, die
   in den Variablen r1 - r4 gespeichert werden. */
void guess()
{
   do
   {
     printf("Raten --> ");
     scanf("%d %d %d %d",&r1,&r2,&r3,&r4);
   }
   while (!alleRUnterschiedlich());
  count++;
}


/*   Spielelogik  */
void play()
{
  bool fertig = false;
  do
  {
    guess();  // naechster Rateversuch durch den Spieler
    int c1 = countAnzRichtigeZahlen();
    int c2 = countAnzRichtigePlaetze();
    if (c2 == 4)
    {  // Spielabbruchbedingung pruefen
      fertig = true;
    }
    else
    {
      printf("Anzahl richtige Zahlen: %d\n",c1);
      printf("Anzahl richtige Plaetze: %d\n",c2);
    }
  }
  while (!fertig);
  
  printf("Das war richtig: Super gemacht!\n");
  printf("Anzahl Versuche: %d\n",count);
}


int main()
{
  /* Zufallszahlengenerator initialisieren */
  srand (time(NULL));

  /* Zufallszahlen initialisieren */
  init(); 
  
  /* spielen */
  play();

  return EXIT_SUCCESS;
}
