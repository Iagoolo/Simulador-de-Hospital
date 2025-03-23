#ifndef PACIENTES_HPP
#define PACIENTES_HPP

#include <string>

class Paciente {
private:
    std::string nome;
    long long cpf;
    int idade;
    int prioridade;

public:
    Paciente(std::string nome, long long cpf, int idade, int prioridade);
    long long getCpf() const;
    std::string getNome() const;
    friend std::ostream& operator<<(std::ostream& os, const Paciente& p);
    bool operator<(const Paciente& other) const;
    bool operator==(const Paciente& other) const;
};

#endif
