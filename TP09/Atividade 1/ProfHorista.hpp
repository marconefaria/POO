#ifndef PROFHOR_HPP
#define PROFHOR_HPP

#include "Professor.hpp"
#include <iostream>
#include <string>
using namespace std;

class ProfHorista: public Professor {
        double nrNorasTrabalhadas;
        double valorHora;
    public:
        ProfHorista(string n, double nht, double vh);
        double getSalario();
        void print() const;
        virtual ~ProfHorista();
};

#endif