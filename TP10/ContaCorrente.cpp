#include "ContaCorrente.hpp"
#include "error.hpp"
#include <string> 
ContaCorrente::ContaCorrente(double saldoConta, int numeroConta, string senhaConta): ContaBancaria(saldoConta, numeroConta, senhaConta)
{
    quantidadeTransacoes = 0;
}

void ContaCorrente::sacar(double valor)
{
    if(saldo >= valor)
    {
        saldo -= valor;
        quantidadeTransacoes++;
    }
    else
    {
        throw Error("O valor requisitado excede o saldo da conta corrente");
    }
}

void ContaCorrente::depositar(double valor)
{
    saldo += valor;
    quantidadeTransacoes++;
}

double ContaCorrente::tirarExtrato()
{
    std::cout << "Extrato total:" << saldo << std::endl;
    return saldo;
}

void ContaCorrente::printTransacoes() const
{
    std::cout<< "Total de transacoes da conta:" << quantidadeTransacoes << std::endl;
}