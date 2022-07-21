#include "ProfHorista.hpp"

ProfHorista::ProfHorista(string n, double nht, double vh): Professor(n){
  valorHora = vh;
  nrNorasTrabalhadas = nht;

}

double ProfHorista::getSalario(){
  float salario = (nrNorasTrabalhadas)*(valorHora);
  return salario;
}

void ProfHorista::print() const{
    cout<< "Nome: "<< getName()<<endl;
    cout<< "Numero de horas trabalhadas: "<<  nrNorasTrabalhadas <<endl;
    cout<< "Valor da hora: "<< valorHora << endl;
}

ProfHorista::~ProfHorista(){}