#ifndef PROFINT_HPP
#define PROFINT_HPP

#include "Professor.hpp"
#include <iostream>
#include <string>

using namespace std;

class ProfIntegral: public Professor {
        double salarioMensal;
    public:
       ProfIntegral(string n, double sm);
       double getSalario();
       void print() const;
       virtual ~ProfIntegral();
};

#endif