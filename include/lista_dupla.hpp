#ifndef LISTA_HPP
#define LISTA_HPP

#include <cstdio>
#include <iostream>

template<typename T>
struct lista{
    class Node{
        T value;
        Node* prev;
        Node* next;

    };

    Node* first = nullptr;
    Node* last = nullptr;
    size_t nodeCount = 0;

    size_t size(){
        return nodeCount;
    }
    void insertAt(T value, size_t position);

    void removeAt(size_t position){
        if (position >= size()) {
            return;
        } 

        size_t currentPosition = 0;
        Node* previousNode = nullptr;
        Node* currentNode = first;

        while (currentPosition < position) {
            previousNode = currentNode;
            currentNode = currentNode->next;

            currentPosition++;
        }

        if (position == 0) {
            first = currentNode->next;
            delete currentNode;
            --nodeCount;
        } 
        else if(position == size()-1){ //Se deletar ultimo da lista, modificar last
            previousNode->next = currentNode->next;
            delete currentNode;
            --nodeCount;
            last = previousNode;
            last->next = previousNode->next;
            
        } else {
            previousNode->next = currentNode->next;
            delete currentNode;
            --nodeCount;
        }
    }

    void insertAtFront(T value);
    void removeAtFront(T value);
    void insertAtBack();
    void removeAtBack();

    void print(){
        if (size() == 0) {
            return;
        }

        Node* current = first;

        do {
            std::cout << current->value << std::endl;
            current = current->next;
        } while (current != nullptr);
    }
};

#endif
