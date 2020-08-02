#ifndef sala_h
#define sala_h
#include "assento.h"
#include <string>
#include <iostream>


class Sala {
    protected:
        int numero;
        int fileiras;
        int assentosPorFileiras;
        float valorPorAssento; // valor por assento precisa ser estático para que todas as salas do mesmo tipo tenham o mesmo valor por assento
        static float valorPorAssentoComum;
        std::string tipo;
    public:
        Sala(int numero,int fileiras, int assentosPorFileiras,std::string tipo);
        Sala(int numero,int fileiras, int assentosPorFileiras);
        Sala();
        virtual ~Sala();
        int getNumero();
        int getCapacidade();
        float getValorPorAssento();
        void setValorPorAssento(float);
        void setNumero(int);
        void setFileiras(int fileiras);
        void setAssentosPorFileiras(int assentosPorFileiras);
        int getFileiras();
        int getAssentosPorFileiras();
        std::string getTipo();
};
#endif