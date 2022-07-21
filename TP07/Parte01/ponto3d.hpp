#include "ponto2d.hpp"

class Ponto3D: public Ponto2D{
    
    public:
        Ponto3D(double xx = 0, double yy = 0, double zz=0) : Ponto2D(xx, yy), z(zz) {this->z = zz;}
        friend ostream& operator<< (ostream &op, const Ponto3D &p);
        Ponto3D& operator= (const Ponto2D &p);
        void set(double nx = 0, double ny = 0, double nz=0){set(nx, ny); z=nz;}
        double get_z(){ return z; }
    private:
        double z;
};    

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