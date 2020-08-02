#include "horarios.h"
#include <string>

std::string Horarios::getHora(int hora) {
    std::string horario_escolhido;
    if (hora == 1) {
        horario_escolhido = std::to_string(Horarios::hora1);
    }

    if (hora == 2) {
        horario_escolhido = std::to_string(Horarios::hora2);
    }

    if (hora == 3) {
        horario_escolhido = std::to_string(Horarios::hora3);
    }

    if (hora == 4) {
        horario_escolhido = std::to_string(Horarios::hora4);
    }

    return horario_escolhido;
}