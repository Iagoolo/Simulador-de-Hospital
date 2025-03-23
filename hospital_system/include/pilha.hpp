#ifndef PILHA_HPP
#define PILHA_HPP

#include <stack>
#include <string>

class PilhaHistorico {
public:
    PilhaHistorico(){}
    void registrarOperacao(const std::string& op);
    std::string desfazerOperacao();
    bool vazia() const;
    void exibirPilha() const;

private:
    std::stack<std::string> pilha;
    void exibirPilha(const std::stack<std::string>& pilha) const;
};

#endif