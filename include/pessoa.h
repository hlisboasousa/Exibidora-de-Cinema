#include <iostream>
#include <string>
#ifndef pessoa_h
#define pessoa_h

class Pessoa {
    private:
        std::string nome;
        unsigned long long int identificacao; // CPF ou CNPJ
        int nivelDeAcesso;
    public:
        Pessoa(std::string nome,unsigned long long int identificacao, int acesso);
        ~Pessoa();
        Pessoa();
        std::string getNome();
        unsigned long long int getIdentificacao();
        int getNivelDeAcesso();
};
#endif