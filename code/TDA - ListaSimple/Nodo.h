#include "Alumno.h"

class Nodo{
    public:
        // Constructor
        Nodo(){};
    private:
        // Atributos
        Nodo *siguente;
        Alumno Persona;
    friend class Lista;
};