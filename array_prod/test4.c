#include "ruby.h"
#include "narray.h"

float mul_all(float array[], int nx);

VALUE wrap_mul_all(self)
     VALUE self;
{
  VALUE na2;
  struct NARRAY *n_na;
  float result;

  na2 = na_cast_object(self, NA_SFLOAT);
  GetNArray(na2, n_na);
  result = mul_all((float*)n_na->ptr, n_na->total);
  return( rb_float_new(result) );
}

void Init_test()
{
  VALUE class_na;

  rb_require("narray");
  class_na = rb_const_get(rb_cObject, rb_intern("NArray"));
  rb_define_method(class_na, "mul_all", wrap_mul_all, 0);
}
