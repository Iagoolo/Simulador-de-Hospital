#include "utils.hpp"
#include <iostream>
#include <limits>

void clearTerminal() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void clearTerminalAfterEnter() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\nPressione Enter para continuar...";
    std::cin.get();
    clearTerminal();
}

void exibirMensagemErro(const std::string& mensagem) {
    std::cout << "ERRO: " << mensagem << "\n";
}

int lerOpcaoMenu(const std::string& mensagem) {
    int opcao;
    while (true) {
        opcao = lerInteiro(mensagem);
        if (opcao >= 1 && opcao <= 6) return opcao;
        exibirMensagemErro("Opção inválida! Escolha entre 1 e 7.");
    }
}

int lerInteiro(const std::string& mensagem) {
    int valor;
    while (true) {
        std::cout << mensagem;
        std::cin >> valor;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            exibirMensagemErro("Entrada inválida! Digite um número inteiro.");
        } else {
            return valor;
        }
    }
}

long long lerCpf(const std::string& mensagem) {
    long long cpf;
    while (true) {
        std::cout << mensagem;
        std::cin >> cpf;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            exibirMensagemErro("Entrada inválida! Digite um número inteiro.");
        } else if (cpf < 10000000000LL || cpf > 99999999999LL) {
            exibirMensagemErro("CPF deve ter 11 dígitos.");
        } else {
            return cpf;
        }
    }
}

void consultarPaciente(const FilaPacientes& fila){

    std::cout << "Digite o número de cpf do paciente: ";
    long long cpf;
    std::cin >> cpf;

    Paciente* p = fila.consultarPaciente (cpf);
    
    if (p != nullptr) {
        std::cout << *p << std::endl;
    } else {
        std::cout << "Paciente não encontrado." << std::endl;
    }
}

void atenderPaciente(FilaPacientes& fila, PilhaHistorico& pilha) {
    try {
        Paciente paciente = fila.atenderPaciente();
        std::cout << "Atendeu paciente " << paciente.getNome() << "\n";
        pilha.registrarOperacao("Atendeu paciente " + paciente.getNome());
    } catch (std::out_of_range&) {
        exibirMensagemErro("Não há pacientes na fila para atender");
    }
}

void adicionarPaciente(FilaPacientes& fila, PilhaHistorico& pilha) {
    std::string nome;
    std::cout << "Nome: ";
    std::getline(std::cin >> std::ws, nome);
    
    long long cpf;
    while (true) {
        cpf = lerCpf("CPF: ");
        if (fila.verificarCpf(cpf)) {
            exibirMensagemErro("CPF já cadastrado");
        } else {
            break;
        }
    }
    
    int idade = lerInteiro("Idade: ");
    int prioridade = lerInteiro("Prioridade: ");

    Paciente paciente(nome, cpf, idade, prioridade);
    fila.adicionarPaciente(paciente);
    pilha.registrarOperacao("Adicionou paciente " + paciente.getNome());
}