#ifndef SIM_HPP
#define SIM_HPP
#include <string>

struct simulador{
    void lerArquivo(std::string nomeArquivo);
    void rodarComando(std::string estrutura, std::string operacao, int parametro, int parametro2);
};


#endif
