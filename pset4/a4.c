// Dominik Hillmann
#include <stdio.h>
#include <stdlib.h>


double praemie1(unsigned int anzP, double fl)
{
  double praemie = 0.0;
  
  if(anzP <= 2)
  {
    praemie = 10.0 + (fl / 2.0);
  }
  else if(anzP == 3)
  {
    praemie = 15.0 + fl;
  }
  else if(anzP == 4)
  {
    praemie = 15.0 + 1.5 * fl;
  }
  else
  {
    praemie = 25.0 + 2.0 * fl;
  }

  return praemie;
}

double praemie2(unsigned int anzP,double fl)
{
  double praemie = 0.0;

  switch(anzP)
  {
  case 1:
  case 2:
    praemie = 10.0 + fl / 2.0;
    break;
  case 3:
    praemie = 15.0 + fl;
    break;
  case 4:
    praemie = 15.0 + 1.5 * fl;
    break;
  default:
    praemie = 25.0 + 2.0 * fl;
    break;
  }

  return praemie;
}

int main()
{

  unsigned int anzPersonen = 500;
  double flaeche = 87;
  
  printf("%u Personen, %5.2f\n",anzPersonen, flaeche); 

  printf("Praemie: %5.2f\n",praemie1(anzPersonen,flaeche));
  
  printf("Praemie: %5.2f\n",praemie2(anzPersonen,flaeche));

  return EXIT_SUCCESS;
}
