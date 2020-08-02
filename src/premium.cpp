#include "premium.h"
#include "imax.h"

float Premium::taxaAdicionalPremium = 1.7; //é aplicada à taxa IMAX

Premium::Premium(int numero, int qtde_fileiras, int assentos_por_fileiras) : IMAX(numero,qtde_fileiras,assentos_por_fileiras,"Premium"){ 
    this->valorPorAssento = Sala::valorPorAssentoComum * IMAX::taxaAdicionalIMAX * Premium::taxaAdicionalPremium;
}

Premium::~Premium(){}

void Premium::setTaxaAdicional(float taxa){
    this->taxaAdicionalPremium = taxa;
}

float Premium::getTaxaAdicional(){
    return(taxaAdicionalPremium);
}