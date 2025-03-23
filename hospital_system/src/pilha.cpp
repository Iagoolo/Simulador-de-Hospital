#include <iostream>
#include "pilha.hpp"

void PilhaHistorico::registrarOperacao(const std::string& op) {
    // Criação de uma cópia da pilha para garantir que não alteramos a pilha original durante a verificação
    std::stack<std::string> historico = pilha;

    // Verifica se a operação já está registrada
    while (!historico.empty()) {
        if (historico.top() == op) {
            return;  // Se a operação já estiver na pilha, não registra novamente
        }
        historico.pop();
    }

    pilha.push(op);  // Adiciona a operação na pilha
}

std::string PilhaHistorico::desfazerOperacao() {
    if (!vazia()) {
        std::string operacao = pilha.top();
        pilha.pop();
        return operacao;
    } else {
        return "Nenhuma operação para desfazer";  // Caso a pilha esteja vazia
    }
}

bool PilhaHistorico::vazia() const {
    return pilha.empty();
}

void PilhaHistorico::exibirPilha(const std::stack<std::string>& pilha) const {
    std::stack<std::string> aux = pilha;  // Cria uma cópia da pilha para não alterar a original

    if (aux.empty()) {
        std::cout << "Nenhuma operação realizada." << std::endl; 
    } else {
        while (!aux.empty()) {
            std::cout << aux.top() << std::endl;
            aux.pop();
        }
    }

    std::cout << std::endl;
}

void PilhaHistorico::exibirPilha() const {
    exibirPilha(pilha);  // Chama a versão privada do método que exibe a pilha
}