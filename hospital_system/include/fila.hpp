#ifndef FILA_HPP
#define FILA_HPP

#include <queue>
#include <unordered_set>
#include "pacientes.hpp"
#include "hash_specialization.hpp"

class FilaPacientes {
public:
    void adicionarPaciente(const Paciente& paciente);
    Paciente atenderPaciente();
    bool vazia() const;
    void exibirFila() const;
    Paciente* consultarPaciente(const long long& cpf) const;
    bool verificarCpf(const long long& cpf) const;

private:
    std::priority_queue<Paciente> fila;
    std::unordered_set<Paciente> pacientesEmFila;  // Armazena CPFs dos pacientes para verificar duplicação
};

#endif
