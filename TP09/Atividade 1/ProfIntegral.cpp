#include "ProfIntegral.hpp"
using namespace std;

ProfIntegral::ProfIntegral(string n, double sm): Professor(n){
    salarioMensal = sm;
}

double ProfIntegral::getSalario(){
    return salarioMensal;
}

void ProfIntegral::print() const{
    cout <<"Nome: "<< getName() << endl;
    cout << "Salario: " << salarioMensal << endl;
}

ProfIntegral::~ProfIntegral(){}