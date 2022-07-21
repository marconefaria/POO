#include "Funcao.hpp"

class Quadratica : public Funcao{
  private:
    double a;
    double b;
    double c;

  public:
    Quadratica();
    Quadratica( double coefA, double coefB, double coefC);
    ~Quadratica();
    double func(double input);
};