#include "Universidade.hpp"

Universidade::Universidade(){
    qtdProfessor = 0;
}

void Universidade::addProfessor(Professor *p){
    lista.push_back(p);
    qtdProfessor++;
}

double Universidade::totalPago() const{
    double total;
    for(int i=0; i<(int)lista.size(); i++){
        total += lista[i]->getSalario();
    }
    return total;
}

void Universidade::print() const{
    for (int count = 0; count < qtdProfessor; count++){
        cout<<"Professor "<<count+1<<endl;
        lista[count]->print();
        cout<<endl;
    }
}