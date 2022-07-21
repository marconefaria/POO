#include "ContaBancaria.hpp"

void ContaBancaria::alterarSenha(string novaSenha)
{
    string teste;
    
    cout << "Senha atual" << endl;
    cin >> teste;

    if(teste == senha){
        senha = novaSenha;
        cout << "Nova senha: " << senha << endl;
    }
    else
    {
        cout << "Senha incorreta!" << endl;
    }
}