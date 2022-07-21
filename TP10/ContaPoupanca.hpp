#include "ContaBancaria.hpp"

class ContaPoupanca: public ContaBancaria
{
    private:
        int taxaRendimento;

    public:
        ContaPoupanca(double saldoConta, int numeroConta, string senhaConta, float taxa);
        //virtual ~ContaPoupanca();

        void sacar(double valor);
        void depositar(double valor);
        double tirarExtrato();
        void printTxRendimento() const;
};