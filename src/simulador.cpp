#include <simulador.hpp>
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>

void simulador::lerComando(std::string localizacao,fila<int> &f, pilha<int> &p, lista<int> &l){
    std::string line;
        std::ifstream input(localizacao);
        std::string delimitador = " ";
        std::string token;
        std::string comandos[4];
        
        while(getline(input,line)){
            int pos = 0, cmdCount=0;
            if (!line.empty()){
                while((pos = line.find(delimitador)) != std::string::npos){
                    token = line.substr(0,line.find(delimitador));
                    comandos[cmdCount] = token;
                    line.erase(0, pos+ delimitador.length());
                    ++cmdCount;
                }
                comandos[cmdCount] = line;
                try{
                    int par2 = std::stoi(comandos[3]);
                    rodarComando(comandos[0],comandos[1],std::stoi(comandos[2]),par2,f,p,l);
                } catch (const std::invalid_argument& e){
                    rodarComando(comandos[0],comandos[1],std::stoi(comandos[2]),0,f,p,l);
                }
            }
        }
    
    
}

void simulador::rodarComando(std::string estrutura, std::string operacao, int parametro, int parametro2, fila<int> &f, pilha<int> &p, lista<int> &l){
    //std::cout << estrutura << operacao << parametro << parametro2 << std::endl;
    
    if(estrutura == "stack"){
        if (operacao == "size"){
            std::cout << "Tamanho da pilha: " << p.size() << std::endl;
        } else if(operacao == "push"){
            std::cout << "Inserindo elemento na pilha: " << parametro << std::endl;
            p.push(parametro);
        } else if(operacao == "top"){

        } else if(operacao == "pop"){

        }
    } else if(estrutura == "list"){
        
    } else if(estrutura == "queue"){
        
    }
}
