#include "Nodo.h"

class Lista{
    public:
        Lista(){};
        void Inicializar();
        bool Vacia(); //
        bool Existe(string);
        int Tamanio(); //
        void Imprimir(); //
        void ImprimirInvertido(); //
        void InsertarInicio(Alumno); //
        void InsertarFinal(Alumno); //
        void InsertarPosicion(Alumno, int); //
        void Eliminar(string); //
        void Anular();
        Nodo *Primero();
        Nodo *Ultimo();
        Nodo *Buscar(string);
        Nodo *Siguiente(string);
        Nodo *Anterior(string);
    private:
        Nodo *cabecera;
        Nodo *cola;
};

void Lista::Inicializar(){
    this->cabecera = nullptr;
    this->cola = nullptr;
}

bool Lista::Vacia(){
    if(this->cabecera and this->cola){
        return false;
    }else{
        return true;
    }
}

int Lista::Tamanio(){

    Nodo *aux = cabecera;
    int tamanio = 0;

    while(aux){
        aux = aux->siguiente;
        tamanio++;
    }

    return tamanio;
}

bool Lista::Existe(string nombre){
    
    Nodo *aux = this->cabecera;
    
    if(!Vacia()){
        while(aux){
            if(nombre == aux->Persona.getNombre()){
                return true;
            }
            aux = aux->siguiente;
        }
    }
    return false;
}

void Lista::InsertarInicio(Alumno Persona){
   
    Nodo *tmp = new Nodo;
    tmp->Persona = Persona;

    if(!Vacia()){
        tmp->siguiente = cabecera;
        this->cabecera->anterior = tmp;
        this->cabecera = tmp;
    }else{
        this->cabecera = tmp;
        this->cola = tmp;
    }
}

void Lista::InsertarFinal(Alumno Persona){
    
    Nodo *tmp = new Nodo;
    tmp->Persona = Persona;

    if(!Vacia()){
        tmp->anterior = cola;
        this->cola->siguiente = tmp;
        this->cola = tmp;
    }else{
        this->cabecera = tmp;
        this->cola = tmp;
    }
}

void Lista::InsertarPosicion(Alumno Persona, int Posicion){

    Nodo *tmp = new Nodo;
    tmp->Persona = Persona;

    if(!Posicion){
        InsertarInicio(Persona);
        delete tmp;
    }else if(Posicion == Tamanio()){
        InsertarFinal(Persona);
        delete tmp;
    }else{
        Nodo *aux = this->cabecera;

        for(int i = 0; i < Posicion; i++){
            aux = aux->siguiente;
        }
        aux->anterior->siguiente = tmp;
        tmp->siguiente = aux;
        tmp->anterior = aux->anterior;
        aux->anterior = tmp;
    }
}

void Lista::Eliminar(string nombre){

    if(Vacia()){
        std::cout << "¡NO hay valores para eliminar!" << std::endl;
    }else if(Existe(nombre)){

        Nodo *aux = this->cabecera;
        bool not_found = true;

        while(aux and not_found){ 
            if(nombre == aux->Persona.getNombre()){
                not_found = false;
            }else{
                aux = aux->siguiente;
            }
        }

        if(aux == cabecera and aux != cola){ // Si es el header
            cabecera = aux->siguiente;
            cabecera->anterior = nullptr;
            delete aux;
        }else if(aux == cabecera and aux == cola){ // Si solo hay un elemento
            cabecera = nullptr;
            cola = nullptr;
            delete aux;
        }else if(aux == cola and aux != cabecera){ // Si es el ultimo
            cola = aux->anterior;
            cola->siguiente = nullptr;
            delete aux;
        }else{ // Si esta en medio
            aux->anterior->siguiente = aux->siguiente;
            aux->siguiente->anterior = aux->anterior;
            delete aux;
        }
    }
}

void Lista::Anular(){
    
    if(!Vacia()){
        while(Tamanio() > 0){
            Eliminar(Primero()->Persona.getNombre());
        }
    }
}

Nodo* Lista::Primero(){

    if(!Vacia()){
        return this->cabecera;
    }
    return nullptr;
}

Nodo* Lista::Ultimo(){

    if(!Vacia()){
        return this->cola;
    }
    return nullptr;
}

Nodo* Lista::Buscar(string nombre){

    Nodo *aux = this->cabecera;

    if(!Vacia() and Existe(nombre)){
        while(aux){
            if(nombre == aux->Persona.getNombre()){
                return aux;
            }else{
                aux = aux->siguiente;
            }
        }
    }
    return nullptr;
}

Nodo* Lista::Siguiente(string nombre){

    Nodo *aux = this->cabecera;

    if(!Vacia() and Existe(nombre)){
        while(aux){
            if(nombre == aux->Persona.getNombre()){
                if(aux->siguiente){
                    return aux->siguiente;
                }else{
                    return nullptr;
                }
            }else{
                aux = aux->siguiente;
            }
        }
        return nullptr;
    }
    return nullptr;
}

Nodo* Lista::Anterior(string nombre){

    Nodo *aux = this->cabecera;

    if(!Vacia() and Existe(nombre)){
        while(aux){
            if(nombre == aux->Persona.getNombre()){
                if(aux->anterior){
                    return aux->anterior;
                }else{
                    return nullptr;
                }
            }else{
                aux = aux->siguiente;
            }
        }
        return nullptr;
    }
    return nullptr;
}

void Lista::Imprimir(){

    Nodo *aux = this->cabecera;
    int index = 1;

    if(Vacia()){
        std::cout << "  ¡NO hay elementos para mostrar, la lista esta vacia!\n";
    }else{
        while(aux){
            std::cout << "\t\t[" << index << "] - " << aux->Persona.getNombre()+", " << aux->Persona.getEdad() << " años." << std::endl;
            aux = aux->siguiente;
            index++;
        }
    }
}

void Lista::ImprimirInvertido(){

    Nodo *aux = this->cola;
    int index = Tamanio();

    if(Vacia()){
        std::cout << "¡NO hay elementos para mostrar, la lista esta vacia!";
    }else{
        while(aux){
            std::cout << "\t\t[" << index << "] - " << aux->Persona.getNombre()+", " << aux->Persona.getEdad() << " años." << std::endl;
            aux = aux->anterior;
            index--;
        }
    }
}