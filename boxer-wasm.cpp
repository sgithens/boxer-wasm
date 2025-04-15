#include <stdio.h>
#include <ecl/ecl.h>

#include <exception>
#include <functional>
#include <emscripten.h>

#include <iostream>
using namespace std;

EM_JS(void, js_draw_line, (int x0, int y0, int x1, int y1), {
  drawLine(x0, y0, x1, y1);
});

cl_object draw_line(cl_object x0, cl_object y0, cl_object x1, cl_object y1) {
  js_draw_line(ecl_fixnum(x0), ecl_fixnum(y0), ecl_fixnum(x1), ecl_fixnum(y1));
  return ECL_NIL;
}

int main(int argc, char** argv) {
  printf("hello, Boxer WASM!\n");

  cl_object aux, result;
  cl_boot(argc, argv);

  result = cl_eval(c_string_to_object("(setf *features* (cons :shim-3d-math *features*))"));
  ecl_print(result, ECL_T);

  result = cl_eval(c_string_to_object("(load \"asdf.lisp\")"));
  ecl_print(result, ECL_T);

  result = cl_eval(c_string_to_object("(load \"boxerdata/quicklisp/setup.lisp\")"));
  ecl_print(result, ECL_T);

  result = cl_eval(c_string_to_object("(format nil \"Pre-boxer features: ~A\" *features*)"));
  ecl_print(result, ECL_T);

  result = cl_eval(c_string_to_object("(load \"boxer-wasm.lisp\")"));
  ecl_print(result, ECL_T);

  result = cl_eval(c_string_to_object("(setup-boxer)"));
  ecl_print(result, ECL_T);

  aux = ecl_make_symbol("THREE-DRAW-LINE", "CL-USER");
  ecl_def_c_function(aux, (cl_objectfn_fixed) draw_line, 4);

  result = cl_eval(c_string_to_object("(bw::start-threejs-boxer nil)"));
  ecl_print(result, ECL_T);

  printf("Wraping up...\n");
  return 0;
}
