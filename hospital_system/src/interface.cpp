#include <iostream>
#include "interface.hpp"

void exibirMenu() {
    std::cout << "1. Adicionar paciente\n";
    std::cout << "2. Atender paciente\n";
    std::cout << "3. Exibir fila de pacientes\n";
    std::cout << "4. Exibir histórico de atendimentos\n";
    std::cout << "5. Consultar paciente\n";
    std::cout << "6. Sair\n";
}

EstadoMenu processarMenu(int opcao, FilaPacientes& fila, PilhaHistorico& pilha) {
    switch (opcao) {
        case 1:
            adicionarPaciente(fila, pilha);
            break;
        case 2:
            atenderPaciente(fila, pilha);
            break;
        case 3:
            fila.exibirFila();
            break;
        case 4:
            pilha.exibirPilha();
            break;
        case 5:
            consultarPaciente(fila); 
            break;
        case 6:
            std::cout << "Saindo...\n";
            return EstadoMenu::Sair;
        default:
            std::cout << "Opção inválida! Escolha entre 1 e 7.\n";
    }
    return EstadoMenu::ExibirMenu;
}

void executarSistema(FilaPacientes& fila, PilhaHistorico& pilha) {
    EstadoMenu estado = EstadoMenu::ExibirMenu;
    int opcao;
    
    while (estado != EstadoMenu::Sair) {
        clearTerminalAfterEnter();
        exibirMenu();
        std::cout << "\n";
        opcao = lerOpcaoMenu("Escolha uma opção: ");
        estado = processarMenu(opcao, fila, pilha);
    }
}