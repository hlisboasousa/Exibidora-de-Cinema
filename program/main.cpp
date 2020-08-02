#include "assento.h"
#include "cinema.h"
#include "distribuidor.h"
#include "filme.h"
#include "pessoa.h"
#include "sala.h"
#include "imax.h"
#include "tresd.h"
#include "premium.h"
#include "sessao.h"
#include "horarios.h"

#include <string.h>
#include <iostream>
#include <limits>
#include <unistd.h>
#include <time.h>
#include <iomanip> 


#define ACESSO_MINIMO 0
#define ACESSO_MAXIMO 5
#define ANO_ATUAL 2019

Pessoa criarEmpregado(){

    std::string nome;
    unsigned long long int id;
    int nivel;
    Pessoa *p;

    std::cout << "Nome do Empregado: " << std::endl;
    std::cin.ignore();
    std::getline (std::cin,nome);
    std::cout << "Identificador Empregado: " << std::endl;

    std::cin >> id;

    std::cout << "Nivel de Acesso: " << std::endl;
    while (!(std::cin >> nivel) || nivel <= ACESSO_MINIMO || nivel > ACESSO_MAXIMO) {
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::cout << "Valor inválido. Tente novamente." << std::endl;
    }

    p = new Pessoa(nome, id, nivel);
    return(*p);
}

Distribuidor criarDistribuidor() {

    std::string nome;
    unsigned long long int id;
    Distribuidor *d;

    std::cout << "Nome do Distribuidor: " << std::endl;
    std::cin.ignore();
    std::getline (std::cin,nome);

    std::cout << "Identificador Distribuidor: " << std::endl;
    std::cin >> id;

    d = new Distribuidor(nome, id);
    return(*d);
}

Filme criarFilme(unsigned long long int distribuidor) {
    std::string nome_filme;
    int duracao;
    std::cout << "Nome do Filme: " << std::endl;
    std::cin.ignore();
    std::getline(std::cin,nome_filme);     
    std::cout << "Duração (min): " << std::endl;
    while (!(std::cin >> duracao) || duracao < 0) {
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::cout << "Valor inválido. Tente novamente." << std::endl;
    }
    Filme *f = new Filme(nome_filme,distribuidor,duracao);
    return *f;

}

Sala cadastrarNovaSala (int num_sala) {
    Sala *s = new Sala();
    int qtde_fileiras;
    int assentos_por_fileiras;
    int tipo_de_sala;
    std::cout << "Sala a ser criada: " << num_sala << std::endl;

do{
    try{
        std::cout << "Digite a quantidade de fileiras da sala: " << std::endl;
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cin >> qtde_fileiras; // QTDE FILEIRAS DEVE SER MENOR QUE 26
        if(std::cin.fail() || qtde_fileiras < 0 || qtde_fileiras > 26) {
            throw(std::invalid_argument("Valor inválido"));
        }
    } catch (std::invalid_argument &e) {
        std::cout << "Valor inválido. Tente novamente" << std::endl;        
    } 
} while (std::cin.fail() || qtde_fileiras < 0 || qtde_fileiras > 26);

do{
    try{
        std::cout << "Digite a quantidade de assentos por fileiras da sala: ";
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cin >> assentos_por_fileiras;
        if(std::cin.fail() || assentos_por_fileiras < 0){
            throw(std::invalid_argument("Valor inválido"));
        }
    } catch(std::invalid_argument &e) {
            std::cout << "Valor inválido. Tente novamente" << std::endl;        
        }
} while (std::cin.fail() || assentos_por_fileiras < 0);

do{
    try{
        std::cout << "Escolha o tipo de sala:" << std::endl;
        std::cout << "1. Comum" << std::endl;
        std::cout << "2. IMAX" << std::endl;
        std::cout << "3. IMAX Premium" << std::endl;
        std::cout << "4. IMAX 3D" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000,'\n');

        std::cin >> tipo_de_sala;
        if (tipo_de_sala < 1 || tipo_de_sala > 4 || std::cin.fail()) {
            throw(std::invalid_argument("Valor inválido"));
        } 
    } catch (std::invalid_argument &e) {
            std::cout << "Valor inválido. Tente novamente" << std::endl;        
        }
} while (tipo_de_sala < 1 || tipo_de_sala > 4 || std::cin.fail());

    if (tipo_de_sala == 1) {
        s = new Sala(num_sala,qtde_fileiras,assentos_por_fileiras);
    }
    if (tipo_de_sala == 2) {
        // sala IMAX
        s = new IMAX(num_sala,qtde_fileiras,assentos_por_fileiras);
    }

    if (tipo_de_sala == 3) {
        // sala IMAX Premium
        s = new Premium(num_sala,qtde_fileiras,assentos_por_fileiras);
    }

    if (tipo_de_sala == 4) {
        //sala IMAX 3D
        s = new TresD(num_sala,qtde_fileiras,assentos_por_fileiras);
    }       
    return *s;
}


