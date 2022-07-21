#include "amigo.hpp"
#include "conhecido.hpp"
#include <vector>

using namespace std;

class Agenda{
    public:
      Agenda (int numeroContatos);
      ~Agenda();
        
      //getters
      int getQuantidadeAmigos() const;
      int getQuantidadeConhecidos() const;

      //setters
      void setQuantidadeAmigos(int _quantidadeAmigos);
      void setQuantidadeConhecidos(int _quantidadeConhecidos);

      //operações da agenda
      void adicionarInformacoes();
      void imprimirAniversario();
      void imprimirEmail();

    private:
      vector<Pessoa*> pessoas;
      int quantidadeAmigos;
      int quantidadeConhecidos;
};