#include "ContaPoupanca.hpp"
#include "error.hpp" 
#include <string>

ContaPoupanca::ContaPoupanca(double saldoConta, int numeroConta, string senhaConta, float taxa): ContaBancaria(saldoConta, numeroConta, senhaConta)
{
    taxaRendimento = taxa;
}

void ContaPoupanca::sacar(double valor)
{
    if(saldo >= valor)
    {
        saldo -= valor;
    }
    else
    {
        throw Error("O valor requisitado excede ao saldo da conta corrente");
    }
}

void ContaPoupanca::depositar(double valor)
{
    saldo+= valor;
}

double ContaPoupanca::tirarExtrato()
{
    std::cout << "Extrato total:" << saldo << std::endl;
    return saldo;
}

void ContaPoupanca::printTxRendimento() const
{
    std::cout << "Taxa rendimento:" << taxaRendimento << std::endl;
}