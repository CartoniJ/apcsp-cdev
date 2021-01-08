#include<stdio.h>

int main()
{
  int a = 545;
  char b = 'b';
  float c = 12.345;
  double d = 123.456;
  unsigned int e = 123;
  short int f = 1;

  // print value and size of an int variable
  printf("int a value: %d and size: %lu bytes\n", a, sizeof(a));
  printf("char b value: %d and size: %lu bytes\n", b, sizeof(b));
  printf("float c value: %d and size: %lu bytes\n", c, sizeof(c));
  printf("double d value: %d and size: %lu bytes\n", d, sizeof(d));
  printf("unsigned int e value: %d and size: %lu bytes\n", e, sizeof(e));
  printf("short int f value: %d and size: %lu bytes\n", f, sizeof(f));
}

