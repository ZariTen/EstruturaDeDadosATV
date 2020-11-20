#ifndef PILHA_HPP
#define PILHA_HPP

template <typename T>
struct pilha{
    struct Node{
        T value;
        Node* prev;
    };

    size_t count;
    Node* topo = nullptr;
    
    
    int size(){
     return count;   
    }
    
    void push(T value){
        if (topo != nullptr){
            Node* other = new Node();
            other->value = value;
            other->prev = topo;

            topo = other;
            ++count;
        }else {
            topo = new Node();
            topo->value = value;
            topo->prev = nullptr;
            ++count;
        }
    }
    
    T top(){ //TODO: lancar exceção caso não haja
        return topo->value;
    }
    
    void pop(){
        if (topo != nullptr){
            if(topo->prev != nullptr){ 
                Node* temp = topo->prev;
                delete topo;
                topo = temp;
                --count;
            }else{
                delete topo;
                topo = nullptr;
                count = 0;
            }
        }
    }
    
    
    ~pilha(){
        if (count == 0) {
            return;
        }

        Node* current = topo;

        while (current != nullptr) {
            Node* tmp = current->prev;
            delete current;
            current = tmp;
        }

        count = 0;
        topo = nullptr;
    }
};


#endif
