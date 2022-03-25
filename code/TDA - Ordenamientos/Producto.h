#include <iostream>

using std::string;

class Producto{
    public:
        Producto(){};
        Producto(string, int, float);

        void setNombre(string);
        void setId(int);
        void setPrecio(float);

        string getNombre();
        int getId();
        float getPrecio();
    private:
        string nombre;
        int id;
        float precio;
};

// Constructor

Producto::Producto(string nombre, int id, float precio){
    this->nombre = nombre;
    this->id = id;
    this->precio = precio;
}

// Setters

void Producto::setNombre(string nombre){
    this->nombre = nombre;
}

void Producto::setId(int id){
    this->id = id;
}

void Producto::setPrecio(float precio){
    this->precio = precio;
}

// Getters

string Producto::getNombre(){
    return this->nombre;
}

int Producto::getId(){
    return this->id;
}

float Producto::getPrecio(){
    return this->precio;
}