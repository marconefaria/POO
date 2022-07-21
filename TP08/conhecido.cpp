#include "conhecido.hpp"

Conhecido::Conhecido() : Pessoa(){
  this->setEmail("default");
}
        
string Conhecido::getEmail() const{
  return email;
}

void Conhecido::setEmail(string _email){
  email = _email;
}

void Conhecido::imprimirEmail(){
    cout << this->getEmail() <<endl;
}

void Conhecido::setDados(){
    string _nome, _email;
  int _idade;

  cout << "===========Digite o nome do contato:===========" << endl;
  cin >> _nome;
  this->setNome(_nome);

  cout << "===========Digite a idade do contato:==========" << endl;
  cin >> _idade;
  this->setIdade(_idade);
    
  cout << "======Digite a data de email do contato:======" << endl;
  cin >> _email;
  this->setEmail(_email);
}