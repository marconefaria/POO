#include "pessoa.hpp"

//construtores
Pessoa::Pessoa(){
  nome = "default";
  idade = 0;
}
 
Pessoa::Pessoa(string _nome, int _idade){
  nome = _nome;
  idade = _idade;
}

//getters
int Pessoa::getIdade() const{
  return idade;
}

string Pessoa::getNome() const{
  return nome;
}

//setters
void Pessoa::setDados(){
  string _nome;
  int _idade;

  cout << "===========Digite o nome do contato:===========" << endl;
  cin >> _nome;
  this->setNome(_nome);
    
  cout << "===========Digite a idade do contato:==========" << endl;
  cin >> _idade;
  this->setIdade(_idade);
}

void Pessoa::setNome(string _nome){
  nome = _nome;
}

void Pessoa::setIdade(int _idade){
  idade = _idade;
}

//operações classe pessoa
void Pessoa::imprimirEmail(){
  cout << "Este contato não possui um email salvo!" << endl;
}

void Pessoa::imprimirAniversario(){
  cout << "Este contato não possui uma data de aniversário salva!" << endl;
}