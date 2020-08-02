#include "imax.h"

float IMAX::taxaAdicionalIMAX = 1.2;

IMAX::IMAX(int numero, int qtde_fileiras, int assentos_por_fileiras) : Sala(numero,qtde_fileiras,assentos_por_fileiras,"IMAX") {
        setValorPorAssento(Sala::valorPorAssentoComum * IMAX::taxaAdicionalIMAX);
 }

IMAX::IMAX(int numero, int qtde_fileiras,int assentos_por_fileiras,std::string tipo) : Sala(numero,qtde_fileiras,assentos_por_fileiras,tipo) { }

IMAX::~IMAX(){}

void IMAX::setTaxaAdicional(float taxa){
    this->taxaAdicionalIMAX = taxa;
}

float IMAX::getTaxaAdicional(){
    return(IMAX::taxaAdicionalIMAX);
}