#include <vector>

using namespace std;

class Ponto2d{
    public:
        Ponto2d(double _x = 0.0, double _y = 0.0);
        //caso não passa parâmetro, iniclializa com 0;
        Ponto2d(const Ponto2d &p1);
        //construtor que passa um ponto como referência
        ~Ponto2d();
        //destrutor, decrementa id
        double distToOrig() const;
        double distTo(const Ponto2d &p2) const;
        Ponto2d sumOf2(const Ponto2d &p2) const;
        void sumOf(const Ponto2d &p2);
        void print() const;
        int getId() const;

    private:
        double x;
        double y;
        static int id;
        vector<int> id_list;
        //pode ser alterado em outras instâncias
        int getNextId();  
};