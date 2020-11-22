#include <iostream>
#include <pilha.hpp>
#include <fila.hpp>
#include <lista_dupla.hpp>
#include <simulador.hpp>


int main(int argc, char* argv[]){
        //argv[1] = localização
        simulador s;
        fila<int> f;
        pilha<int> p;
        lista<int> l;
        
        if (argc < 1) {
            std::cout << "Uso: <localização das instruções>" << std::endl;
        }
        
        s.lerComando(argv[1],f,p,l);
        
        
        
        
        
 
        return 0;
}
