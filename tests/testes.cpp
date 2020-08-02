#include "doctest.h"

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

#include <string.h>
#include <iostream>

/*TESTES UNITÁRIOS:

1) Salas e valores de ingresso;
2) Pessoas e níveis de acesso; 
3) Filmes;
4) Sessões;
5) Vendas de ingresso;
6) Valor arrecadado, publico total ticket medio (filme);
7) Valor total arrecadado do cinema;
8) Lucro do cinema e porcentagem do distribuidor;


---------------------------TESTES UNITÁRIOS----------------------------

-------------------TESTE SALAS E VALORES POR ASSENTO----------------------------

                CONSTRUTOR SALA COM FORMATO: Tipo(numero, capacidade)------*/

TEST_CASE("01 - Testando o construtor de salas") {
    CHECK_NOTHROW(Sala salaComum(1,5,10));
    CHECK_NOTHROW(IMAX salaIMAX(2,5,10));
    CHECK_NOTHROW(Premium salaPremium(3,5,10));
    CHECK_NOTHROW(TresD salaTresD(4,5,10));
}

TEST_CASE("02 - Testando getters e setters das salas") {

    //CONSTRUINDO UMA SALA DE CADA TIPO COM CAPACIDADE 50 (5X10)
    Sala *salaComum = new Sala(1,5,10);
    Sala *salaIMAX = new IMAX(2,5,10);
    Sala *salaPremium = new Premium(3,5,10);
    Sala *sala3D = new TresD(4,5,10);

    CHECK(salaComum->getCapacidade()==50);
    CHECK(salaComum->getNumero()==1);
    CHECK(salaComum->getFileiras()==5);
    CHECK(salaComum->getAssentosPorFileiras()==10);
    CHECK(salaComum->getTipo()=="Comum");
    CHECK(salaIMAX->getTipo()=="IMAX");
    CHECK(salaPremium->getTipo()=="Premium");
    CHECK(sala3D->getTipo()=="3D");

    //setando valores diferentes
    salaComum->setNumero(2);
    salaComum->setFileiras(6);
    salaComum->setAssentosPorFileiras(11);

    CHECK(salaComum->getNumero()==2);
    CHECK(salaComum->getFileiras()==6);
    CHECK(salaComum->getAssentosPorFileiras()==11);

    //DESALOCANDO MEMÓRIA
    delete salaComum;
    delete salaIMAX;
    delete salaPremium;
    delete sala3D;
}

TEST_CASE("03 - Testando os valores por assento de cada tipo") {

    //CONSTRUINDO UMA SALA DE CADA TIPO COM CAPACIDADE 50 (5X10)
    Sala *salaComum = new Sala(1,5,10);
    Sala *salaIMAX = new IMAX(2,5,10);
    Sala *salaPremium = new Premium(3,5,10);
    Sala *sala3D = new TresD(4,5,10);

    //CONFERINDO OS VALORES POR ASSENTO
    CHECK(salaComum->getValorPorAssento()==27.00);
    CHECK(salaIMAX->getValorPorAssento()-32.40 < 0.01);
    CHECK(salaPremium->getValorPorAssento()-55.08 < 0.01);
    CHECK(sala3D->getValorPorAssento()-40.40 < 0.01);

    //DESALOCANDO MEMÓRIA
    delete salaComum;
    delete salaIMAX;
    delete salaPremium;
    delete sala3D;
}

TEST_CASE("04 - Testando o cadastro de salas"){
    Cinema Cineart("Cineart");

    Sala *salaComum = new Sala(1,5,10);
    Sala *salaIMAX = new IMAX(2,5,10);
    Sala *salaPremium = new Premium(3,5,10);
    Sala *sala3D = new TresD(4,5,10);

    CHECK_NOTHROW(Cineart.armazenarNovaSala(*salaComum));
    CHECK_NOTHROW(Cineart.armazenarNovaSala(*salaIMAX));
    CHECK_NOTHROW(Cineart.armazenarNovaSala(*salaPremium));
    CHECK_NOTHROW(Cineart.armazenarNovaSala(*sala3D));

    //DESALOCANDO MEMÓRIA
    delete salaComum;
    delete salaIMAX;
    delete salaPremium;
    delete sala3D;
}

