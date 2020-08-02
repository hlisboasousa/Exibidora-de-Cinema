#include <iostream>
#include <map>
#include "cinema.h"

Cinema::Cinema (std::string nome) {
    this->nomeDoCinema = nome;
    std::cout << "Bem-vindo ao " << this->nomeDoCinema << "!" << std::endl;
    this->lucro = 0;
    this->verbaArrecadada = 0;
}

Cinema::~Cinema () {  
}

std::map<int, Sala> Cinema::getSalas() {
    return this->listaSalas;
}

std::map<unsigned long long int, Pessoa> Cinema::getEmpregados() {
    return this->listaEmpregados;
}

std::map<std::string, Filme> Cinema::getFilmes() {
    return this->listaFilmes;
}

std::map<std::string, Sessao> Cinema::getSessoes() {
    return this->listaSessoes;
}

std::map<unsigned long long int, Distribuidor> Cinema::getDistribuidores() {
    return this->listaDistribuidores;
}

bool Cinema::isListaSalaVazia() {
    if ((this->getSalas()).empty()) {
        return true;
    } else {
        return false;
    }
}

Sessao * Cinema::getSessao(std::string chave_sessao) {
    return &(this->listaSessoes.find(chave_sessao)->second);
}

// verifica se o id do empregado já existe na lista do cinema
bool Cinema::isEmpregadoExistente(unsigned long long int id_empregado) {
    std::map<unsigned long long int, Pessoa>::iterator it;
    it = this->listaEmpregados.find(id_empregado); // estou pegando certo?
    if (it != this->listaEmpregados.end()) { // estou pegando certo?
        return true;
    } else {
        return false;
    }
}

// verifica se titulo do filme ja existe na lista
bool Cinema::isFilmeExistente(std::string nome_filme) {
    std::map<std::string,Filme>::iterator it;
    it = this->listaFilmes.find(nome_filme); // estou pegando certo?
    if (it != this->listaFilmes.end()) { // estou pegando certo?
        return true;
    } else {
        return false;
    }
}

// verifica se o id do distribuidor ja existe na lista
bool Cinema::isDistribuidorExistente(unsigned long long int id_distribuidor) {
    std::map<unsigned long long int,Distribuidor>::iterator it;
    it = this->listaDistribuidores.find(id_distribuidor); 
    if (it != this->listaDistribuidores.end()) {
        return true;
    } else {
        return false;
    }
}

// a sala sempre eh criada em sequencia a funcao pega o tamanho da lista e retorna +1 do tamanho
int Cinema::getProximaSalaASerCriada() {
    return (this->getSalas()).size()+1;
}

void Cinema::armazenarNovaSala(Sala sala) {
    (this->listaSalas).insert(std::pair<int, Sala>(sala.getNumero(),sala));
    std::cout << "Sala " << sala.getNumero() << " armazenada com sucesso!" << std::endl;
}

void Cinema::armazenarNovaPessoa(Pessoa pessoa) {
    
    if (isEmpregadoExistente(pessoa.getIdentificacao())) {
            std::cout << "O identificador já existe no sistema. Tente novamente." << std::endl;
    } else {
    this->listaEmpregados.insert(std::pair<unsigned long long int, Pessoa>(pessoa.getIdentificacao(),pessoa));
    std::cout << "Empregado " << pessoa.getNome() << " armazenado com sucesso!" << std::endl;
    }
}

void Cinema::armazenarNovoDistribuidor(Distribuidor distribuidor) {
    
    if (isDistribuidorExistente(distribuidor.getIdentificacao())) {
            std::cout << "O identificador já existe no sistema. Tente novamente." << std::endl;
    } else {
    this->listaDistribuidores.insert(std::pair<unsigned long long int, Distribuidor>(distribuidor.getIdentificacao(),distribuidor));
    std::cout << "Distribuidor " << distribuidor.getNome() << " armazenado com sucesso!" << std::endl;
    }
}

void Cinema::armazenarNovoFilme(Filme filme) {
    if (isFilmeExistente(filme.getTitulo())) {
                std::cout << "O título já existe no sistema. Tente novamente." << std::endl;
    } else {
        this->listaFilmes.insert(std::pair<std::string,Filme>(filme.getTitulo(),filme));
        std::cout << "Filme " << filme.getTitulo() << " armazenado com sucesso!" << std::endl;
    }
} 

