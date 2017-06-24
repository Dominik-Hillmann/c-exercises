// Dominik Hillmann, Lösungen ganz unten

#include <stdio.h>
#include <stdlib.h>


int f1(unsigned int a, unsigned int b){
  if (b == 0){
    if (a == 0)
    {
      return 0;
    } 
    else
    {
      return  -1;
    }
  } 
  else if (a == 0)
  {
    return 1;
  }
  else
  {
    return f1(a-1,b-1);
  }
}

int f2(unsigned int a, unsigned int b)
{
  if (b == 0)
  {
    return a;
  } else if (a > b) {
    return f2(--a,--b);
  } else {
    return f2(--b,--a);
  }
}


int f3(unsigned int a, unsigned int b){
  if (a < b)
  {
    return 0;
  } else {
    return 1 + f3(f2(a,b),b);
  }
}

int main()
{
  unsigned int a= 15,b = 4;

  //printf("a = %u  b = %u f1(a,b) = %d\n",a,b,f1(a,b));
  //printf("a = %u  b = %u f2(a,b) = %d\n",a,b,f2(a,b));
  printf("a = %u  b = %u f3(a,b) = %d\n",a,b,f3(a,b));
  
  return EXIT_SUCCESS;
}

/*
a: f1: a = 3, b = 2

f1(3,2)
  f1(2,1)
    f1(1,0)
--> -1


b: f2: a = 3, b = 4

f2(3,4)
  f2(3,2)
    f2(2,1)
      f2(1,0)
----> 1


c: f3: a = 15, b = 4

f3(15,4)
  f2(14,3)
    f2(13,2)
      f2(12,1)
        f2(11,0)
------> 11
  f3(11,4)
    f2(11,4)
      f2(10,3)
        f2(9,2)
          f2(8,1)
            f2(7,0)
----------> 7
    f3(7,4)
      f2(7,4)
        f2(6,3)
          f2(5,2)
            f2(4,1)
              f2(3,0)
------------> 3
      f3(3,4)
----> 0
--> 1
> 2
3 

(in den letzten Zeilen dann 1 + f3(...) ausgerechnet, deren Argumente f2-Funktionen sind
*/