/*---------------------------TESTE PESSOAS E NIVEIS-----------------------------
    NÍVEIS:
        0)Distribuidor
        1)Proprietário do cinema
        2)Gerente
        3)Vendedor

        EMPREGADOS - CONSTRUTOR COM FORMATO: Pessoa("nome", cpf ou cnpj, nível de acesso )------
        DISTRIBUIDOR - CONSTRUTOR COM FORMATO: Distribuidor("nome", id_distribuidor)-----------*/

TEST_CASE("05 - Testando o construtor de pessoas"){

    CHECK_NOTHROW(Pessoa("Proprietário", 12345678900,1));
    CHECK_NOTHROW(Pessoa("Gerente", 12345678901, 2));
    CHECK_NOTHROW(Pessoa("Vendedor", 12345678902, 3));
    CHECK_NOTHROW(Distribuidor("Distribuidor", 1));
}

TEST_CASE("06 - Testando os getters de nome, id e nível"){
    //CONSTRUINDO UM PROPRIETARIO, UM GERENTE, UM VENDEDOR E UM DISTRIBUIDOR
    Pessoa *proprietario = new Pessoa("Proprietário", 12345678900,1);
    Pessoa *gerente = new Pessoa("Gerente", 12345678901, 2);
    Pessoa *vendedor = new Pessoa("Vendedor", 12345678902, 3);
    Distribuidor *distribuidor = new Distribuidor("Distribuidor", 1);

    CHECK(proprietario->getNome()=="Proprietário");
    CHECK(gerente->getNome()=="Gerente");
    CHECK(vendedor->getNome()=="Vendedor");
    CHECK(distribuidor->getNome()=="Distribuidor");

    CHECK(proprietario->getIdentificacao()==12345678900);
    CHECK(gerente->getIdentificacao()==12345678901);
    CHECK(vendedor->getIdentificacao()==12345678902);
    CHECK(distribuidor->getIdentificacao()==1);

    CHECK(proprietario->getNivelDeAcesso()==1);
    CHECK(gerente->getNivelDeAcesso()==2);
    CHECK(vendedor->getNivelDeAcesso()==3);
    CHECK(distribuidor->getNivelDeAcesso()==0);

    //DESALOCANDO MEMÓRIA
    delete proprietario;
    delete gerente;
    delete vendedor;
    delete distribuidor;
}

TEST_CASE("07 - Testando o cadastro de pessoas"){
    Cinema Cineart("Cineart");

    Pessoa *proprietario = new Pessoa("Proprietário", 12345678900,1);
    Pessoa *gerente = new Pessoa("Gerente", 12345678901, 2);
    Pessoa *vendedor = new Pessoa("Vendedor", 12345678902, 3);
    Distribuidor *distribuidor = new Distribuidor("Distribuidor", 1);

    Cineart.armazenarNovaPessoa(*proprietario);
    Cineart.armazenarNovaPessoa(*gerente);
    Cineart.armazenarNovaPessoa(*vendedor);
    Cineart.armazenarNovoDistribuidor(*distribuidor);

    CHECK(Cineart.isEmpregadoExistente(12345678900)==1);
    CHECK(Cineart.isEmpregadoExistente(12345678901)==1);
    CHECK(Cineart.isEmpregadoExistente(12345678902)==1);
    CHECK(Cineart.isDistribuidorExistente(1)==1);

    //DESALOCANDO MEMÓRIA
    delete proprietario;
    delete gerente;
    delete vendedor;
    delete distribuidor;
}

/*-----------------------------TESTE FILMES-----------------------------

           CONSTRUTOR FILME COM FORMATO: Filme("nome", id_distribuidor, duração em minutos)------*/

TEST_CASE("08 - Testando o construtor de filmes"){
    CHECK_NOTHROW(Filme("Rei Leão",1,90));
    CHECK_NOTHROW(Filme("Titanic",1,195));
}

