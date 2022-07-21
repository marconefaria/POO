#include "ponto3d.hpp"

Ponto3D::Ponto3D(double xx, double yy, double zz):Ponto2D(xx,yy){
    this->z = zz;
}

ostream& operator<< (ostream &op, const Ponto3D &p){
    op << "------------------------------------------------" << endl;
    op << "x = " << p.get_x() << endl;
    op << "y = " << p.get_y() << endl;
    op << "z = " << p.z << endl;

    return op;
}

Ponto3D& Ponto3D::operator= (const Ponto2D &p){
    double x, y;
    x = p.get_x();
    y = p.get_y();
    set(x, y, 0.0);

    return *this;
}

void Ponto3D::set(double nx, double ny, double nz){
    z = nz;
    set(nx, ny);
}

double Ponto3D::get_z(){
    return z;
}