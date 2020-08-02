#ifndef imax_h
#define imax_h
#include "sala.h"
#include <string>
#include <iostream>



class IMAX : public Sala {
    protected:
        static float taxaAdicionalIMAX;

    public:
        IMAX(int numero,int qtde_fileiras, int assentos_por_fileiras,std::string tipo);
        IMAX(int numero,int qtde_fileiras, int assentos_por_fileiras);
        ~IMAX();
        virtual void setTaxaAdicional(float taxa_adicional);
        virtual float getTaxaAdicional(); // é virtual para cada tipo de sala retornar sua proŕia taxa
        
};
#endif