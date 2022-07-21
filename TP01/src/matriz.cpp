#include <iostream>
#include "matriz.hpp"
using namespace std;

void inicializaMatriz(Matriz &X, int ls, int cs, const double elem)
{
    X.m  = new double * [ls];
    for (int i=0; i<ls; i++)
        X.m[i] = new double[cs];

    X.nLinhas = ls;
    X.nColunas = cs;
   
    for(int i=0; i<X.nLinhas; i++)    
    {
        for(int j=0; j<X.nColunas; j++)
            X.m[i][j] = elem;
    }
}

void apagaMatriz(Matriz &X)
{
    for (int i=0; i<X.nLinhas; i++)
       delete(X.m[i]);
}

Matriz transposta(Matriz &X)
{
    Matriz transposta;
    inicializaMatriz(transposta, X.nColunas, X.nLinhas, X.m[0][0]);

    for(int i=0; i<X.nColunas; i++)    
    {
        for(int j=0; j<X.nLinhas; j++)
            transposta.m[i][j] = X.m[j][i];
    }

    return transposta;
}

Matriz multiplica_por_cte(Matriz &X, double k)
{   
    Matriz resultado;
    inicializaMatriz(resultado, X.nLinhas, X.nColunas, X.m[0][0]);

    for(int i=0; i<X.nLinhas; i++)    
    {
        for(int j=0; j<X.nColunas; j++)
            resultado.m[i][j] = ((X.m[i][j])*k);
    }

    return resultado;
}

void imprimeMatriz(Matriz &X){
    for(int i=0; i<X.nLinhas; i++)
    {
        for(int j=0; j<X.nColunas; j++)
            cout << X.m[i][j] << " ";
        
        cout << endl;
    }
}
