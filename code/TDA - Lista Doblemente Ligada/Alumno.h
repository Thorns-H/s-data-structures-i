#include <iostream>

#ifdef _WIN32 // Declarando constantes de Windows

#define clear "cls"
#define pause "PAUSE"

#else // Declarando constantes de Linux

#define clear "clear"
#define pause "read -p '' var"

#endif

using std::string;

class Alumno{
    public:
        // Constructores
        Alumno(){};
        Alumno(string, int);
        // Setters
        void setNombre(string);
        void setEdad(int);
        // Getters
        string getNombre();
        int getEdad();
    private:
        // Atributos
        string nombre;
        int edad;
};

// Constructor

Alumno::Alumno(string nombre, int edad){
    this->nombre = nombre;
    this->edad = edad;
}

// Setters

void Alumno::setNombre(string nombre){
    this->nombre = nombre;
}

void Alumno::setEdad(int edad){
    this->edad = edad;
}

// Getters

string Alumno::getNombre(){
    return this->nombre;
}

int Alumno::getEdad(){
    return this->edad;
}