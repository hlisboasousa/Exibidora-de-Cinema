#include "distribuidor.h"
#include "pessoa.h"
#include <string>

// o acessi default de cada distribuidor é o mesmo (0)
#define ACESSO_DISTRIBUIDOR 0

Distribuidor::Distribuidor(std::string nome,unsigned long long int identificacao) : Pessoa(nome, identificacao, ACESSO_DISTRIBUIDOR) {
    //Pessoa(nome,identificacao,acesso);
    this->ValorTotalArrecadado = 0;
}

Distribuidor::~Distribuidor() {

}

Distribuidor::Distribuidor() {
    
}

float Distribuidor::getValorTotalArrecadado() {
    return this->ValorTotalArrecadado;
}

void Distribuidor::adicionarVendaIngresso(float valor) {
    this->ValorTotalArrecadado += valor;
    this->ValorDisponivelParaSaque += valor;
}
