#ifndef cinema_h
#define cinema_h
#include <iostream>
#include <vector>
#include "filme.h"
#include "pessoa.h"
#include "sessao.h"
#include "sala.h"

#define PORCENTAGEMDISTRIBUIDOR 0.4

class Cinema {
    private:
        // os maps terao como chave respectivamente:
        // filme: titulo do filme
        // empregados: numero identificador
        // sala: numero da sala
        // sessao: string representando data/hora
        // lista distribuidores: numero identificador
        std::map<std::string, Filme> listaFilmes;
        std::map<unsigned long long int, Pessoa> listaEmpregados;
        std::map<int, Sala> listaSalas;
        std::map<std::string, Sessao> listaSessoes; // a chave aqui eh datahorasala ex: 20191102-01:00-01
        std::map<unsigned long long int, Distribuidor> listaDistribuidores;
        float verbaArrecadada;
        float lucro;
        std::string nomeDoCinema;

    public:
        Cinema(std::string nome);
        ~Cinema();
        void armazenarNovaSala(Sala sala); 
        void armazenarNovaPessoa(Pessoa pessoa); 
        void armazenarNovoDistribuidor(Distribuidor novoDistribuidor);
        void armazenarNovoFilme(Filme novoFilme);
        void armazenarSessao(Sala sala, Sessao novaSessao);
        void imprimirFilmesEmCartaz();
        void imprimirFilmesCadastrados();
        void imprimirSessoesFuturas(Filme filme);
        void imprimirSessoesFuturas();
        void imprimirEmpregados();
        void imprimirDistribuidores();
        void imprimirSalas();
        void adicionarVerbaArrecadada(unsigned int valorParaAdicionar);
        float getVerbaArrecadada();
        void setNomeDoCinema(std::string novoNome);
        int getProximaSalaASerCriada();
        bool isListaSalaVazia(); // testa se nao ha nenhum elemento na lista de salas
        bool isEmpregadoExistente(unsigned long long int id_empregado);
        bool isFilmeExistente(std::string nome_filme);
        bool isDistribuidorExistente(unsigned long long int id_distribuidor);
        bool isSessaoExistente(Sessao sessao);
        bool isSessaoExistente(std::string chave_sessao);
        std::map<std::string, Filme> getFilmes();
        std::map<unsigned long long int, Pessoa> getEmpregados();
        std::map<int, Sala> getSalas();
        std::map<std::string, Sessao> getSessoes();
        std::map<unsigned long long int, Distribuidor> getDistribuidores();
        std::string getNomeDoCinema();
        Sessao * getSessao(std::string chave_sessao);
        Distribuidor * getDistribuidor(unsigned long long int id);
        Distribuidor * getDistribuidorPorNomeFilme(std::string filme);
        Distribuidor * getDistribuidorPorFilmeSessao(std::string sessao);
        Filme * getFilmePorSessao(std::string sessao);
        Filme * getFilme(std::string filme);
        void venderIngresso(std::string sessao, std::string assento);
        
};
#endif