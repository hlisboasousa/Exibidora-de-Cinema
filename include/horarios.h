#include <string>
#include <iostream>

// essa classe eh abstrata apenas para armazenar os horarios constantes das sessoes do cinema
// ainda nao sei como vou implementar isso
class Horarios {
    private:
        static const int hora1 = 10;
        static const int hora2 = 15;
        static const int hora3 = 18;
        static const int hora4 = 21;
    public:
        static std::string getHora(int hora);
};