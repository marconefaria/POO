#include "matrix.hpp"
using namespace std;

int main()
{
	ifstream in("myFile.txt");
    Matrix Y;
    Matrix X(3,1,1), A(3,3,2);
    Matrix Z(3,2,7.0);
    Matrix W(in);
    
    A(2,1) = 10;

    Matrix C = A + A;
    std::cout << "\nC = A + A: " << std::endl;
    C.print();

    C -= A;
    std::cout << "\nC = C - A: " << std::endl;  
    C.print();

    X *= 2;
    std::cout << "\nX = X*2: " << std::endl;  
    X.print();

    C = A*X;
    std::cout << "\nC = A*X: " << std::endl;  
    C.print();

    A *= X;
    std::cout << "\nA = A*X: " << std::endl;  
    A.print();

    A += A;
    std::cout << "\nA = A + A: " << std::endl;  
    A.print();

    A = ~X;
    std::cout << "\nA = Transposta de X: " << std::endl;  
    A.print();

    A = C - C;
    std::cout << "\nA = C - C: " << std::endl;  
    A.print();

    if (A == C) {
        std::cout << "\nC == A " << std::endl;
    }
    if(A != C) {
        std::cout << "\nC != A " << std::endl;
    }
    std::cout << "\nA: " << std::endl;
    std::cout<<A<< std::endl;

    std::cin >> W ;
    std::cout << "\nW: " << std::endl;
    std::cout<<W<< std::endl;
    return 0;
}