TEST_CASE("09 - Testando os getters de filme"){
    //definição de distribuidor
    Distribuidor *distribuidor = new Distribuidor("distribuidor", 1);

    //definição de filme
    Filme *ReiLeao = new Filme("Rei Leão",distribuidor->getIdentificacao(),90);

    CHECK(ReiLeao->getTitulo()=="Rei Leão");
    CHECK(ReiLeao->getDistribuidor()==1);
    CHECK(ReiLeao->getDuracaoMinutos()==90);
}

TEST_CASE("10 - Testando o cadastro de filmes"){
    Cinema Cineart("Cineart");

    //definição e cadastro de distribuidor
    Distribuidor *distribuidor = new Distribuidor("distribuidor", 1);
    Cineart.armazenarNovoDistribuidor(*distribuidor);

    //definição de filmes
    Filme *ReiLeao = new Filme("Rei Leão",distribuidor->getIdentificacao(),90);
    Filme *Titanic = new Filme("Titanic",distribuidor->getIdentificacao(),195);
    Filme *MagicoDeOz = new Filme("Mágico de Oz",1,195); 
    
    Cineart.armazenarNovoFilme(*ReiLeao);
    Cineart.armazenarNovoFilme(*Titanic);
    Cineart.armazenarNovoFilme(*MagicoDeOz);
    
    CHECK(Cineart.isFilmeExistente("Rei Leão")==1);
    CHECK(Cineart.isFilmeExistente("Titanic")==1);
    CHECK(Cineart.isFilmeExistente("Mágico de Oz")==1);
    

    delete ReiLeao;
    delete Titanic;
    delete MagicoDeOz;
}


/*-----------------------------TESTE SESSÕES-----------------------------

     CONSTRUTOR SESSAO COM FORMATO: Sessao(Sala, "nome_do_filme", string data)------*/

TEST_CASE("11 - Testando o contrutor de sessões "){

    //definição de salas
    Sala *salaComum = new Sala(1,5,10);
    Sala *salaIMAX = new IMAX(2,5,10);

    //definição de filmes
    Filme *ReiLeao = new Filme("Rei Leão",1,90);
    Filme *Titanic = new Filme("Titanic",1,195);

    CHECK_NOTHROW(Sessao(*salaComum,"Rei Leão", std::to_string(20191101)));
    CHECK_NOTHROW(Sessao(*salaIMAX,"Titanic", std::to_string(20191101)));

    //DESALOCANDO MEMÓRIA
    delete salaComum;
    delete salaIMAX;
    delete ReiLeao;
    delete Titanic;
}

TEST_CASE("12 - Testando os getters de sessão"){

    //Definição de salas
    Sala *salaComum = new Sala(1,6,10);
    Sala *salaIMAX = new IMAX(2,5,10);
    
    //Definição de distribuidores
    Distribuidor *distribuidor = new Distribuidor("distribuidor", 1);

    //Definição de filmes
    Filme *ReiLeao = new Filme("Rei Leão",1,90);
    Filme *Titanic = new Filme("Titanic",1,195);

    //Definição de Sessões
    Sessao *sessao1 = new Sessao(*salaComum,"Rei Leão", std::to_string(2019093010));
    Sessao *sessao2 = new Sessao(*salaIMAX,"Titanic", std::to_string(2019093010));

    CHECK(sessao1->getChaveSessao()=="201909301001");
    CHECK(sessao1->getDataHora()=="2019093010");
    CHECK(sessao1->getFilme()=="Rei Leão");
    CHECK(sessao2->getFilme()=="Titanic");
    CHECK(sessao1->getSala().getNumero()==1);    
    
    //DESALOCANDO MEMÓRIA
    delete salaComum;
    delete salaIMAX;
    delete distribuidor;
    delete ReiLeao;
    delete Titanic;
    delete sessao1;
    delete sessao2;
}

