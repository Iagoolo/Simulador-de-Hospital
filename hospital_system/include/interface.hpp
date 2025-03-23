#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "utils.hpp"

// Enum para representar o estado do menu
enum class EstadoMenu {
    ExibirMenu,
    Sair
};

void executarSistema(FilaPacientes& fila, PilhaHistorico& pilha);

#endif