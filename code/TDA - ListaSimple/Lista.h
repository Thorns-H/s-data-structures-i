#include "Nodo.h"

class Lista{
    public:
        // Métodos Normales
        void Inicializar(); 
        void EliminarTodo();
        bool Vacia();
        int Tamanio();
        void MostrarTodo();
        // Métodos Personalizados del Objeto
        void Insertar(Alumno);
        void Eliminar(string);
        int Buscar(string);
        Alumno Primero();
        Alumno Ultimo();
        Alumno Siguente(string);
        Alumno Anterior(string);
    private:
        Nodo *raiz;
};

void Lista::Inicializar(){
    this->raiz = nullptr;
}

void Lista::EliminarTodo(){
    Nodo *aux;

    while(aux){
        aux = raiz;
        raiz = nullptr;
        delete(aux);
    }
}

bool Lista::Vacia(){
    if(this->raiz){return false;}
    else{return true;}
}

int Lista::Tamanio(){

    Nodo *aux;
    aux = raiz;
    int i = 1;

    if(Vacia()){return 0;}

    while(aux){
        i++;
        aux = aux->siguente;
    }
    return i-1;  
}

void Lista::MostrarTodo(){
    Nodo *aux;
    aux = raiz;
    int i = 1;

    while(aux){
        std::cout << "[" << i << "] - Alumno: " << aux->Persona.getNombre() << ", Edad: " << aux->Persona.getEdad() << std::endl; 
        i++;
        aux = aux->siguente;
    }
}

void Lista::Insertar(Alumno Persona){

    Nodo *aux = new Nodo;
    aux->Persona = Persona;
    aux->siguente = nullptr;

    if(Vacia()){
        raiz = aux;
    }else{
        aux->siguente = raiz;
        raiz = aux;
    }
}

void Lista::Eliminar(string Nombre){
    Nodo *aux, *anterior;
    aux = raiz;

    if(Nombre == aux->Persona.getNombre()){
        raiz = raiz->siguente;
    }else{
        while(Nombre != aux->siguente->Persona.getNombre()){
            aux = aux->siguente;
        }
        anterior = aux;
        aux = aux->siguente;
        anterior->siguente = aux->siguente;
    }
        delete aux;
}

int Lista::Buscar(string Nombre){
    Nodo *aux;
    aux = raiz;
    int i = 1;

    while(Nombre != aux->Persona.getNombre()){
        aux = aux->siguente;
        i++;
    }
    if(Nombre == aux->Persona.getNombre()){
        return i;
    }
}

Alumno Lista::Primero(){
    if(raiz){
        return raiz->Persona;
    }
}

Alumno Lista::Ultimo(){
    Nodo *aux;
    aux = raiz;

    while(aux->siguente){
        aux = aux->siguente;
    }

    return aux->Persona;
}

Alumno Lista::Siguente(string Nombre){
    Nodo *aux;
    aux = raiz;

    while(Nombre != aux->Persona.getNombre()){
        aux = aux->siguente;
    }
    if(Nombre == aux->Persona.getNombre()){
        if(aux->siguente){
            return aux->siguente->Persona;
        }
    }
}

Alumno Lista::Anterior(string Nombre){
    Nodo *aux;
    aux = raiz;

    while(Nombre != aux->siguente->Persona.getNombre()){
        aux = aux->siguente;
    }
    return aux->Persona;
}