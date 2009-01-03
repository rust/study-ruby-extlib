%module test
%{
#include "narray.h"
#include <stdio.h>
float mul_all(float *array, int nx);
%}

%typemap(ruby,in) (float *NARRAY, int LENGTH ){
  VALUE na;
  struct NARRAY *n_na;

  na = na_cast_object($input, NA_SFLOAT);
  GetNArray(na, n_na);
  $1 = (float*)n_na->ptr;
  $2 = n_na->total;
}

extern float mul_all(float *NARRAY, int LENGTH);
