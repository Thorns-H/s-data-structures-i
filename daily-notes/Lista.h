#include <iostream>

class Node{
    public:
        Node(){};
    private:
        Node *next;
        int value;
        friend class List;
};

class List{
    public:
        List(){};
        void Initial();
        void Insert(int);
        void InsertLast(int);
        Node Return(int);
        void PrintIn();
        bool Empty();
        void Delete(int);     
    private:
        Node *header;
};

void List::Initial(){
    this->header = nullptr;
}

void List::Insert(int value){

    Node *aux = new Node;
    aux->value = value;
    aux->next = nullptr;    

    if(Empty()){
        header = aux;
    }else{
        aux->next = header;
        header = aux;
    }
}

void List::InsertLast(int value){

    Node *tmp = new Node;
    tmp->value = value;
    tmp->next = nullptr;

    if(Empty()){
        header = tmp;
    }else{
        Node *aux;
        aux = header;
        while(aux->next){
            aux = aux->next;    
        }
        aux->next = tmp;
    }
}

Node List::Return(int value){
    Node *aux = this->header;

    if(Empty()){
        return *header;
    }else{
        while(aux){
            if(aux->value == value){
                return *aux;
            }
        }
    }
}

bool List::Empty(){
    if(this->header){ return false; }
    else{ return true; }
}

void List::PrintIn(){

    Node *aux;
    aux = header;
    int i = 1;
    std::cout << '\n';

    while(aux){
        std::cout << "\t[" << i << "] - " << aux->value << '\n';
        aux = aux->next;
        i++;
    }
}

void List::Delete(int value){

    Node *aux, *behind;
    aux = header;

    if(header->value == value){
        header = header->next;
    }else{
        while(aux){
            if(aux->next->value == value){
                break;
            }
            aux = aux->next;
        }
        behind = aux;
        aux = aux->next;
        behind->next = aux->next;
    }
    delete aux;
}