#include "amigo.hpp"

Amigo::Amigo():Pessoa(){
  aniversario = "default";
}

//getters
string Amigo::getAniversario() const{
  return aniversario;
}

//setters
void Amigo::setAniversario(string _aniversario){
  aniversario = _aniversario;
}

void Amigo::setDados(){
  string _nome, _aniversario;
  int _idade;

  cout << "===========Digite o nome do contato:===========" << endl;
  cin >> _nome;
  this->setNome(_nome);

  cout << "===========Digite a idade do contato:==========" << endl;
  cin >> _idade;
  this->setIdade(_idade);
    
  cout << "===Digite a data de aniversário do contato:===" << endl;
  cin >> _aniversario;
  this->setAniversario(_aniversario);
}

void Amigo::imprimirAniversario(){
  cout << this->getAniversario() << endl;
} 