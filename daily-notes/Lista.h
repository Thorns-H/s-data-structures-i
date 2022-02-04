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

bool List::Empty(){
    if(this->header){return false;}
    else{return true;}
}

void List::PrintIn(){

    Node *aux;
    aux = header;
    int i = 0;
    std::cout << '\n';

    while(aux != nullptr){
        std::cout << "\t[" << i << "] - " << aux->value << '\n';
        aux = aux->next;
        i++;
    }
}

void List::Delete(int position){

    Node *aux, *behind;
    aux = header;

    if(position == 0){
        header = header->next;
    }else{
        
        for(int i = 0; i < position - 1; i++){
            aux = aux->next;
        }

        behind = aux;
        aux = aux->next;
        behind->next = aux->next;
    }

    delete aux;
}