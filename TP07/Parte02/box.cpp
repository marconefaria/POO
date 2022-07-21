#include "box.hpp"


Box::Box(double width=0, double lenght=0, double height=0){
    this->width = width;
    this->length = lenght;
    this->height = height;
    
    if(width < 0 ||  lenght < 0 || height < 0){
        throw invalid_argument("ERROR: invalid dimensions!");
    }
}

Box::Box(Ponto3D p1, Ponto3D p2, Ponto3D p3, Ponto3D p4){
    width = distance(p1, p2);
    length = distance(p1, p3);
    height = distance(p1, p4);
}

double Box::distance(Ponto3D a, Ponto3D b){
    double x = pow((a.get_x()+b.get_x()),2);
    double y = pow((a.get_y()+b.get_y()),2);
    double z = pow((a.get_z()+b.get_z()),2);
    return sqrt(x+y+z);
}

double Box::area(){
    return 2*(height * length + height * width + width * length);
}

double Box::volume(){
    return height * length * width;
}
