#ifndef PROF_HPP
#define PROF_HPP

#include <string>
#include <iostream>

using namespace std;

class Professor{
        string nome;
    public:
        Professor(string n){
          nome = n;
        }

        string getName() const{
          return nome;
        }

        virtual double getSalario() = 0;

        virtual void print() const = 0;

        virtual ~Professor(){};
};

#endif