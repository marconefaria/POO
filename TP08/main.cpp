#include "agenda.hpp"
#include "amigo.hpp"
#include "conhecido.hpp"
using namespace std;

int main() {
  cout << "=====================AGENDA PESSOAL=====================" << endl;
  cout << "Insira um número de contatos: ";

  int numContatos;
  cin >> numContatos;

  Agenda agendaPessoal(numContatos);
  cout << "Número de amigos: " << agendaPessoal.getQuantidadeAmigos() << endl;
  cout << "Número de conhecidos: " << agendaPessoal.getQuantidadeConhecidos() << endl <<endl;

  agendaPessoal.imprimirEmail();
  cout<< endl;
  agendaPessoal.imprimirAniversario();

  cout << endl << "Defina seus contatos:" <<endl;
  agendaPessoal.adicionarInformacoes();

  cout <<endl;
  agendaPessoal.imprimirEmail();
  cout<< endl;
  agendaPessoal.imprimirAniversario();

  return 0;
}