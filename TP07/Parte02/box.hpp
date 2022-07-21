#include "ponto3d.hpp"
#include <cmath>

class Box{
    private:
        double width;
        double length;
        double height;
        double dist(Ponto3D a, Ponto3D b);
    public:
        Box(double width=0, double lenght=0, double height=0);
        Box(Ponto3D p1, Ponto3D p2, Ponto3D p3, Ponto3D p4);
        double distance(Ponto3D a, Ponto3D b);
        double area();
        double volume();
};