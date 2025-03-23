#ifndef UTILS_HPP
#define UTILS_HPP

#include "fila.hpp"
#include "pilha.hpp"

// Função de leitura
int lerOpcaoMenu(const std::string& mensagem);
int lerInteiro(const std::string& mensagem);

//Função para limpar o terminal
void clearTerminal();
void clearTerminalAfterEnter();

// Funções específicas de operação
void exibirHistorico(const PilhaHistorico& pilha);
void exibirFila(const FilaPacientes& fila);
void consultarPaciente(const FilaPacientes& fila);
void atenderPaciente(FilaPacientes& fila, PilhaHistorico& pilha);
void adicionarPaciente(FilaPacientes& fila, PilhaHistorico& pilha);

#endif