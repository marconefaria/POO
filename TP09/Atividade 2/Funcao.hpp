#ifndef FUNCAO_H
#define FUNCAO_H

#include <iostream>
using namespace std;

class Funcao
{
    public:

     //funcao que obtem a integral da funcao pela regra do trapezio
    double getIntegral(double limiteInferior, double limiteSuperior, double intervalos);

    // funcao virtual representando a funcao cuja integral deve ser calculada
    virtual double func(double input) = 0;

    virtual ~Funcao(){}
};

double Funcao::getIntegral(double limiteInferior, double limiteSuperior, double intervalos){
    double resultado = 0, h = 0;
    h = (limiteSuperior - limiteInferior) / intervalos;

    resultado += (func(limiteInferior) + func(limiteSuperior));
    double value = limiteInferior;

    for(int i = 1; i < (intervalos); i++){
        value += h;
        resultado += 2 * func(value);
    }
    return (h/2) * resultado;
}
#endif