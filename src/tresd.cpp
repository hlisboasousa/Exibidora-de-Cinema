#include "tresd.h"

float TresD::taxaAdicionalTresD = 8.00; //valor dos oculos

TresD::TresD(int numero, int qtde_fileiras, int assentos_por_fileiras) : IMAX(numero,qtde_fileiras,assentos_por_fileiras,"3D"){ 
   this->valorPorAssento = (Sala::valorPorAssentoComum * IMAX::taxaAdicionalIMAX) + TresD::taxaAdicionalTresD;
}

TresD::~TresD(){}

void TresD::setTaxaAdicional(float taxa){
    this->taxaAdicionalTresD = taxa;
}

float TresD::getTaxaAdicional(){
    return(taxaAdicionalTresD);
}