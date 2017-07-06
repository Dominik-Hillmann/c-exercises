// Dominik Hillmann
// Matrikelnr.: 1513306
// Uebung 11, Aufgabe 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
   double x;
   double y;
}  P2D;

/* *** Teilaufgabe (a) *** */
struct viereck
{
   char *name;
   P2D eckpunkte[4];
};

/* *** Teilaufgabe (b) *** */
void ausgabePunkt(struct viereck inViereck, int punktNr)
{
   printf("(%.1f,%.1f)", inViereck.eckpunkte[punktNr].x,
                         inViereck.eckpunkte[punktNr].y);
}

void ausgabeViereck(struct viereck inViereck)
{
   for(int i = 0; i < 4; i++)
   {
      ausgabePunkt(inViereck, i);
      printf(" ");
   }
   printf("\n");
}

/* *** Teilaufgabe (c) *** */
double laenge(P2D *anfangsP, P2D *endP)
{
   return sqrt(pow((endP->x - anfangsP->x), 2.0) +
               pow((endP->y - anfangsP->y), 2.0));
}


/* *** Teilaufgabe (d) *** */
double umfang(struct viereck inViereck)
{
   double re = 0.0;
   int endpunkt;

   /* Es ist sichergestellt, dass das Viereck nicht "ueber Kreuz" vermessen wird, da im Array aufeinander folgende Punkte nicht ueber Kreuz zu finden sind,
      wenn diese wie in der Main initialisiert werden. */
   for(int i = 0; i < 4; i++)
   {
      endpunkt = (i == 3) ? 0 : (i + 1); // es gibt keinen vierten Punkt, also muss in der letzter Messung Abstand von [3] zu [0] gemessen werden
      re += laenge(&(inViereck.eckpunkte[i]),
                   &(inViereck.eckpunkte[endpunkt]));
   }
   return re;
}


int main()
{
   /* *** Teilaufgabe (e) *** */

   // Viereck erstellen
   struct viereck v1;
   v1.name = "Viereck McViereckface";
   v1.eckpunkte[0].x = 1.0;
   v1.eckpunkte[0].y = 2.5;
   v1.eckpunkte[1].x = 5.0;
   v1.eckpunkte[1].y = 2.5;
   v1.eckpunkte[2].x = 5.0;
   v1.eckpunkte[2].y = 8.0;
   v1.eckpunkte[3].x = 1.0;
   v1.eckpunkte[3].y = 8.5;

   // Teilaufgabe e
   printf("Viereck %s:\n", v1.name);
   ausgabeViereck(v1);
   printf("Umfang: %.2f\n", umfang(v1));

   return EXIT_SUCCESS;
}
