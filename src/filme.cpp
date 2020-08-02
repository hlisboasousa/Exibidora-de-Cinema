#include "filme.h"
#include <string>

Filme::Filme(std::string titulo, unsigned long long int id_distribuidor,int duracao_minutos) {
    this->titulo = titulo;
    this->distribuidor = id_distribuidor;
    this->duracao_minutos = duracao_minutos;
    this->publicoTotal = 0;
    this->ticketMedio = 0;
    this->verbaArrecadada =0;
}

Filme::~Filme() {

}

Filme::Filme() {
    
}

std::string Filme::getTitulo(){
    return(this->titulo);
}

unsigned long long int Filme::getDistribuidor(){
    return(this->distribuidor);
}

int Filme::getDuracaoMinutos() {
    return this->duracao_minutos;
}

// venda de 1 ingresso
void Filme::adicionarVendaIngresso(float valor) {
    this->verbaArrecadada += valor;
    this->publicoTotal ++;
    this->ticketMedio = (float) (this->verbaArrecadada/this->publicoTotal);
}

float Filme::getVerbaArrecadada() {
    return this->verbaArrecadada;
}

unsigned long long int Filme::getPublicoTotal() {
    return this->publicoTotal;
}

float Filme::getTicketMedio() {
    return this->ticketMedio;
}