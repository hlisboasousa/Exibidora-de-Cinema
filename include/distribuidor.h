#ifndef distribuidor_h
#define distribuidor_h
#include <iostream>
#include "pessoa.h"
#include <string>


class Distribuidor: public Pessoa {
    private:
        float ValorTotalArrecadado;
        float ValorDisponivelParaSaque;
    public:
        Distribuidor(std::string nome,unsigned long long int identificacao);
        ~Distribuidor();
        Distribuidor();
        float getValorTotalArrecadado();
        void adicionarVendaIngresso(float valor);

};
#endif