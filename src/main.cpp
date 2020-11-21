#include <iostream>
#include <pilha.hpp>
#include <fila.hpp>
#include <lista_dupla.hpp>


int main(int argc, char* argv[]){
        lista<int> listaT;
        listaT.insertAtFront(1);
        listaT.insertAtFront(2);
        listaT.removeAtFront();
        listaT.removeAtFront();
        listaT.removeAtFront();
        

        listaT.print();      
        return 0;
}
