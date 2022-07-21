#ifndef UNIV_HPP
#define UNIV_HPP

#include "ProfIntegral.hpp"
#include "ProfHorista.hpp"
#include <iostream>
#include <vector>

using namespace std;


class Universidade{
        int qtdProfessor;
        vector <Professor*> lista;
    public:
        Universidade();
        void addProfessor(Professor *p);
        double totalPago() const;
        void print() const;
};

#endif


