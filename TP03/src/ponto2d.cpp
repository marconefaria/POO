#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <math.h>
#include <vector>
#include "ponto2d.hpp"

using namespace std;

int Ponto2d::id=0;

Ponto2d::Ponto2d(const Ponto2d &p1){
    this->x = p1.x;
    this->y = p1.y;
    this->id = p1.id;
}

Ponto2d::Ponto2d(double _x, double _y){
    this->x = _x;
    this->y = _y;
    id = getNextId();
}

Ponto2d::~Ponto2d(){
    id_list.pop_back();
}
 
int Ponto2d::getNextId(){
    int verif=0;
    do{
        id = rand()%1000;
        for(int i=0; i< id_list.size(); i++){
            if(id_list[i] == id){
                verif = 1;
            }
        }
    }while(verif == 1);

    //atualiza id
    id_list.push_back(id);
    return id;
}

double Ponto2d::distToOrig() const{
    double dist = sqrt(pow(x,2) + pow(y,2));
    return dist;
}

double Ponto2d::distTo( const Ponto2d &p2) const{
    double dist_x = (this->x - p2.x) * (this->x - p2.x);
    double dist_y = (this->y - p2.y) * (this->y - p2.y);
    
    return sqrt(dist_x + dist_y);
}

Ponto2d Ponto2d::sumOf2(const Ponto2d &p2) const{
    Ponto2d p3;
    p3.x = this->x + p2.x;
    p3.y = this->y + p2.y;

    return p3;
}

void Ponto2d::sumOf( const Ponto2d &p2){
    this->x += p2.x;
    this->y += p2.y;
}

void Ponto2d::print() const{
    cout << "X => " << this->x << endl;
    cout << "Y => " << this->y << endl;
}

int Ponto2d::getId() const{
    return this->id;
}