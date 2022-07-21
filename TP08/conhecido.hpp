#include "pessoa.hpp"
#include <iostream>
#include <string>

using namespace std;

class Conhecido : public Pessoa{
  private:
    string email;
  public:
    Conhecido();
    ~Conhecido(){};

    string myType() const;
    virtual void imprimirEmail() override;

    //getters       
    string getEmail() const;

    //setters
    void setEmail(string _email);
    virtual void setDados() override;   
};