TEST_CASE("13 - Testando o cadastro de Sessões"){

    Cinema Cineart("Cineart");

    //Definição e cadastro de salas
    Sala *salaComum = new Sala(1,5,10);
    Sala *salaIMAX = new IMAX(2,5,10);
    Cineart.armazenarNovaSala(*salaComum);
    Cineart.armazenarNovaSala(*salaIMAX);

    //Definição e cadastro de distribuidores
    Distribuidor *distribuidor = new Distribuidor("distribuidor", 1);
    Cineart.armazenarNovoDistribuidor(*distribuidor);

    //Definição e cadastro de filmes
    Filme *ReiLeao = new Filme("Rei Leão",1,90);
    Filme *Titanic = new Filme("Titanic",1,195);
    Cineart.armazenarNovoFilme(*ReiLeao);
    Cineart.armazenarNovoFilme(*Titanic);

    //Definição e cadastro de sessoes    
    Sessao *sessao1 = new Sessao(*salaComum,"Rei Leão", std::to_string(2019093010));
    Sessao *sessao2 = new Sessao(*salaIMAX,"Titanic", std::to_string(2019093010));
    Cineart.armazenarSessao(*salaComum,*sessao1);
    Cineart.armazenarSessao(*salaIMAX,*sessao2);

    CHECK(Cineart.isSessaoExistente(*sessao1)==1);
    CHECK(Cineart.isSessaoExistente(*sessao2)==1);

    //DESALOCANDO MEMÓRIA
    delete salaComum;
    delete salaIMAX;
    delete distribuidor;
    delete ReiLeao;
    delete Titanic;
    delete sessao1;
    delete sessao2;
}


TEST_CASE("14 - Testando a venda de ingressos"){

    Cinema Cineart("Cineart");

    //Definição e cadastro de salas
    Sala *salaComum = new Sala(1,5,10);
    Cineart.armazenarNovaSala(*salaComum);

    //Definição e cadastro de distribuidores
    Distribuidor *distribuidor = new Distribuidor("distribuidor", 1);
    Cineart.armazenarNovoDistribuidor(*distribuidor);

    //Definição e cadastro de filmes
    Filme *ReiLeao = new Filme("Rei Leão",1,90);
    Cineart.armazenarNovoFilme(*ReiLeao);

    //Definição e cadastro de Sessões   
    Sessao *sessao = new Sessao(*salaComum,"Rei Leão", std::to_string(2019093010));
    Cineart.armazenarSessao(*salaComum,*sessao);

    CHECK(Cineart.getSessao("201909301001")->isAssentoLivre("A01")==1); //assento previamente livre
    Cineart.venderIngresso(sessao->getChaveSessao(),"A01");
    CHECK(Cineart.getSessao("201909301001")->isAssentoLivre("A01")==0); //assento ocupado após venda

    CHECK(Cineart.getSessao("201909301001")->isAssentoLivre("A02")==1); //assento previamente livre
    Cineart.venderIngresso("201909301001","A02");
    CHECK(Cineart.getSessao("201909301001")->isAssentoLivre("A02")==0); //assento ocupado após venda

    //DESALOCANDO MEMÓRIA
    delete salaComum;
    delete distribuidor;
    delete ReiLeao;
    delete sessao;
}


