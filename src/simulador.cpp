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
            std::cout << "Elemento do topo da pilha: " << p.top()->value << std::endl;
        } else if(operacao == "pop"){
            std::cout << "Removendo elemento da pilha" << std::endl;
            p.pop();
        }
    } else if(estrutura == "list"){
       if (operacao == "print"){
            std::cout << "Imprimindo lista: " << std::endl;
            l.print();
       } else if(operacao == "insertAt"){
            std::cout << "Inserindo elemento na posição " << parametro << " da lista: " << parametro2 << std::endl;
            l.insertAt(parametro2,parametro);
       } else if(operacao == "removeAt"){
            std::cout << "Removendo elemento na posição " << parametro << " da lista" << std::endl;
            l.removeAt(parametro);
       } else if(operacao == "insertAtFront"){
            std::cout << "Inserindo elemento no inicio da lista: " << parametro << std::endl;
            l.insertAtFront(parametro);
       } else if(operacao == "insertAtBack"){
            std::cout << "Inserindo elemento no final da lista: " << parametro << std::endl;
            l.insertAtBack(parametro);
       } else if(operacao == "removeAtFront"){
            std::cout << "Removendo elemento do inicio da lista" << std::endl;
            l.removeAtFront();
       } else if(operacao == "removeAtBack"){
            std::cout << "Removendo elemento do final da lista" << std::endl;
            l.removeAtBack();
       } else if(operacao == "size"){
            std::cout << "Tamanho da lista: " << l.size() << std::endl;
       }
    } else if(estrutura == "queue"){
       if(operacao == "size"){
            std::cout << "Tamanho da fila: " << f.size();
       } else if(operacao == "pushBack"){
            std::cout << "Inserindo elemento na fila: " << parametro << std::endl;
            f.pushBack(parametro);
       } else if(operacao == "popFront"){
            std::cout << "Removendo elemento da fila" << std::endl;
            f.popFront();
       } else if(operacao == "front"){
            std::cout << "Primeiro elemento da fila: " << f.front()->value << std::endl;
       } else if(operacao == "back"){
            std::cout << "Último elemento da fila: " << f.back()->value << std::endl;
       }
    }
}
