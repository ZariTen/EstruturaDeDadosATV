#ifndef SIM_HPP
#define SIM_HPP
#include <pilha.hpp>
#include <fila.hpp>
#include <lista_dupla.hpp>
#include <string>

struct simulador{
    void lerComando(std::string localizacao, fila<int> &f , pilha<int> &p, lista<int> &l);
    void rodarComando(std::string estrutura, std::string operacao, int parametro, int parametro2,fila<int> &f, pilha<int> &p, lista<int> &l);
};


#endif
