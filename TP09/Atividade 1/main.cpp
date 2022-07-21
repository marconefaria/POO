#include "Professor.hpp"
#include "ProfHorista.hpp"
#include "ProfIntegral.hpp"
#include "Universidade.hpp"

#include <iostream>
#include <string>

using namespace std;

int main(){
    Universidade UFMG;
    string nome;
    double valor, salario, hora;

    for(int count = 0; count < 2; count++){
    cout<< "PROFESSOR HORISTA" << endl;
    cout<<"Digite o nome do professor: ";
    cin>>nome;
    cout<<"Digite o numero de horas trabalhadas: ";
    cin>>hora;
    cout<<"Digite o valor da hora: ";
    cin>>valor;
    cout << endl;
    UFMG.addProfessor(new ProfHorista(nome, hora, valor)); 

    }

    cout<< "PROFESSOR INTEGRAL" << endl;
    cout<<"Digite o nome do professor: ";
    cin>>nome;
    cout<<"Digite o salario: ";
    cin>>salario;
    cout << endl;

    UFMG.addProfessor(new ProfIntegral(nome, salario));

    UFMG.print();
    cout<<"O total pago aos professores: "<<UFMG.totalPago()<<endl;

    return 0;
}