#ifndef FILA_HPP
#define FILA_HPP

template <typename T>
struct fila{
    struct Node{
        T value;
        Node* prev;
    };

    int count = 0;    
    Node* first = nullptr;
    Node* last = nullptr;

    int size(){
       return count; 
    }

    void pushBack(T value){
        if (first != nullptr){
            Node* other = new Node();
            other->value = value;
            other->prev = nullptr;

            last->prev = other;
            last = other;
            ++count;
        } else{
            first = new Node();
            first->value = value;
            first->prev = nullptr;
            last = first;
            ++count;

        }
    }

    void popFront(){
        if (first != nullptr){
            if (first->prev != nullptr){
                Node* temp = first->prev;
                delete first;
                first = temp;
                --count;
            } else{
                delete first;
                first = nullptr;
                count = 0;
            }
        }


    }

    Node * front(){
        if (first != nullptr){
            return first; 
        } else{
            return nullptr;
        }
    }

    Node * back(){
        if (last != nullptr){
            return last;
        } else{
            return nullptr;
        }

    }

    ~fila(){ //Impedir vazamento de memoria
        if (count == 0){
            return;
        }

        Node* current = first;

        while(current != nullptr){
            Node* tmp = current->prev;
            delete current;
            current = tmp;
       }

       count = 0;
       first = nullptr;
       last = nullptr;

    }
};


#endif
