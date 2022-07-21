#include "ContaBancaria.hpp"

class ContaCorrente: public ContaBancaria
{
    
    private:
        int quantidadeTransacoes;

    public:
        ContaCorrente(double saldoConta, int numeroConta, string senhaConta);
        //virtual ~ContaCorrente();

        void sacar(double valor);
        void depositar(double valor);
        double tirarExtrato();
        void printTransacoes() const;
};