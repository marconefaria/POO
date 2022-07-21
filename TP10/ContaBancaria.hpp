#pragma once
#include <string>
#include <iostream>
using namespace std;

class ContaBancaria 
{
    protected:
        double saldo;
        int numero;
        string senha;

    public:
        ContaBancaria(double saldoConta, int numeroConta, string senhaConta): saldo(saldoConta), numero(numeroConta), senha(senhaConta){}
        //virtual ~ContaBancaria();

        void alterarSenha(string novaSenha);
        int getNumero() const
        {
            return numero;
        };

        //métodos virtuais puros
        virtual void sacar(double valor) = 0;
        virtual void depositar(double valor) = 0;
        virtual double tirarExtrato() = 0;
};