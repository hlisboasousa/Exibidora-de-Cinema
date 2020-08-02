#ifndef premium_h
#define premium_h
#include "imax.h"
#include <iostream>


class Premium : public IMAX {
    private:
        static float taxaAdicionalPremium;

    public:
        Premium(int numero,int qtde_fileiras, int assentos_por_fileiras);
        ~Premium();
        void setTaxaAdicional(float) override;
        float getTaxaAdicional() override;
      
};
#endif