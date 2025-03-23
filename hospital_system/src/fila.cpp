#include <iostream>
#include "fila.hpp"

bool FilaPacientes::vazia() const {
    return fila.empty();  // Retorna verdadeiro se a fila estiver vazia
}

bool FilaPacientes::verificarCpf(const long long& cpf) const {
    // Procurando diretamente o CPF no unordered_set
    return pacientesEmFila.find(Paciente("", cpf, 0, 0)) != pacientesEmFila.end();
}

Paciente* FilaPacientes::consultarPaciente(const long long& cpf) const {
    // Criando um paciente fictício apenas com o CPF para realizar a busca
    auto it = pacientesEmFila.find(Paciente("", cpf, 0, 0));  // Procurando pelo CPF

    if (it != pacientesEmFila.end()) {
        // Retorna o ponteiro do paciente encontrado
        return const_cast<Paciente*>(&(*it));  // Retorna o endereço do paciente encontrado no unordered_set
    } else {
        // Se o paciente não for encontrado, retorna nullptr
        return nullptr;
    }
}

void FilaPacientes::adicionarPaciente(const Paciente& paciente) {
    
    // Verifica se o CPF já existe no unordered_set
    if (pacientesEmFila.find(paciente) != pacientesEmFila.end()) {
        std::cout << "Paciente com CPF " << paciente.getCpf() << " já está na fila!" << std::endl;
        return;  // Se já estiver, não adiciona
    }

    // Adiciona o paciente na fila
    fila.push(paciente);
    pacientesEmFila.insert(paciente);  // Adiciona o paciente ao unordered_set
}

Paciente FilaPacientes::atenderPaciente() {
    if (!vazia()) {
        Paciente paciente = fila.top();  // Guarda o paciente
        fila.pop();  // Remove o paciente da fila
        pacientesEmFila.erase(paciente);  // Remove o CPF do unordered_set
        std::cout << "Paciente atendido: " << paciente.getNome() << std::endl;
        return paciente;
    } else {
        throw std::out_of_range("A fila está vazia!");  // Exceção caso a fila esteja vazia
    }
}

void FilaPacientes::exibirFila() const {
    std::priority_queue<Paciente> fila2 = fila;

    if (fila2.empty()) {
        std::cout << "A fila está vazia" << std::endl;
    } else {
        while (!fila2.empty()) {
            std::cout << fila2.top() << std::endl;
            fila2.pop();
        }
    }

    std::cout << std::endl;
}
