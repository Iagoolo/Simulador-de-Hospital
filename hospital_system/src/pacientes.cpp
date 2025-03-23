#include "pacientes.hpp"
#include <iostream>

Paciente::Paciente(std::string nome, long long cpf, int idade, int prioridade)
    : nome(nome), cpf(cpf), idade(idade), prioridade(prioridade) {}

long long Paciente::getCpf() const {
    return cpf;
}

std::string Paciente::getNome() const {
    return nome;
}

std::ostream& operator<<(std::ostream& os, const Paciente& p) {
    os << "Nome: " << p.nome
       << ", CPF: " << p.cpf
       << ", Idade: " << p.idade
       << ", Prioridade: " << p.prioridade;
    return os;
}

bool Paciente::operator<(const Paciente& other) const {
    return prioridade > other.prioridade;  // Maior prioridade é "menor" na comparação
}

bool Paciente::operator==(const Paciente& other) const {
    return cpf == other.cpf;
}