TEST_CASE("15 - Testando a função de quantidade de assentos livres/ocupados"){

    Cinema Cineart("Cineart");

    //Definição e cadastro de salas
    Sala *salaComum = new Sala(1,6,10);
    Sala *salaIMAX = new IMAX(2,5,10);
    Cineart.armazenarNovaSala(*salaComum);
    Cineart.armazenarNovaSala(*salaIMAX);

    //Definição e cadastro de distribuidores
    Distribuidor *distribuidor = new Distribuidor("distribuidor", 1);
    Cineart.armazenarNovoDistribuidor(*distribuidor);

    //Definição e cadastro de filmes
    Filme *ReiLeao = new Filme("Rei Leão",1,90);
    Filme *Titanic = new Filme("Titanic",1,195);
    Cineart.armazenarNovoFilme(*ReiLeao);
    Cineart.armazenarNovoFilme(*Titanic);

    //Definição e cadastro de Sessões    
    Sessao *sessao1 = new Sessao(*salaComum,"Rei Leão", std::to_string(2019123010));
    Sessao *sessao2 = new Sessao(*salaIMAX,"Titanic", std::to_string(2019123010));
    Cineart.armazenarSessao(*salaComum,*sessao1);
    Cineart.armazenarSessao(*salaIMAX,*sessao2);

    CHECK(Cineart.getSessao(sessao1->getChaveSessao())->getQtdeAssentosLivres()==60);
    CHECK(Cineart.getSessao(sessao2->getChaveSessao())->getQtdeAssentosLivres()==50);
    CHECK(Cineart.getSessao(sessao1->getChaveSessao())->getQtdeAssentosOcupados()==0);
    CHECK(Cineart.getSessao(sessao2->getChaveSessao())->getQtdeAssentosOcupados()==0);

    //vendendo 3 ingressos da sessao1 e 2 ingressos da sessao2
    Cineart.venderIngresso(sessao1->getChaveSessao(),"B01");
    Cineart.venderIngresso(sessao1->getChaveSessao(),"B02");
    Cineart.venderIngresso(sessao1->getChaveSessao(),"B03");
    Cineart.venderIngresso(sessao2->getChaveSessao(),"C01");
    Cineart.venderIngresso(sessao2->getChaveSessao(),"C02");

    CHECK(Cineart.getSessao(sessao1->getChaveSessao())->getQtdeAssentosLivres()==57);
    CHECK(Cineart.getSessao(sessao2->getChaveSessao())->getQtdeAssentosLivres()==48);
    CHECK(Cineart.getSessao(sessao1->getChaveSessao())->getQtdeAssentosOcupados()==3);
    CHECK(Cineart.getSessao(sessao2->getChaveSessao())->getQtdeAssentosOcupados()==2);
    
    //DESALOCANDO MEMÓRIA
    delete salaComum;
    delete salaIMAX;
    delete distribuidor;
    delete ReiLeao;
    delete Titanic;
    delete sessao1;
    delete sessao2;

}

