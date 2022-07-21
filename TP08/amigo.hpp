#include <iostream>
#include <string>
#include "pessoa.hpp"

using namespace std;

class Amigo : public Pessoa{
  public:
    Amigo();
    ~Amigo(){};

    //getters
    string getAniversario() const;

    //setters
    void setAniversario(string _aniversario);
    virtual void setDados() override;

    //operações classe amigo
    virtual void imprimirAniversario() override;

    private:
      string aniversario;
};