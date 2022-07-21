#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "ContaCorrente.hpp"
#include "ContaPoupanca.hpp"
#include "error.hpp"
using namespace std;

void clearscreen()
{
    if(system("clear")) system( "cls" );
}

void wait()
{
    cout << "Precione uma tecla para continuar" << endl;
    cin.ignore();
    getchar();
}

ContaPoupanca* criaPoupanca()
{
    int conta;
    string senha;
    double taxa, saldo;

    cout << "Digite o numero da conta a ser criada: ";
    cin >> conta;
    cout << endl;

    cout << "Digite a senha da conta (sem espaços): ";
    cin >> senha;
    cout << endl;

    cout << "Digite a taxa: ";
    cin >> taxa;
    cout << endl;

    cout << "Digite o saldo da conta: ";
    cin >> saldo;
    cout << endl;

    return new ContaPoupanca(saldo, conta, senha, taxa);
}

ContaCorrente* criaCorrente()
{
    int conta;
    double saldo;
    string senha;

    cout << "Digite o numero da conta a ser criada: ";
    cin >> conta;
    cout << endl;

    cout << "Digite a senha da conta (sem espaços): ";
    cin >> senha;
    cout << endl;

    cout << "Digite o saldo da conta: ";
    cin >> saldo;
    cout << endl;

    return new ContaCorrente(saldo, conta, senha);
}

double valorDeposito()
{
    double valor;
    cout << "Digite a quantidade a ser depositada: ";
    cin >> valor;
    cout << endl;

    return valor;
}

double valorSaque()
{
    double valor;
    cout << "Digite a quantidade a ser sacada: ";
    cin >> valor;
    cout << endl;

    return valor;
}

string verificarSaida(string entrada)
{
  if(entrada == "S" || entrada == "sim" || entrada == "Sim" || entrada == "SIM")
  {
    entrada = "s";
  }
  return entrada;
}

int main()
{
    vector<ContaBancaria*> contas;
    int quantia;
    string entrada;
    
    while(entrada != "s")
    {
      cout << "Digite a quantidade de contas a ser criadas: ";
      cin >> quantia;

      for(int i = 0; i < quantia; i++)
      {
          cout << endl;
          int type;
          cout << "Digite o tipo de conta" << endl;
          cout << "1 para Conta Corrente" << endl;
          cout << "2 para Conta Poupança" << endl;
          cin >> type;

          if(type == 1)
          {
            contas.push_back(criaCorrente());
          }
          if(type == 2)
          {
            contas.push_back(criaPoupanca());
          }
          clearscreen();
      }

      for(int i = 0; i < quantia; i++)
      {
          ContaPoupanca *teste = dynamic_cast<ContaPoupanca *>(contas[i]);
          if(teste) teste -> printTxRendimento();
      }

      wait();
      clearscreen();

      for(int i = 0; i < quantia; i++)
      {
          int op;
          
          cout << "Deseja sair? Se sim digite 's', caso contrário digite qualquer tecla..." << endl;
          cin >> entrada;

          entrada = verificarSaida(entrada);
        
          cout << "Digite o tipo de operação para a conta " << contas[i]->getNumero() << endl;
          cout << "1 para saque" << endl;
          cout << "2 para depósito" << endl;
          cout << "3 para extrato" << endl;
          cout << "4 alterar senha" << endl; 
          cin>>op;

          try
          {
              if(op==1)
              {
                contas[i]->sacar(valorSaque());
              } 
              if(op==2)
              {
                contas[i]->depositar(valorDeposito());
              }
              if(op==3)
              {
                contas[i]->tirarExtrato();
              }
              if(op==4)
              {
                string novaSenha;
                cout << "Alterando a senha da conta " << contas[i]->getNumero() << endl;
                cout << "Digite a nova senha: ";
                cin >> novaSenha;
                contas[i]->alterarSenha(novaSenha);
                cout << "Senha Alterada com sucesso!!!"<< endl;
              }
          }catch (Error e)
          {
              cout << "A operação " << op << " não pode ser concluida devido ao erro:" << endl;
              e.print();
          }
          wait();     
      }

      for(int i = 0; i < quantia; i++)
      {
          ContaCorrente *t1 = dynamic_cast<ContaCorrente *>(contas[i]);
          if(t1) t1 -> printTransacoes();

          ContaPoupanca *t2 = dynamic_cast<ContaPoupanca *>(contas[i]);
          if(t2) t2 -> printTxRendimento();
      }

      wait();
      clearscreen();
  }
    return 0;
}