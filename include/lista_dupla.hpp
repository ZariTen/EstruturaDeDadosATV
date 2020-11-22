#ifndef LISTA_HPP
#define LISTA_HPP

#include <cstdio>
#include <iostream>

template<typename T>
struct lista{
    struct Node{
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

    void insertAt(T value, size_t position){
        if (position == size()+1){
            insertAtBack(value);

        } else if(position == 0){
            insertAtFront(value);
        } else if(position > 0 || position < size()+1){ //Verificar se position está dentro do tamanho
            Node* tmpPrev = first;
            Node* tmpNext = first->next;
            size_t loopCount = 0;

            while (loopCount != position-2){
                tmpPrev = tmpNext;
                tmpNext = tmpNext->next;
                ++loopCount;
            
            }

            Node* other = new Node();
            other->value = value;
            other->prev = tmpPrev;
            other->next = tmpNext;

            tmpPrev->next = other;
            tmpNext->prev = other;
            ++nodeCount;
        }
    }

    void removeAt(size_t position){
        if (position >= size()) {
            return;
        } 

        size_t currentPosition = 0;
        Node* previousNode = nullptr;
        Node* currentNode = first;

        while (currentPosition < position-1) {
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

    void insertAtFront(T value){
        Node* other = new Node();
        other->value = value;
        other->prev = nullptr;
        other->next = first;
        if (first != nullptr){
            first->prev = other;
        }
        if (nodeCount == 0){
            last = other;
        } else if (nodeCount == 1){
            last->prev = other;
        }
            
        first = other;
        ++nodeCount;
    }

    void removeAtFront(){
        if (first != nullptr){
            if (first->next != nullptr){
                Node* temp = first->next;
                delete first;
                first = temp;
                first->prev = nullptr;
                --nodeCount;
            }else{
                delete first;
                first = nullptr;
                nodeCount = 0;
            }
        }
    }

    void insertAtBack(T value){
        Node* other = new Node();
        if (last == nullptr){
            first = other;
            last = other;
        } else {
            last->next = other;
        }
        other->value = value;
        other->prev = last;
        other->next = nullptr;
        last = other;
        ++nodeCount;
    }

    void removeAtBack(){
        if (last != nullptr){
            if (last->prev != nullptr){
                Node* temp = last->prev;
                delete last;
                last = temp;
                last->next = nullptr;
                --nodeCount;
            } else{
                delete last;
                last = nullptr;
                nodeCount = 0;
            }
        }
    }

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

    ~lista(){
        if (size() == 0){
            return;
        }

        Node* current = first;

        while(current != nullptr){
            Node* tmp = current->next;
            delete current;
            current = tmp;
        }

        nodeCount = 0;
        first = nullptr;
        last = nullptr;

    }
};

#endif