TEST_CASE("16 - Testando publico total, ticket médio e valor arrecadado de filmes"){

    Cinema Cineart("Cineart");

    //Definição e cadastro de salas
    Sala *salaComum = new Sala(1,6,10);
    Sala *salaIMAX = new IMAX(2,5,10);
    Sala *salaPremium = new Premium (3,5,10);
    Sala *sala3D = new TresD (4,5,10);
    Cineart.armazenarNovaSala(*salaComum);
    Cineart.armazenarNovaSala(*salaIMAX);
    Cineart.armazenarNovaSala(*salaPremium);
    Cineart.armazenarNovaSala(*sala3D);

    //Definição e cadastro de distribuidores
    Distribuidor *distribuidor = new Distribuidor("distribuidor", 1);
    Cineart.armazenarNovoDistribuidor(*distribuidor);

    //Definição e cadastro de filmes
    Filme *ReiLeao = new Filme("Rei Leão",1,90);
    Filme *Titanic = new Filme("Titanic",1,195);
    Cineart.armazenarNovoFilme(*ReiLeao);
    Cineart.armazenarNovoFilme(*Titanic);

    //Definição e cadastro de Sessões
    Sessao *sessao1 = new Sessao(*salaComum,"Rei Leão", std::to_string(2019123010));
    Sessao *sessao2 = new Sessao(*salaIMAX,"Titanic", std::to_string(2019123010));
    Sessao *sessao3 = new Sessao(*salaPremium, "Rei Leão", std::to_string(2019123010));
    Sessao *sessao4 = new Sessao(*sala3D, "Titanic", std::to_string(2019123010));
    Cineart.armazenarSessao(*salaComum,*sessao1);
    Cineart.armazenarSessao(*salaIMAX,*sessao2);
    Cineart.armazenarSessao(*salaPremium, *sessao3);
    Cineart.armazenarSessao(*sala3D,*sessao4);

    //vendas de ingressos
    CHECK(salaIMAX->getValorPorAssento()-32.40 < 0.01);
    CHECK(salaPremium->getValorPorAssento()-55.08 < 0.01);
    CHECK(sala3D->getValorPorAssento()-40.40 < 0.01);

    //vendendo 5 ingressos da sessão 1
    Cineart.venderIngresso(sessao1->getChaveSessao(), "A05");
    Cineart.venderIngresso(sessao1->getChaveSessao(), "A06");
    Cineart.venderIngresso(sessao1->getChaveSessao(), "A07");
    Cineart.venderIngresso(sessao1->getChaveSessao(), "A08");
    Cineart.venderIngresso(sessao1->getChaveSessao(), "A09");

    //vendendo 10 ingressos da sessão 2
    Cineart.venderIngresso(sessao2->getChaveSessao(), "A01");
    Cineart.venderIngresso(sessao2->getChaveSessao(), "B01");
    Cineart.venderIngresso(sessao2->getChaveSessao(), "C01");
    Cineart.venderIngresso(sessao2->getChaveSessao(), "C02");
    Cineart.venderIngresso(sessao2->getChaveSessao(), "C03");
    Cineart.venderIngresso(sessao2->getChaveSessao(), "D01");
    Cineart.venderIngresso(sessao2->getChaveSessao(), "D02");
    Cineart.venderIngresso(sessao2->getChaveSessao(), "D03");
    Cineart.venderIngresso(sessao2->getChaveSessao(), "D04");
    Cineart.venderIngresso(sessao2->getChaveSessao(), "D05");

    //vendendo 3 ingressos da sessão 3
    Cineart.venderIngresso(sessao3->getChaveSessao(), "A01");
    Cineart.venderIngresso(sessao3->getChaveSessao(), "B01");
    Cineart.venderIngresso(sessao3->getChaveSessao(), "C01");

    //vendendo 8 ingressos da sessão 4
    Cineart.venderIngresso(sessao4->getChaveSessao(), "A01");
    Cineart.venderIngresso(sessao4->getChaveSessao(), "B01");
    Cineart.venderIngresso(sessao4->getChaveSessao(), "C01");
    Cineart.venderIngresso(sessao4->getChaveSessao(), "C02");
    Cineart.venderIngresso(sessao4->getChaveSessao(), "C03");
    Cineart.venderIngresso(sessao4->getChaveSessao(), "D01");
    Cineart.venderIngresso(sessao4->getChaveSessao(), "D02");
    Cineart.venderIngresso(sessao4->getChaveSessao(), "D03");


    //publico total
    CHECK(Cineart.getFilme("Rei Leão")->getPublicoTotal()==8);
    CHECK(Cineart.getFilme("Titanic")->getPublicoTotal()==18);
    
    //valor total arrecadado de um filme
    CHECK(Cineart.getFilme("Rei Leão")->getVerbaArrecadada()-300.24 < 0.1);
    CHECK(Cineart.getFilme("Titanic")->getVerbaArrecadada()-647.2 < 0.1);

    //ticket medio de um filme
    CHECK(Cineart.getFilme("Rei Leão")->getTicketMedio()-37.53 < 0.1);
    CHECK(Cineart.getFilme("Titanic")->getTicketMedio()-35.95 < 0.1);

    //valor total arrecadado do cinema
    CHECK(Cineart.getVerbaArrecadada()-947.4 < 0.1);

    //DESALOCANDO MEMÓRIA
    delete salaComum;
    delete salaIMAX;
    delete salaPremium;
    delete sala3D;
    delete distribuidor;
    delete ReiLeao;
    delete Titanic;
    delete sessao1;
    delete sessao2;
    delete sessao3;
    delete sessao4;
}

