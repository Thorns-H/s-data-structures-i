#include "Alumno.h"

class Nodo{
    public:
        Nodo();
        Nodo(Alumno);
    private:
        Nodo *siguiente;
        Nodo *anterior;
        Alumno Persona;
    friend class Lista;
};

Nodo::Nodo(){
    this->siguiente = nullptr;
    this->anterior = nullptr;
}

Nodo::Nodo(Alumno Nuevo){
    this->siguiente = nullptr;
    this->anterior = nullptr;
    this->Persona = Nuevo;
}