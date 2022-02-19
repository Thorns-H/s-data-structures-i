#include "Alumno.h"

class Nodo{
    public:
        // Constructor
        Nodo(){};
    private:
        // Atributos
        Nodo *siguiente;
        Nodo *anterior;
        Alumno Persona;
    friend class Lista;
};
