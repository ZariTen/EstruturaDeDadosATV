#include <iostream>
#include <pilha.hpp>
#include <fila.hpp>


int main(int argc, char* argv[]){
        fila<int> filaTeste;
        filaTeste.pushBack(1);
        filaTeste.pushBack(2);

        std::cout << filaTeste.front()->value << std::endl;
        std::cout << filaTeste.back()->value << std::endl;
        filaTeste.popFront();
        std::cout << filaTeste.front()->value << std::endl;
        filaTeste.popFront();        
        return 0;
}
