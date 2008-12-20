#include "ruby.h"

int add(int a, int b);

VALUE wrap_add(self, aa, bb)
     VALUE self, aa, bb;
{
  int a, b, result;

  a = FIX2INT(aa);        // FIX2INT によって，VALUE 型構造体を int 型へ変換する
  b = FIX2INT(bb);        // 同上
  result = add(a, b);
  return INT2FIX(result); // INT2FIX によって，int 型を VALUE 型構造体へ変換する
}

void Init_test()
{
  VALUE module;

  module = rb_define_module("Test"); // Test モジュールを生成する
  rb_define_module_function(module, "add", wrap_add, 2); // module(Test モジュール) に add メソッドを，引数の数を2として登録する
}
