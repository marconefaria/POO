#include "Senoide.hpp"
#include <cmath>

double Senoide::func(double input){
  double x = input;
  if( x == 0 ){
    return 1;
  }else{
    return( (sin(x))/x );
  }
}
