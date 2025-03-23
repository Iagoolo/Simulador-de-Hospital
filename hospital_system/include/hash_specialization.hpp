#ifndef HASH_SPECIALIZATION_HPP
#define HASH_SPECIALIZATION_HPP

#include "pacientes.hpp"
#include <functional>

namespace std{
    template <>
    struct hash<Paciente> {
        size_t operator() (const Paciente& p) const {
            return std::hash<long long>()(p.getCpf());
        }
    };
}

#endif