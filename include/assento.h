#ifndef assento_h
#define assento_h
#include <iostream>
#include <map>


class Assento {
    private:
        bool estaLivre;
    public:
        Assento(); // quando se cria um assento, ele automaticamente esta livre
        ~Assento();
        bool getAssentoEstaLivre();
        bool setOcuparAssento(); // retornar TRUE se o assento estiver livre e conseguirmos transforma-lo em ocupado
                                 // retornar FALSE se o assento ja estiver ocupado
        void imprimirAssento();
};
#endif