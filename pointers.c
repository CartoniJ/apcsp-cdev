#include <stdio.h>

int main()
{
  
  int a;
  int* ptrtoa;
  float d;
  float e;
  float* ptrtod;
  float* ptrtoe;
  float swap;

  ptrtoa = &a;
  ptrtod = &d;
  ptrtoe = &e;

  a = 5;
  printf("The value of a is %d\n", a);

  *ptrtoa = 6;
  printf("The value of a is %d\n", a);

  printf("The value of ptrtoa is %p\n", (void*)ptrtoa);
  printf("It stores the value %d\n", *ptrtoa);
  printf("The address of a is %p\n", (void*)&a);


  d = 1.234;
  printf("The value of d is %f\n", d);

  e = 5.678;
  printf("The value of e is %f\n", e);

  printf("The address of d is %p\n", (void*)&d);
  printf("The address of e is %p\n", (void*)&e);

  swap = d;
  *ptrtod = e;
  *ptrtoe = swap;
  
  printf("The value of d is %f\n", d);
  printf("The value of e is %f\n", e);
}
