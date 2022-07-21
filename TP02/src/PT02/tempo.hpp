#include <iostream>

class Tempo {
    private:

        int _dia;
        int _hora;
        int _minuto;
        int _segundo;

    public:

        // Construtores
       Tempo(int d = 0, int h = 0, int m = 0, int s = 0);
        // Destrutor
        ~Tempo();
    
        // basic getters
        int getDia();
        int getHora();
        int getMinuto();
        int getSegundo();

        //basic setters
        // basic getters
        void setDia();
        void setHora();
        void setMinuto();
        void setSegundo();
        
        // other methods
        void check();
        Tempo somaTempo();
        void print();
        void read();
        Tempo incrementador();
        Tempo decrementador();
};