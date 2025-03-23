#include <iostream>
#include <fstream>
#include <string>
#include "../include/pacientes.hpp"
#include "../include/fila.hpp"
#include "../include/arvore.hpp"
#include "../include/pilha.hpp"

void testarFila() {
    FilaPacientes fila;

    // Adicionando pacientes
    Paciente p1("João", 123456789, 30, 1);
    Paciente p2("Maria", 987654321, 40, 2);
    fila.adicionarPaciente(p1);
    fila.adicionarPaciente(p2);

    // Esperado: "João" deve sair primeiro por ter prioridade 1
    Paciente pacienteAtendido = fila.atenderPaciente();
    std::cout << "Paciente atendido (esperado João): " << pacienteAtendido << std::endl;

    pacienteAtendido = fila.atenderPaciente();
    std::cout << "Paciente atendido (esperado Maria): " << pacienteAtendido << std::endl;
}

void testarArvore() {
    ArvorePacientes arvore;

    // Adicionando pacientes
    Paciente p1("João", 123456789, 30, 1);
    Paciente p2("Maria", 987654321, 40, 2);
    arvore.inserir(p1);
    arvore.inserir(p2);
    Paciente* p3 = arvore.buscar(123456789);
    std::cout<<"João: " << *p3 << std::endl;

    // Removendo paciente
    arvore.remover(p1);

    // Verificando se a remoção funcionou corretamente
    std::cout << "Árvore após remover João:" << std::endl;
    arvore.exibirArvore();  // Assumindo que você tem um método `imprimir` para exibir pacientes na árvore
}

void testarPilha() {
    PilhaHistorico pilha;

    // Adicionando operações na pilha
    pilha.registrarOperacao("Operação 1");
    pilha.registrarOperacao("Operação 2");
    pilha.registrarOperacao("Operação 3");

    // Exibindo histórico antes de desempilhar
    std::cout << "Histórico de operações:" << std::endl;
    pilha.exibirPilha();

    // Desempilhando e verificando a ordem
    std::cout << "Operação desempilhada (esperado 'Operação 3'): " << pilha.desfazerOperacao() << std::endl;
    std::cout << "Operação desempilhada (esperado 'Operação 2'): " << pilha.desfazerOperacao() << std::endl;
    std::cout << "Operação desempilhada (esperado 'Operação 1'): " << pilha.desfazerOperacao() << std::endl;
}

int main() {
    // Rodando as funções de teste e imprimindo a saída no terminal
    testarFila();
    testarArvore();
    testarPilha();

    return 0;
}