void Cinema::armazenarSessao(Sala sala, Sessao sessao) {
    std::string chave_sessao;
    if (isSessaoExistente(sessao.getChaveSessao())) {
        std::cout << "Ja existe uma sessao na mesma sala, na mesma data/horário." << std::endl;
    } else {
        if (sala.getNumero() < 10) {
            chave_sessao = sessao.getDataHora() + "0" + std::to_string(sala.getNumero());
        } else {
            chave_sessao = sessao.getDataHora() + std::to_string(sala.getNumero());
        }
        std::cout << "Sessão " << chave_sessao << " criada com Sucesso!" << std::endl;
        this->listaSessoes.insert(std::pair<std::string,Sessao>(chave_sessao,sessao));
    }
}

bool Cinema::isSessaoExistente(Sessao sessao) {
    std::map<std::string,Sessao>::iterator it = this->listaSessoes.find(sessao.getChaveSessao());
    if (it != this->listaSessoes.end()) {
        return true;
    } else {
        return false;
    }
}

bool Cinema::isSessaoExistente(std::string chave_sessao) {
    std::map<std::string,Sessao>::iterator it = this->listaSessoes.find(chave_sessao);
    if (it != this->listaSessoes.end()) {
        return true;
    } else {
        return false;
    }
}

std::string Cinema::getNomeDoCinema() {
    return this->nomeDoCinema;
}

// imprime a lista de salas cadastradas no cinema
void Cinema::imprimirSalas() {
    std::map<int, Sala>::iterator it;
    it = this->listaSalas.begin(); // estou pegando certo?
    if (this->listaSalas.empty()) { // estou pegando certo?
        std::cout << "Não há salas Cadastradas ainda no " << this->getNomeDoCinema() << std::endl;
    } else {
        std::cout << "Sala\t| Capacidade\t| Tipo\t\t|" << std::endl;
        while (it != this->listaSalas.end()) { // estou pegando certo?
            std::cout << it->first << "\t| " << it->second.getCapacidade() << "\t\t|" << it->second.getTipo() << "\t\t|";
            std::cout << std::endl;
            ++it;
        }
    }
}

// imprime a lista de empregados cadastrados no cinema
void Cinema::imprimirEmpregados() {
    std::map<unsigned long long int, Pessoa>::iterator it;
    it = this->listaEmpregados.begin(); // estou pegando certo?
    if (this->listaEmpregados.empty()) { // estou pegando certo?
        std::cout << "Não há funcionários cadastrados no " << this->getNomeDoCinema() << std::endl;
    } else {
        std::cout << "ID\t\t| Nome\t\t\t| Nível|" << std::endl;
        while (it!= this->listaEmpregados.end()) { // estou pegando certo?
            std::cout << it->first << "\t| " << it->second.getNome() << "\t| " << it->second.getNivelDeAcesso() << "\t\t|";
            std::cout << std::endl;
            ++it;
        }
    }
}

void Cinema::imprimirDistribuidores() {
    std::map<unsigned long long int, Distribuidor>::iterator it;
    it = this->listaDistribuidores.begin(); // estou pegando certo?
    if (this->listaDistribuidores.empty()) { // estou pegando certo?
        std::cout << "Não há distribuidores cadastrados no " << this->getNomeDoCinema() << std::endl;
    } else {
        std::cout << "ID\t| Nome\t\t| Valor Arrecadado" << std::endl;
        while (it != this->listaDistribuidores.end()) { // estou pegando certo?
            std::cout << it->first << "\t| " << it->second.getNome() << "\t| " << it->second.getValorTotalArrecadado() << "\t\t|";
            std::cout << std::endl;
            ++it;
        }
    }
}


void Cinema::imprimirFilmesCadastrados() {
    std::map<std::string, Filme>::iterator it;
    it = this->listaFilmes.begin(); 
    if (this->listaFilmes.empty()) { 
        std::cout << "Não há filmes cadastrados no " << this->getNomeDoCinema() << std::endl;
    } else {
        std::cout << "Nome\t\t| Distribuidor\t\t| Valor Arrecadado\t| Publico\t| Ticket Médio" << std::endl;
        while (it != this->listaFilmes.end()) { 
            std::cout << it->first << "\t\t| " << this->listaDistribuidores.find(it->second.getDistribuidor())->second.getNome() << "\t\t| " << it->second.getVerbaArrecadada() << "\t\t| " << it->second.getPublicoTotal() << "\t| " << it->second.getTicketMedio();
            std::cout << std::endl;
            ++it;
        }
    }
}

