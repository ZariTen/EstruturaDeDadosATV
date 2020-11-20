#include <iostream>
#include <pilha.hpp>


int main(int argc, char* argv[]){
        pilha<int> pilhaTeste;
        pilhaTeste.push(10);
        pilhaTeste.push(9);
        pilhaTeste.push(6);
        pilhaTeste.push(4);
        
        std::cout << pilhaTeste.top() << std::endl;
        pilhaTeste.pop();
        std::cout << pilhaTeste.top() << std::endl;
        pilhaTeste.push(4);
        std::cout << pilhaTeste.top() << std::endl;
        
        return 0;
}
