#pragma once

#include <iostream>
#include <string>

using namespace std;

class Error
{
    private:
        string mensagem;
      
    public:
      Error()
      {
          mensagem = "Erro Indefinido";
      };
      Error(string mensagem)
      {
          this -> mensagem = mensagem;
      };
      void print() const
      {
          cout << mensagem << endl;
      };
};
