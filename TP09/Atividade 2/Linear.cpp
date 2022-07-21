#include "Linear.hpp"

Linear::Linear(){
  a = 0;
  b = 0;
}

Linear::Linear(double _a, double _b){
  a = _a;
  b = _b;
}

double Linear::func(double input){
  return (a * input + b);
}