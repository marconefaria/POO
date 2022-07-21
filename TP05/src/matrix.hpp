#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Matrix {
    private:

        double** m; // m é um array 2D a ser implementado como um pointer de pointers
        int nRows;  // numero de linhas
        int nCols;  //  numero de colunas

    public:

        // Construtores
        Matrix();                           
        Matrix(int rows, int cols, const double &value=0.0);
        Matrix(ifstream &myFile);
        Matrix(const Matrix& that);
        // destrutor
        ~Matrix();
    
        // basic getters
        int getRows() const;
        int getCols() const;
        double get(int row, int col) const;   

        // basic setters
        void setRows(int row);
        void setCols(int col);
        void set(int row, int col, double value);   
        
        // other methods
        void print() const;
        void unit();
        void zeros();
        void ones();
        
        // operators
        bool operator== (const Matrix& that) const;                 //igualdade
        bool operator!= (const Matrix& that) const;                 //diferença
        double& operator()(int i, int j){return m[i - 1][j - 1];};  
        Matrix operator= (const Matrix& that);                      //atribuição
        Matrix operator* (const Matrix& that) const;                //multiplicação
        Matrix& operator*=(const Matrix& that);                     //multiplicação incrementada matrix*matrix
        Matrix& operator*=(int value);                              //multiplicação incrementada cte*matrix
        Matrix operator+ (const Matrix& that) const;                //soma
        Matrix& operator+=(const Matrix& that);                     //soma incrementada
        Matrix& operator-(const Matrix& that) const;                //subtração
        Matrix& operator-=(const Matrix& that);                     //subtração incrementada
        Matrix& operator~() const;                                  //trasposta da matrix
        
        
        friend std::ostream& operator<< (std::ostream& op, const Matrix &that); //leitura de matrix
        friend std::istream& operator>> (std::istream& op, Matrix &that);       //impressão de matrix
};