// Dominik Hillmann
// Matrikelnummer 1513306

#include <stdio.h>
#include <stdlib.h>

int main(){
  
  // Teil (a)
  const float PI = 3.14159;
  float radius = 5.3;
  float umfang = 2 * radius * PI;
  float flaeche = radius * radius * PI;

  printf("Ein Kreis mit dem Radius %f hat einen Umfang von %f und eine Flaeche von %f.\n", radius, umfang, flaeche);
 
  // Teil (b)

  int n = 4281;  // n sei maximal vierstellig
  int t = n / 1000;
  int h = (n - t * 1000) / 100;
  int z = (n - t * 1000 - h * 100) / 10;
  int e = (n - t * 1000 - h * 100 - z * 10);
    
  printf("%d besitzt:\n%d Tausender\n%d Hunderter\n%d Zehner und\n%d Einer.\n", n, t, h, z, e);


 
  return EXIT_SUCCESS;
}
