#include <iostream>

using std::string;

class Alumno{
    public:
        Alumno(){};
        Alumno(string, int);
        void setNombre(string);
        void setEdad(int);
        string getNombre();
        int getEdad();
    private:
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
