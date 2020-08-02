#include "pessoa.h"

Pessoa::Pessoa(std::string nome,unsigned long long int identificacao, int acesso) {
    this->nome = nome;
    this->identificacao = identificacao;
    this->nivelDeAcesso = acesso;
}

Pessoa::~Pessoa () {
    
}

Pessoa::Pessoa() {
    
}

unsigned long long int Pessoa::getIdentificacao() {
    return this->identificacao;
}

std::string Pessoa::getNome() {
    return this->nome;
}

int Pessoa::getNivelDeAcesso() {
    return this->nivelDeAcesso;
}

