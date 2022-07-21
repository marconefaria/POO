#include "matrix.hpp"

// contrutor default - cria uma matriz vazia com nRows = nCols = 0  
Matrix::Matrix(){
    nRows = 0.0;
    nCols = 0.0;
    m = NULL;
}
    

// contrutor parametrico 1 - cria uma matriz com nRows  = rows, nCols = cols e 
// com todos os elementos iguais a elem (double)
Matrix::Matrix(int rows, int cols, const double &value){
    nRows  = rows; 
    nCols = cols;
    m  = new double * [nRows];
    for (int i = 0; i < nRows; i++)
        m[i] = new double[nCols];

    for(int i = 0; i < nRows; i++)    
    {
        for(int j = 0; j < nCols; j++)
            m[i][j] = value;
    }
}

Matrix::Matrix(const Matrix& that){
    this->nCols = that.nCols;
    this->nRows = that.nRows;

    m  = new double * [nRows];

    for(int i = 0; i < nRows; i++)
    {
        m[i] = new double[nCols];
        for(int j = 0; j < nCols; j++)
        {
            this->m[i][j] = that.m[i][j];
        }
    }
}

Matrix::Matrix(std::ifstream &myFile){
    while (!myFile.eof()){
        
        //armazena em uma string a primeira linha do arquivo, que contem o numero de linhas e colunas da matriz
        string data; 
        getline(myFile,data);

        nRows = (int)data[0] - 48;
        nCols = (int)data[2] - 48;
        
        m = new double * [nRows];
        for (int i = 0; i < nRows; i++){
            m[i] = new double [nCols];
        }

        std::string aux;
            
        for( int j = 0; j < nRows; j++){
            int val = 0;
            getline(myFile, aux);
            for( int k = 0; k < nCols; k++){
                   m[j][k] = (double)aux[val] - 48.0;
                   val = val + 2;
            }
        }
    }
}

// destrutor
Matrix::~Matrix() {
    for (int i = 0; i < nRows; i++){
        delete[] m[i];
    }
    delete[] m;
}


// obtem o numero de linhas
int Matrix::getRows() const {
    return nRows;
}

// obtem o numero de colunas
int Matrix::getCols() const {
    return nCols;
}

//retorna o elemento de uma coluna e linha especifica
double Matrix::get(int row, int col) const{
    col-=1;
    row-=1;
    if((row > this->getRows() && row > 0) || (col > this->getCols() && col > 0)){
        return -1;
    }else{
        return this->m[row][col];
    }
}

// imprime o conteudo da matriz
void Matrix::print() const {
    for(int i = 0; i < this->getRows(); i++)
    {
        for(int j = 0; j < this->getCols(); j++)
            cout << this->m[i][j] << " ";
        
        cout << endl;
    }
}

void Matrix::unit(){
    if(this->getRows() == this->getCols()){
        for(int i = 0; i < this->getRows(); i++)    
        {
            for(int j = 0; j < this->getCols(); j++){
                if(i == j){
                    this->m[i][j] = 1;
                }else{
                    this->m[i][j] = 0;
                }
            }
        }
    }else{
        return ;
    }
}

void Matrix::zeros(){
    for(int i = 0; i < this->getRows(); i++)    
    {
        for(int j = 0; j < this->getCols(); j++)
            this->m[i][j] = 0;
    }
}

void Matrix::ones(){
    for(int i = 0; i < this->getRows(); i++)    
    {
        for(int j = 0; j < this->getCols(); j++)
            this->m[i][j] = 1;
    }
}