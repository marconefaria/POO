#include "box.cpp"
#include "ponto3d.cpp"

#include <iostream>

using namespace std;

int main(){
    try{
        Box b1(2,2,2);

        cout<<"Area: "<<b1.area()<<endl;
        cout<<"Volume: "<<b1.volume()<<endl;
        
        Ponto3D p1(0,0,0);
        Ponto3D p2(0,3,0);
        Ponto3D p3(3,0,0);
        Ponto3D p4(0,0,3);

        Box b2(p1, p2, p3, p4);

        cout<<"Area: "<<b2.area()<<endl;
        cout<<"Volume: "<<b2.volume()<<endl;   
    }
    catch(invalid_argument e){
        cerr << e.what() << endl;
        return -1;
    }

    return 0;
}