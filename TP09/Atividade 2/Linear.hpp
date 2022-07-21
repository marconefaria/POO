#include "Funcao.hpp"

class Linear : public Funcao{
  private:
    double a;
    double b;
  public:
    Linear();
    Linear(double _a, double _b);
    ~Linear();
    double func(double input);
};