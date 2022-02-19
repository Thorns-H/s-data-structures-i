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
        void InsertarFinal(Alumno);
        void InsertarPosicion(Alumno, int);
        void Eliminar(string);
        Alumno Buscar(string);
        Alumno Primero();
        Alumno Ultimo();
        Alumno Siguente(string);
        Alumno Anterior(string);
        // Helpers Personales (Validaciones)
        bool Existe(string);
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
        delete aux;
    }
}

bool Lista::Vacia(){
    if(this->raiz){return false;}
    else{return true;}
}

int Lista::Tamanio(){

    Nodo *aux = raiz;
    int i = 0;

    if(Vacia()){return 0;}
    while(aux){
        i++;
        aux = aux->siguente;
    }
    return i;  
}

void Lista::MostrarTodo(){
    Nodo *aux;
    aux = raiz;
    int i = 1;

    std::cout << std::endl;

    while(aux){
        std::cout << "\t[" << i << "] - Alumno: " << aux->Persona.getNombre() << ", Edad: " << aux->Persona.getEdad() << std::endl; 
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

void Lista::InsertarFinal(Alumno Persona){

    Nodo *tmp = new Nodo;
    tmp->Persona = Persona;
    tmp->siguente = nullptr;

    if(Vacia()){
        raiz = tmp;
    }else{
        Nodo *aux;
        aux = raiz;
        while(aux->siguente){
            aux = aux->siguente;    
        }
        aux->siguente = tmp;
    }
}

void Lista::InsertarPosicion(Alumno Persona, int pos){

    Nodo *tmp = new Nodo;
    tmp->Persona = Persona;
    tmp->siguente = nullptr;

    if(Vacia()){
        raiz = tmp;
    }else{
        if(pos == 0){
            Insertar(Persona);
        }else{
            if(pos == Tamanio()){
            InsertarFinal(Persona);
        }else{
            Nodo *aux, *aux2;
            aux = raiz;

            for(int i = 0; i < pos; i++){
                aux2 = aux;
                aux= aux->siguente;
            }

            aux2->siguente = tmp;
            tmp->siguente = aux;
            }   
        }
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

Alumno Lista::Buscar(string Nombre){

    Nodo *aux;
    aux = raiz;
    
    if(!Vacia()){
        while(aux){
            if(aux->Persona.getNombre() == Nombre){
                return aux->Persona;
            }else{
                aux = aux->siguente;
            }
        }
    }
}

Alumno Lista::Primero(){
    if(this->raiz){
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

bool Lista::Existe(string Nombre){
    Nodo *aux = raiz;
    
    if(Vacia()){
        return false;
    }else{
        while(aux){
            if(aux->Persona.getNombre() == Nombre){ return true; }
            else{ aux = aux->siguente; }
        }
        return false;
    }
}