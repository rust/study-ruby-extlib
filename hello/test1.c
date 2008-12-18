#include "ruby.h"

void hello();

VALUE wrap_hello(self) VALUE self;
{
  hello();
  return Qnil;
}

void Init_test()
{
  VALUE module;

  module = rb_define_module("Test");
  rb_define_module_function(module, "hello", wrap_hello, 0);
}
