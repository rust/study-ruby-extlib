#include <stdio.h>

float mul_all(float array[], int nx);

int main()
{
  int n = 5;
  float a[n];
  int i;

  for(i=0; i<n; i++){
    a[i] = i + 1;
    printf("%f\n", a[i]);
  }
  printf("mul_all()=%f\n", mul_all(a, n));
}
