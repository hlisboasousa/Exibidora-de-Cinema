#ifndef filme_h
#define filme_h
#include "distribuidor.h"
#include <iostream>
#include <string>


class Filme {
    private:
        std::string titulo;
        int duracao_minutos;
        unsigned long long int distribuidor;
        float verbaArrecadada;
        unsigned long long int publicoTotal;
        float ticketMedio;
    public:
        Filme(std::string titulo, unsigned long long int distribuidor,int duracao_minutos);
        Filme();
        ~Filme();
        int getDuracaoMinutos();
        float getTicketMedio(); 
        std::string getTitulo();
        unsigned long long int getPublicoTotal();
        float getVerbaArrecadada();
        unsigned long long int getDistribuidor();
        void adicionarVendaIngresso(float valor);
};
#endif