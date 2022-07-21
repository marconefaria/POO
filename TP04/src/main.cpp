#include "matrix.hpp"
using namespace std;

int main()
{
	ifstream in("myFile.txt");
    Matrix Y;
    Matrix X(3,1);
    Matrix Z(3,2,7.0);
    Matrix W(in);

    cout << "-------------------MATRIZ Y-------------------" << std::endl;
    Y.print();
    cout << "número de linhas:" << Y.getRows();
    cout << "número de colunas:: " << Y.getCols() << endl;
    cout << endl;

	cout << "-------------------MATRIZ X-------------------" << endl;
    X.print();
    cout << "número de linhas:" << X.getRows();
    cout << "número de colunas:: " << X.getCols() << endl;
    cout << endl;

	cout << "-------------------MATRIZ Z-------------------" << endl;
    Z.print();
    cout << "número de linhas:" << Z.getRows();
    cout << "número de colunas:: " << Z.getCols() << endl;
    cout << endl;
    
	Matrix E = X;

	cout << "------- CÓPIA DA MATRIZ U NA MATRIZ E --------" << endl;
    E.print();
    cout << "número de linhas:" << E.getRows();
    cout << "número de colunas:: " << E.getCols() << endl;
    cout << endl;
    
    Matrix C = Z;

	cout << "------- MATRIZ C COM OS ATRIBUTOS DE Z ------" << endl;
    C.print();
    cout << "número de linhas:" << C.getRows();
    cout << "número de colunas:: " << C.getCols() << endl;
    cout << endl;

	Matrix P(3,3);

    P.unit();
    cout << "\n-------------MATRIZ IDENTIDADE-------------" << endl;
    P.print();

	P.zeros();
    cout << "\n----------------MATRIZ NULA---------------" << endl;
    P.print();

	P.ones();
    cout << "\n--------------MATRIZ DE UNS---------------" << endl;
    P.print();

    cout << "---- MATRIZ W - PEGA OS ATRIBUTOS DO ARQUIVO ----" << endl;
    W.print();
    cout << "número de linhas:" << W.getRows();
    cout << "número de colunas:: " << W.getCols() << endl;
    cout << endl;

	std::cout << "\nELEMENTO(1,2) DA MATRIZ W: " << W.get(2,2) << endl;

//testando funções
    
    return 0;
}