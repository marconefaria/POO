#include "ponto3d.hpp"
#include <cmath>

class Erro{
  string whatIsHappening;
  public:
    Erro(const string &message) : whatIsHappening(msg) {
        cout << whatIsHappening << endl;
    };
};

class Box{
    private:
        double width;
        double length;
        double height;
        double distance(Ponto3D a, Ponto3D b);
    public:

    Box(double _height, double _width, double _lenght){
      height = abs(height);
      width = abs(_width);
      lenght = abs(_leght);
    }

    Box(Ponto3D p1, Ponto3D p2, Ponto3D p3, Ponto3D p4, double _height){
      if((distance(p1,p2) == distance(p3,p4)) && (distance(p1,p4) == distance(p3,p2))){
        width = distance(p1,p2);
        lenght = distance(p2,p3);
        height = _height;
      }
      else{
        throw Erro("Isn't a paralelogram!");
      } 
    }

    double area() const{
      double area =  2*(width * height) + 2*(width * leght) + 2*(height * leght);
      return area;
    } 
    
    double volume() const{
      double volume = height * width * leght;
      return volume;
    }
};