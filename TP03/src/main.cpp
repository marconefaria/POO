#include <iostream>
#include "ponto2d.hpp"

using namespace std;

int main(){

    Ponto2d p1; 
    cout << "Id: " << p1.getId() << endl; 

    Ponto2d p2(4.0, 3.0);   
    cout << "Id: " << p1.getId() << endl;

    p1.print();
    p2.print();

    double distancia_origem = p2.distToOrig();
    cout << "Distancia de P1 ate a origem: " << distancia_origem << endl;

    p1.sumOf(p2);
    p1.sumOf(p2);
    p1.print();
    
    double distancia_p1p2 = p1.distTo(p2);
    cout << "Distancia de P1 ate P2 " << distancia_p1p2 << endl;

    Ponto2d p3 = p1.sumOf2(p2);
    Ponto2d *p4 = new Ponto2d;

    cout << "Id: " << p1.getId() << endl;
    p3.print();
    
    delete p4;

    Ponto2d p5 = p1.sumOf2(p2);

    cout << "Id: " << p1.getId() << endl;

    return 0;
}