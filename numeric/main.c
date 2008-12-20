#include <stdio.h>

int add(int a, int b);

int main()
{
  int a, b;

  a = 1;
  b = 2;
  printf("%d + %d = %d\n", a, b, add(a, b));
}