int main() {

    int opcao = 0;
    int id_distribuidor;
    int ano, mes, dia;
    std::string s_mes, s_dia, s_sala;
    int num_sala;
    int horario_sessao;
    int qtde_vendaIngressos;
    int contador;
    float valor_total_venda;
    std::string assento_venda;
    Sessao *_sessao = new Sessao();
    std::string chave_sessao, chave_data;
    std::string filme_para_sessoes;

    std::map<unsigned long long int, Distribuidor>::iterator distribuidor_it;
    std::string nome_filme;

    std::cout << std::endl;

    Cinema cinema("Cineart");
    
    while (opcao != -1) {

        std::cout << std::endl;
        std::cout << "O que você deseja fazer?" << std::endl; 
        std::cout << "1. Criar uma nova sala do cinema" << std::endl; // OK 
        std::cout << "2. Criar um novo empregado" << std::endl; // OK
        std::cout << "3. Cadastrar um novo distribuidor" << std::endl; // OK
        std::cout << "4. Cadastrar um novo filme" << std::endl; // OK
        std::cout << "5. Cadastrar uma nova sessao" << std::endl; // OK
        std::cout << "6. Imprimir filmes em cartaz" << std::endl; 
        std::cout << "7. Imprimir próximas sessoes" << std::endl; // OK
        std::cout << "8. Imprimir salas do cinema" << std::endl; // OK
        std::cout << "9. Imprimir empregados" << std::endl; // OK
        std::cout << "10. Imprimir lista Distribuidores" << std::endl; // OK
        std::cout << "11. Imprimir todos os filmes do cinema" << std::endl; // OK
        std::cout << "12. Imprmir mapa de assentos de determinada sessao" << std::endl;
        std::cout << "13. Vender ingressos" << std::endl;
        std::cout << "-1. Sair" << std::endl;

        try{
            std::cin >> opcao;
            if((!std::cin || opcao < -1 || opcao > 13)){
                throw(std::invalid_argument("Valor inválido"));
            }
            } catch(std::invalid_argument &e){
            std::cout << "Valor inválido. Tente novamente" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000,'\n');

        }

        if (opcao == 1) {
            // criando uma sala
            cinema.armazenarNovaSala(cadastrarNovaSala(cinema.getProximaSalaASerCriada()));
        }

        if (opcao == 2) {
            cinema.armazenarNovaPessoa(criarEmpregado());
        }

        if (opcao == 3) {
            // cadastrar um novo distribuidor
            cinema.armazenarNovoDistribuidor(criarDistribuidor());
        }

        if (opcao == 4) {
            std::cout << "Código Distribuidor: " << std::endl;
            std::cin >> id_distribuidor;
            if (cinema.isDistribuidorExistente(id_distribuidor)) {
                cinema.armazenarNovoFilme(criarFilme(id_distribuidor));
            } else {
                std::cout << "Distribuidor não localizado"<< std::endl;
                std::cout << "Retornando ao Menu Inicial..." << std::endl;
                sleep(2);
            }
        }

        if (opcao == 5) {
            if (cinema.getProximaSalaASerCriada() == 1) { // nao existem salas, nao da pra criar sessoes
                std::cout << "Não existem salas no cinema. Não é possível criar sessões." << std::endl;
            } else {
                std::cout << "Para qual filme deseja criar sessoes?" << std::endl;
                std::cin.ignore();
                std::getline (std::cin,filme_para_sessoes);
                if (!cinema.isFilmeExistente(filme_para_sessoes)) {
                    std::cout << "Filme não existente. Retornando ao Menu Inicial." << std::endl;
                    sleep(2);
                } else {
                    std::cout << "Ano: " << std::endl;
                    while (!(std::cin >> ano) || ano < ANO_ATUAL) {
                        std::cin.clear();
                        std::cin.ignore(1000,'\n');
                        std::cout << "Valor inválido. Tente novamente." << std::endl;
                    }               
                    std::cout << "Mês: " << std::endl;
                    while (!(std::cin >> mes) || mes < 1 || mes > 12) {
                        std::cin.clear();
                        std::cin.ignore(1000,'\n');
                        std::cout << "Valor inválido. Tente novamente." << std::endl;
                    } 
                    std::cout << "Dia: " << std::endl;
                    while (!(std::cin >> dia) || dia < 1 || dia > 31) {
                        std::cin.clear();
                        std::cin.ignore(1000,'\n');
                        std::cout << "Valor inválido. Tente novamente." << std::endl;
                    }
                    std::cout << "Sala: " << std::endl; 
                    while (!(std::cin >> num_sala) || num_sala >= cinema.getProximaSalaASerCriada() || num_sala < 1) {
                        std::cin.clear();
                        std::cin.ignore(1000,'\n');
                        std::cout << "Valor inválido. Tente novamente." << std::endl;
                    } 
                    std::cout << "Horário: " << std::endl;
                    std::cout << "1. " + Horarios::getHora(1) << std::endl;
                    std::cout << "2. " + Horarios::getHora(2) << std::endl;
                    std::cout << "3. " + Horarios::getHora(3) << std::endl;
                    std::cout << "4. " + Horarios::getHora(4) << std::endl;                       
                    while (!(std::cin >> horario_sessao) || horario_sessao > 4 || horario_sessao < 1) {
                        std::cin.clear();
                        std::cin.ignore(1000,'\n');
                        std::cout << "Valor inválido. Tente novamente." << std::endl;
                    }
                        
                    if (mes < 10) {
                        s_mes = "0" + std::to_string(mes);
                    } else {
                        s_mes = std::to_string(mes);
                    }

                    if (dia < 10) {
                        s_dia = "0" + std::to_string(dia);
                    } else {
                        s_dia = std::to_string(dia);
                    }

                    if (num_sala < 10) {
                        s_sala = "0" + std::to_string(num_sala);
                    } else {
                        s_sala = std::to_string(num_sala);
                    }

                    chave_data = std::to_string(ano) + s_mes + s_dia + Horarios::getHora(horario_sessao);
                    chave_sessao = chave_data + s_sala;

                    if (!Sessao::isSessaoFutura(chave_sessao)) {
                        // se for uma sessao que já passou nao deve ser possível cria-lá
                        std::cout << "Não é possível criar uma sessão para uma data/hora atual/passada." << std::endl;
                    } else {
                        if (cinema.isSessaoExistente(chave_sessao)) {
                            std::cout << "Não foi possível criar sessão por incompatibilidade de horarios com outras sessões." << std::endl;
                        } else {
                            _sessao = new Sessao(cinema.getSalas().find(num_sala)->second,filme_para_sessoes,chave_data);
                            cinema.armazenarSessao(cinema.getSalas().find(num_sala)->second,*_sessao);
                        }
                    }
                }
            }
        }

        if (opcao == 6) {
            cinema.imprimirFilmesEmCartaz();
        }

        if (opcao == 7) {
            cinema.imprimirSessoesFuturas();
        }

        if (opcao == 8) {
            cinema.imprimirSalas();
        }

        if (opcao == 9) {
            cinema.imprimirEmpregados();
        }

        if(opcao == 10){
            cinema.imprimirDistribuidores();
        }              
        
        if(opcao == 11){
            cinema.imprimirFilmesCadastrados();
        }
        
        if(opcao == 12){
            std::cout << "Para qual sessao você deseja imprimir o mapa de assentos?" << std::endl;
            std::cin >> chave_sessao;
            if (!cinema.isSessaoExistente(chave_sessao)) {
                std::cout << "Sessao Inexistente. Retornando ao Menu Inicial..." << std::endl;
                sleep (2);
            } else {
                cinema.getSessao(chave_sessao)->imprimirMapaAssentos();
            }
        }    

        if (opcao == 13) { // vender ingresso
            std::cout << "Para qual sessao você deseja vender ingressos?" << std::endl;
            std::cin >> chave_sessao;
            if (!cinema.isSessaoExistente(chave_sessao)) {
                std::cout << "Sessao Inexistente. Retornando ao Menu Inicial..." << std::endl;
                sleep (2);
            } else {
                std::cout << "Quantos ingressos deseja vender?" << std::endl;
                while (!(std::cin >> qtde_vendaIngressos) || qtde_vendaIngressos < 1 || qtde_vendaIngressos > cinema.getSessao(chave_sessao)->getQtdeAssentosLivres()) {
                    std::cin.clear();
                    std::cin.ignore(1000,'\n');
                    std::cout << "Valor inválido. Qtde de assentos livres: " + std::to_string(cinema.getSessao(chave_sessao)->getQtdeAssentosLivres()) << std::endl;
                    std::cout << "Tente novamente." << std::endl;
                }
                // imprimir valor total da venda
                valor_total_venda = cinema.getSessao(chave_sessao)->getSala().getValorPorAssento() * qtde_vendaIngressos;
                std::cout << "Valor total: ";
                std::cout << std::setprecision(2) << std::fixed << valor_total_venda << std::endl;

                std::cout << "Selecione o(s) assento(s) que deseja vender" << std::endl;
                cinema.getSessao(chave_sessao)->imprimirMapaAssentos();
                for (contador = 0; contador<qtde_vendaIngressos;contador++) {
                    std::cout << "Ingresso n." + std::to_string(contador+1) + ": ";
                    std::cin >> assento_venda;
                    // o processo de venda de cada ingresso eh feito individualmente
                    // primeiro preciso verificar se o assento digitado eh valido
                    if (cinema.getSessao(chave_sessao)->isAssentoLivre(assento_venda)) {
                        // posso vendê-lo
                        cinema.venderIngresso(chave_sessao,assento_venda);
                    } else {
                        // nao posso vendê-lo
                        //std::cout << "Assento não disponível. Escolha outro." << std::endl;
                        // diminuir o contador para repetir essa venda de ingresso
                        contador--;
                    }
                }
                std::cout << "Ingressos vendidos com sucesso." << std::endl;
            }
        }

        if (opcao == -1) {
            // desalocar os espacos alocados
            cinema.~Cinema();
        }
    }
    return 0;
}
