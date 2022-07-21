#include <iostream>
#include <string>

using namespace std;

class Pessoa{
  protected:
    string nome;
    int idade;
  public:
    Pessoa();
    Pessoa(string _nome, int _idade);
      
    virtual ~Pessoa(){};
      
    //getters
    int getIdade() const;
    string getNome() const;

    //setters
    void setNome(string _nome);
    void setIdade(int _idade);
    virtual void setDados();

    //operações classe pessoa
    virtual void imprimirEmail();
    virtual void imprimirAniversario();
};