void Cinema::imprimirFilmesEmCartaz() {
    // criar um mapa cuja chave é o nome dos filmes e o conteúdo é a quantidade de sessoes futuras existentes daquele filme.
    std::map<std::string, int> listaFilmeEmCartaz;
    std::map<std::string, int>::iterator it_filmes;
    std::map<std::string, Sessao>::iterator it_sessoes;
    
    it_sessoes = this->listaSessoes.begin();
    while (it_sessoes != this->listaSessoes.end()) {
        // primeiro preciso saber se a sessao que eu estou analisando é futura
        if (it_sessoes->second.isSessaoFutura()) {
            // se o filme existir, somar no contador interno dele
            if (listaFilmeEmCartaz.find(it_sessoes->second.getFilme()) != listaFilmeEmCartaz.end()) {
                listaFilmeEmCartaz.find(it_sessoes->second.getFilme())->second ++;
            } else { // se nao existir vou ter que adicionar e iniciar o contador com 1 (o filme existe em pelo menos uma sessao futura)
                listaFilmeEmCartaz.insert( std::pair<std::string, int>(it_sessoes->second.getFilme(), 1) );
            }
        }
        ++it_sessoes;
    }
    
    // agora é o processo de impressao do filme em cartaz
    it_filmes = listaFilmeEmCartaz.begin();
    if (it_filmes == listaFilmeEmCartaz.end()) {
        std::cout << "Não há filmes em Cartaz" << std::endl;
    } else {
        std::cout << "Filme \t\t| Qtde Sessoes \t\t" << std::endl;
        while (it_filmes != listaFilmeEmCartaz.end())
        {
            std::cout << it_filmes->first << "\t\t| " << it_filmes->second << std::endl;
            ++it_filmes;
        }
    }
    
}


void Cinema::imprimirSessoesFuturas() { 
    std::map<std::string, Sessao>::iterator it;
    it = this->listaSessoes.begin();
    if (this->listaSessoes.empty()) {
        std::cout << "Não há sessoes cadastradas no " << this->getNomeDoCinema() << std::endl;
    } else {
        std::cout << "Sessao\t\t| Sala\t\t| Filme\t\t" << std::endl;
        while (it != this->listaSessoes.end()) {
            // apenas se a sessao for posterior a hoje/agora que eu devo imprimir
            if (it->second.isSessaoFutura()) {
                std::cout << it->first << "\t| " << it->second.getSala().getNumero() << "-" << it->second.getSala().getTipo() << "\t| " << it->second.getFilme() << std::endl;
            }
            ++it;
        }
    }
}

Distribuidor * Cinema::getDistribuidor(unsigned long long int id) {
    return &this->listaDistribuidores.find(id)->second;
}

Distribuidor * Cinema::getDistribuidorPorNomeFilme(std::string filme) {
    return this->getDistribuidor(this->listaFilmes.find(filme)->second.getDistribuidor());
}

Distribuidor * Cinema::getDistribuidorPorFilmeSessao(std::string sessao) {
    return this->getDistribuidorPorNomeFilme(this->listaSessoes.find(sessao)->second.getFilme());
}

Filme * Cinema::getFilme (std::string filme) {
    return &this->listaFilmes.find(filme)->second;
}

Filme * Cinema::getFilmePorSessao(std::string sessao) {
    return this->getFilme(this->listaSessoes.find(sessao)->second.getFilme());
}

void Cinema::venderIngresso(std::string sessao, std::string assento) {
    float valorIngresso = this->listaSessoes.find(sessao)->second.getSala().getValorPorAssento();
    // primeiro eu ocupo o assento
    this->listaSessoes.find(sessao)->second.setAssentoOcupado(assento);
    // agora eu preciso adicionar na arrecadacao do distribuidor
    this->getDistribuidorPorFilmeSessao(sessao)->adicionarVendaIngresso(valorIngresso*PORCENTAGEMDISTRIBUIDOR);
    // agora eu preciso adicionar na arrecadação do filme
    this->getFilmePorSessao(sessao)->adicionarVendaIngresso(valorIngresso);
    // agora eu preciso adicionar na arrecadação geral do cinema
    this->verbaArrecadada += valorIngresso;
    this->lucro += valorIngresso*(1-PORCENTAGEMDISTRIBUIDOR);
}

float Cinema::getVerbaArrecadada(){
    return(this->verbaArrecadada);
}