#include "matrix.hpp"
using namespace std;

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

Matrix::Matrix(ifstream &myFile){
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

        string aux;
            
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

//seta o numero de linhas da matrix
void Matrix::setRows(int row){
    this->nRows = row;
}

//seta o numero de colunas da matrix
void Matrix::setCols(int col){
    this->nCols = col;
}

void Matrix::set(int row, int col, double value){
	this->m[row][col] = value;
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

//matriz identidade
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

//matriz de zeros
void Matrix::zeros(){
    for(int i = 0; i < this->getRows(); i++)    
    {
        for(int j = 0; j < this->getCols(); j++)
            this->m[i][j] = 0;
    }
}

//matriz de ums
void Matrix::ones(){
    for(int i = 0; i < this->getRows(); i++)    
    {
        for(int j = 0; j < this->getCols(); j++)
            this->m[i][j] = 1;
    }
}

//operators
Matrix Matrix::operator* (const Matrix& that) const{
	//a matriz resultado da multiplicação terá o número de linhas de A e de colunas de B
    Matrix auxiliar( this->getRows() , that.getCols() );
    double elem = 0;

    for(int i = 0; i < this->getRows(); i++){
        for(int j = 0; j < that.getCols(); j++){
            for(int k = 0; k < this->getCols(); k++){
                elem = this->m[i][k] * that.m[k][j];
                auxiliar.m[i][j] += elem;
            }
            elem = 0;
        }
    }
    return auxiliar;
 }

Matrix Matrix::operator= (const Matrix& that){
    for(int i = 0; i < this->getRows(); i++){
        delete [] m[i];
    }
    delete[] m;
    
    this->setRows(that.nRows);
    this->setCols(that.nCols);

    this->m = new double*[this->getRows()];
    for(int i = 0; i < this->getRows(); i++){
        this->m[i] = new double[this->getCols()];
        for(int j = 0; j < this->getCols(); j++){
			this->set(i, j, that.m[i][j]);
        }
    }
    return *this;
 }

Matrix Matrix::operator+ (const Matrix& that) const{
    Matrix *soma = new Matrix(that.nRows, that.nCols);
    for(int i = 0; i < this->getRows(); i++){
        for(int j = 0; j < this->getCols(); j++){
			soma->set(i, j, this->m[i][j] + that.m[i][j]);
        }
    }
    
    return *soma;
}

bool Matrix::operator== (const Matrix& that) const{
    if(this->getCols() != that.nCols){
		return false;
	}
    if(this->getRows() != that.nRows){
		return false;
	}
        
    for (int i = 0; i < this->getRows(); i++){
        for (int j = 0; j < this->getCols(); j++){
            if(this->m[i][j] != that.m[i][j]){
                return false;
            }
        }
    }

	return true;
}

bool Matrix::operator!= (const Matrix& that) const{
    if(this->getCols() != that.nCols){
		return false;
	}
    if(this->getRows() != that.nRows){
		return false;
	}

    for (int i = 0; i < this->getRows(); i++){
        for (int j = 0; j < this->getCols(); j++){
            if(this->m[i][j] != that.m[i][j]){
                return true;
            }
        }
    }

    return false;
}

Matrix& Matrix::operator*=(const Matrix& that){
    Matrix *solucao = new Matrix(this -> nRows, that.nCols);

    double aux;
    for(int i = 0; i < this->getRows(); i++){
        for(int j = 0; j < that.nCols; j++){
            aux = 0;
            for(int k = 0; k < this->getCols(); k++){
                aux += this -> m[i][k] * that.m[k][j];
            }
			solucao->set(i, j, aux);
        }
    }

    *this = *solucao;
    return *this;
}

Matrix& Matrix::operator*=(int value){
    for(int i = 0; i < this->getRows(); i++){
        for(int j = 0; j < this->getCols(); j++){
			this->set(i, j, m[i][j] *= value);
        }
    }

    return *this;
}

Matrix& Matrix::operator+=(const Matrix& that){
    for(int i = 0; i < this->getRows(); i++){
        for(int j = 0; j < this->getCols(); j++){
			this->set(i, j, m[i][j] += that.m[i][j]);
        }
    }

    return *this;
}

Matrix& Matrix::operator-(const Matrix& that) const{
    Matrix *subtracao = new Matrix(that.nRows, that.nCols);
    subtracao->m = new double*[this->getRows()];
	
    for(int i = 0; i < this->getRows(); i++){
        subtracao->m[i] = new double[this->getCols()];
        for(int j = 0; j < this->getCols(); j++){
			subtracao->set(i, j, this -> m[i][j] - that.m[i][j]);
        }
    }

    return *subtracao;
}

Matrix& Matrix::operator-=(const Matrix& that){
    for(int i = 0; i < this->getRows(); i++){
        for(int j = 0; j < this->getCols(); j++){
            this->m[i][j] -= that.m[i][j];
        }
    }

    return *this;
}

Matrix& Matrix::operator~() const{
    Matrix *transposta = new Matrix(this->getCols(), this->getRows());

    transposta->m = new double*[transposta->getRows()];
    for(int i = 0; i < transposta->getRows(); i++){
        transposta->m[i] = new double [transposta->getCols()];
        for (int j = 0; j < transposta->getCols(); j++){
			transposta->set(i, j, this -> m[j][i]);
        }
    }

    return *transposta;
}

std::ostream& operator<< (std::ostream& op, const Matrix &that){
    for(int i = 0; i < that.nRows; i++){
        for(int j = 0; j < that.nCols; j++){
            op << that.m[i][j] << ' ';
        }
        op << std::endl;
    }
    return op;
}

std::istream& operator>> (std::istream& op, Matrix &that){
    for (int i = 0; i < that.nRows; i++){
        delete[] that.m[i];
    }
    delete[] that.m;
    
    std::cout << "\nDigite o numero de linhas: " << std::endl;
    op >> that.nRows;
    std::cout << "\nDigite o numero de colunas: " << std::endl;
    op >> that.nCols;

    std::cout << "\nDigite os valores: " << std::endl;
    that.m = new double * [that.nRows];
    for(int i = 0; i < that.nRows; i++){
        that.m[i] = new double[that.nCols];
        for(int j = 0; j < that.nCols; j++){
            op >> that.m[i][j];
        }
    }

    return op;
}