#include "Ponto2D.hpp"

class Ponto3D : public Ponto2D {
private:
    double z;

public: 
    Ponto3D(double xx = 0, double yy = 0, double zz = 0):Ponto2D(xx, yy){
      this -> z = zz;
    };
    friend ostream& operator<< (ostream &op, const Ponto3D &p);
    Ponto3D& operator= (const Ponto2D &op);
    Ponto3D& operator= (const Ponto3D &op);
    ~ Ponto3D() {};

    double get_z(void) {return z;}
    void set3D (double nx, double ny, double nz) {set(nx, ny); z = nz;} 
    
};

ostream& operator<< (ostream &op, const Ponto3D &p) {
    op << "------------------------------------------------" << endl;
    op << "x = " << p.get_x() << endl;
    op << "y = " << p.get_y() << endl;
    op << "z = " << p.z << endl;
    return op;
}


Ponto3D& Ponto3D::operator= (const Ponto2D &p) {
    set3D(p.get_x(), p.get_y(), 0.0);
    return *this;
}

Ponto3D& Ponto3D::operator= (const Ponto3D &p){
  set3D(p.get_x(), p.get_y(), p.z);
  return *this;
}