#include "sala.h"

float Sala::valorPorAssentoComum = 27.00;

Sala::Sala() {
    
}

Sala::Sala(int numero, int fileiras, int assentosPorFileiras) {
    this->tipo = "Comum";
    this->fileiras = fileiras;
    this->assentosPorFileiras = assentosPorFileiras;
    this->valorPorAssento = 27.00;
    this->numero = numero;
}

Sala::Sala(int numero,int fileiras, int assentosPorFileiras,std::string tipo) {
    this->tipo = tipo;
    this->fileiras = fileiras;
    this->assentosPorFileiras = assentosPorFileiras;
    this->valorPorAssento = 27.00;
    this->numero = numero;
}

Sala::~Sala() {
    
}


int Sala::getNumero() {
    return this->numero;
}

int Sala::getCapacidade() {
    return this->fileiras*this->assentosPorFileiras;
}

int Sala::getFileiras() {
    return this->fileiras;
}

int Sala::getAssentosPorFileiras() {
    return this->assentosPorFileiras;
}
float Sala::getValorPorAssento() {
    return this->valorPorAssento;
}

void Sala::setFileiras(int fileiras) {
    this->fileiras = fileiras;
}

void Sala::setAssentosPorFileiras(int assentosPorFileiras) {
    this->assentosPorFileiras = assentosPorFileiras;
}

void Sala::setValorPorAssento(float valor) {
    this->valorPorAssento = valor;
}

void Sala::setNumero(int numero) {
    this->numero = numero;
}

std::string Sala::getTipo() {
    return this->tipo;
}

