#include <iostream>
#include "tempo.hpp"
using namespace std;

        // Construtores
        Tempo::Tempo(int d, int h, int m, int s){
            this->_dia = d;
            this->_hora = h;
            this->_minuto = m;
            this->_segundo = s;
            check();
        }
    
        // basic getters
        int Tempo::getDia(){
            return this->_dia;
        }
        
        int Tempo::getHora(){
            return this->_hora;
        }
        
        int Tempo::getMinuto(){
            return this->_minuto;
        }
        
        int Tempo::getSegundo(){
            return this->_segundo;
        }
        
        
        // other methods
        void Tempo::check();{
            int aux;
        //Checando conscistência positiva
            if (this->_segundo >= 60){
                aux = (int)(this->_segundo / 60);
                this->_minuto += aux;
                this->_segundo -= 60 * aux;
            }

            if (this->_minuto >= 60){
                aux = (int)(this->_minuto/60);
                this->_hora += aux;
                this->_minuto -= 60 * aux;
            }
            if (this->_hora >= 24){
                aux = (int)(this->_hora/24);
                this->_dia += aux;
                this->_hora -= 24 * aux;
            }

        //Checando consistência negativa
            if (seconds < 0){
                aux = (int)(seconds/60);
                if (seconds % 60 != 0){
                    aux -= 1;
                    seconds = 60 + (seconds%60);
                }else{
                    seconds = 0;
                }
                minutes += aux;
            }

            if (minutes < 0){
                aux = (int)(minutes/60);
                if (minutes % 60 != 0){
                    aux -= 1;
                    minutes = 60 + (minutes%60);
                }else{
                    minutes = 0;
                }
                hours += aux;
            }

            if (hours < 0){
                aux = (int)(hours/24);
                if (hours % 24 != 0){
                    aux -= 1;
                    hours = 24 + (hours%24);
                }else{
                    hours = 0;
                }
                days += aux;
            }

            if (days < 0){
                std::cout<<"Voce fez uma violação incapaz de corrigir."<<std::endl;
                std::cout<<"Todos valores vão ser zerados por isso."<<std::endl;
                days = 0;
                hours = 0;
                minutes = 0;
                seconds = 0;
            }
        }
        
        Tempo Tempo::somaTempo();{
            ...
        }
        
        void Tempo::print(){
            cout<< this->_dia
            <<"d "<< this->_hora
            <<"h "<< this->_minuto
            <<"m "<< this->_segundo
            <<"s " << endl;
        }
        
        void Tempo::read();{
            char option;
            std::cout << "\n Deseja configurar todas as instancias de tempo?" << std::endl;
            std::cout << "Em caso afirmativo, digite 's'. Caso contrario, digite 'n' " << std::endl;
            std:: cin >> option; 

            if( option == 's'){
                std::cout << "\n--Escolha valores para dias, horas, minutos e segundos--";
                std::cout << "\nDias: ";
                std::cin >> days;
                std::cout << "\nHoras: ";
                std::cin >> hours;
                std::cout << "\nMinutos: ";
                std::cin >> minutes;
                std::cout << "\nSegundos: ";
                std::cin >> seconds;
            } else if( option == 'n'){
                char instance;
                std::cout << "\nDigite a inicial de qual instancia de tempo deseja configurar ('d' para dias, 'h' para horas, 'm' para minutos e 's' para segundos)" << std::endl;
                std:: cin >> instance;

                switch (instance)
                {
                case 'd' :
                    std::cout << "Digite o numero de dias:" << std::endl;
                    std::cin >> days;
                    break;
                case 'h' :
                    std::cout << "Digite o numero de horas:" << std:: endl;
                    std:: cin >> hours;
                    break;
                case 'm' : 
                    std::cout << "Digite o numero de minutos:" <<std::endl;
                    std::cin >> minutes;
                    break;
                case 's' :
                    std::cout << "Digite o numero de segundos: " << std::endl;
                    std::cin >> seconds;
                    break;

                default:
                    std::cout << "Instância invalida, tente novamente" << std::endl;
                    break;
                }
            }else{
                std::cout << "Opcao invalida, tente novamente" << std::endl;
            }
            check();
        }
        
        Tempo Tempo::incrementador();{
            ...
        }
        
        Tempo Tempo::decrementador();{
            ...
        }