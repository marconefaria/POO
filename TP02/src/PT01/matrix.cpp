#include <iostream>
#include "matrix.hpp"
using namespace std;

// contrutor default - cria uma matriz vazia com nRows = nCols = 0  
Matrix::Matrix(){
    nRows = 0;
    nCols=0;
}
    

// contrutor parametrico 1 - cria uma matriz com nRows  = rows, nCols = cols e 
// com todos os elementos iguais a elem (double)
Matrix::Matrix(int rows, int cols, double elem){
    nRows  = rows; 
    nCols = cols;
    m  = new double * [rows];
    for (int i=0; i<rows; i++)
        m[i] = new double[cols];

    for(int i=0; i<rows; i++)    
    {
        for(int j=0; j<cols; j++)
            m[i][j] = elem;
    }
}


// destrutor
Matrix::~Matrix() {
    for (int i=0; i < this->nRows; i++)
       delete(this->m[i]);
}


// obtem o numero de linhas
int Matrix::getRows() const {
    return nRows;
}

// obtem o numero de colunas
int Matrix::getCols() const {
    return nCols;
}

// retorna uma matriz transposta
Matrix Matrix::transpose() {
    Matrix transposta(this->nCols, this->nRows, this->m[0][0]);

    for(int i=0; i< transposta.getRows(); i++)    
    {
        for(int j=0; j < transposta.getCols(); j++)
            transposta.m[i][j] = this->m[j][i];
    }

    return transposta;
}

// imprime o conteudo da matriz
void Matrix::print() const {
    for(int i=0; i < this->nRows; i++)
    {
        for(int j=0; j < this->nCols; j++)
            cout << this->m[i][j] << " ";
        
        cout << endl;
    }
}