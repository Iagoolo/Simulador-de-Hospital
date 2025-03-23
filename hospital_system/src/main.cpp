#include <iostream>
#include "interface.hpp"

int main(){

    clearTerminal();
    
    std::cout << "Bem vindo ao simulador de atendimento hospitalar.\n";

    PilhaHistorico pilha;
    FilaPacientes fila;

    executarSistema(fila, pilha);

    return 0;
}