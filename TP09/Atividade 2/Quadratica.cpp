#include "Quadratica.hpp"
#include <math.h>

Quadratica::Quadratica(){
  a = 0;
  b = 0;
  c = 0;
}

Quadratica::Quadratica( double _a, double _b, double _c){
  a = _a;
  b = _b;
  c = _b;
}

double Quadratica::func(double input){
  return( a * pow(input, 2) + b * input + c);
}