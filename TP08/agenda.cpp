#include <iostream>
#include "agenda.hpp"

Agenda::Agenda (int numeroContatos)
{
  quantidadeAmigos = 0;
  quantidadeConhecidos = 0;
  
  srand((unsigned int) time (NULL));
  
  for(int i = 0; i < numeroContatos; i++){
    int code = (rand()%2 + 1);
    //começa a partir do zero aí incrementa 1
    cout << code <<endl;
    
    if(code == 1)
    {
      pessoas.push_back(new Amigo());
      quantidadeAmigos++;
    }
    else if(code == 2)
    {
      pessoas.push_back(new Conhecido());
      quantidadeConhecidos++;
    }

  }
}

void Agenda::setQuantidadeAmigos(int _quantidadeAmigos)
{
  quantidadeAmigos = _quantidadeAmigos;
}

void Agenda::setQuantidadeConhecidos(int _quantidadeConhecidos)
{
  quantidadeConhecidos = _quantidadeConhecidos;
}

int Agenda::getQuantidadeAmigos() const
{
  return quantidadeAmigos;
}

int Agenda::getQuantidadeConhecidos() const {
  return quantidadeConhecidos;
}

void Agenda::adicionarInformacoes()
{
  int quantidade = (int)pessoas.size();
  for(int i = 0; i < quantidade; i++)
  {
    pessoas[i]->setDados();
  }
}

void Agenda::imprimirAniversario()
{
  int quantidade = (int)pessoas.size();
  for(int i = 0; i < quantidade; i++)
  {
    pessoas[i]->imprimirAniversario();
  }
}

void Agenda::imprimirEmail()
{
  int quantidade = (int)pessoas.size();
  for(int i = 0; i < quantidade; i++)
  {
    pessoas[i]->imprimirEmail();
  }
}