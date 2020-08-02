#ifndef sessao_h
#define sessao_h
#include <iostream>
#include <map>
#include <iterator>
#include <string>
#include "sala.h"
#include "filme.h"
#include "assento.h"


class Sessao {
    private:
        Sala sala;
        std::string dataHora; // formato anomesdia ex: 20191131 ou 20191102
        std::string filme;
        std::multimap <std::string,Assento> mapa_assentos;
        int qtde_assentosLivres;
        int qtde_assentosOcupados;
    public:
        Sessao(Sala sala, std::string filme, std::string data);
        Sessao();
        ~Sessao();
        void imprimirMapaAssentos();
        std::string getDataHora();
        std::string getChaveSessao();
        std::string getFilme();
        Sala getSala();
        int getQtdeAssentosLivres();
        int getQtdeAssentosOcupados();
        bool isAssentoLivre(std::string assento);
        void setAssentoOcupado(std::string assento);
        static bool isSessaoFutura(std::string cod_sessao);
        bool isSessaoFutura();
};
#endif