TEST_CASE("17 - Testando o lucro do cinema e porcentagem do distribuidor"){
    
    Cinema Cineart("Cineart");

    //Definição e cadastro de salas
    Sala *salaComum = new Sala(1,6,20);
    Sala *salaIMAX = new IMAX(2,5,20);
    Cineart.armazenarNovaSala(*salaComum);
    Cineart.armazenarNovaSala(*salaIMAX);

    //Definição e cadastro de distribuidores
    Distribuidor *distribuidor1 = new Distribuidor("Henrique Lisboa", 1);
    Distribuidor *distribuidor2 = new Distribuidor("Andressa Nowasyk", 2);
    Cineart.armazenarNovoDistribuidor(*distribuidor1);
    Cineart.armazenarNovoDistribuidor(*distribuidor2);

    //Definição e cadastro de filmes
    Filme *ReiLeao = new Filme("Rei Leão",1,90);
    Filme *ChefJack = new Filme("Chef Jack",2,90);
    Cineart.armazenarNovoFilme(*ReiLeao);
    Cineart.armazenarNovoFilme(*ChefJack);

    //Definição e cadastro de Sessões    
    Sessao *sessao1 = new Sessao(*salaComum,"Rei Leão", std::to_string(2019123010));
    Sessao *sessao2 = new Sessao(*salaIMAX, "Rei Leão", std::to_string(2019123010));
    Sessao *sessao3 = new Sessao(*salaComum,"Chef Jack", std::to_string(2019113010));
    Sessao *sessao4 = new Sessao(*salaIMAX, "Chef Jack", std::to_string(2019113010));
    Cineart.armazenarSessao(*salaComum,*sessao1);
    Cineart.armazenarSessao(*salaIMAX,*sessao2);
    Cineart.armazenarSessao(*salaComum,*sessao3);
    Cineart.armazenarSessao(*salaIMAX,*sessao4);

    //vendas
    int i;

    //vendendo 20 ingressos da sessao 1 -> valor total = 540,00;
    for(i=1; i < 21; i++){
        if(i < 10)
            Cineart.venderIngresso(sessao1->getChaveSessao(), "A0" + std::to_string(i));
        else
            Cineart.venderIngresso(sessao1->getChaveSessao(),"A"+ std::to_string(i));     
   }

    //vendendo 39 ingressos da sessao 2 -> valor total = 1263,60
    for(i=1; i < 21; i++){
        if(i < 10)
            Cineart.venderIngresso(sessao2->getChaveSessao(), "A0" + std::to_string(i));
        else
            Cineart.venderIngresso(sessao2->getChaveSessao(),"A"+ std::to_string(i));     
   }
   for(i=1; i < 20; i++){
        if(i < 10)
            Cineart.venderIngresso(sessao2->getChaveSessao(), "B0" + std::to_string(i));
        else
            Cineart.venderIngresso(sessao2->getChaveSessao(),"B"+ std::to_string(i));     
   }
    //vendendo 13 ingressos da sessão 3 = 351,00
    for(i=1; i < 14; i++){
        if(i < 10)
            Cineart.venderIngresso(sessao3->getChaveSessao(), "A0" + std::to_string(i));
        else
            Cineart.venderIngresso(sessao3->getChaveSessao(),"A"+ std::to_string(i));     
   }
   //vendendo 14 ingressos da sessão 4 = 453,60
   for(i=1; i < 15; i++){
        if(i < 10)
            Cineart.venderIngresso(sessao4->getChaveSessao(), "A0" + std::to_string(i));
        else
            Cineart.venderIngresso(sessao4->getChaveSessao(),"A"+ std::to_string(i));     
   }

   //conferindo a verba arrecadada total
   CHECK(Cineart.getVerbaArrecadada()-2608.2 < 0.1);
   //conferindo o valor total arrecadado de cada filme 
   CHECK(Cineart.getFilme("Rei Leão")->getVerbaArrecadada()-1803.6 < 0.1);
   CHECK(Cineart.getFilme("Chef Jack")->getVerbaArrecadada()-804.6 < 0.1);

   //conferindo a porcentagem de cada distribuidor = 0.4
   CHECK(Cineart.getDistribuidor(1)->getValorTotalArrecadado()-(1803.6*0.4) < 0.1);
   CHECK(Cineart.getDistribuidor(2)->getValorTotalArrecadado()-(804.6*0.4) < 0.1);

    //DESALOCANDO MEMÓRIA
    delete salaComum;
    delete salaIMAX;
    delete ReiLeao;
    delete ChefJack;
    delete sessao1;
    delete sessao2;
    delete sessao3;
    delete sessao4;
    delete distribuidor1;
    delete distribuidor2;

}

