#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Tacos{ // Creating the blueprint of my object "taco" 
    public:
        Tacos(string, float); // Constructor
        Tacos();

        // Setters & Getters

        float getCosto(); 
        void setCosto(float);
        string getTipo();
        void setTipo(string);

        // Methods

        void serComido();
        void preparar(int);
        void ponerSalsa();

    private:

        // Attributes

        string tipo;
        float costo;
        bool dobleTortilla;
        int cont;
};

// Constructor

Tacos::Tacos(string tipo, float costo){ 
    this->tipo = tipo;
    this->costo = costo;
    this->dobleTortilla = false;
}

Tacos::Tacos(){
    this->dobleTortilla = false;
    this->costo = 15;
}

// Setters & Getters

float Tacos::getCosto(){
    return this->costo;
}

void Tacos::setCosto(float costo){
    this->costo = costo;
}

string Tacos::getTipo(){
    return this->tipo;
}

void Tacos::setTipo(string tipo){
    this->tipo = tipo;
}

// Methods 

void Tacos::serComido(){
    cout << "Yummi, yummi! :)" << endl;
}

void Tacos::preparar(int cont){
    cout << "Preparando..." << endl;
    this->cont += cont;
    cout << "Lista de tu orden de " << cont << "." << endl;
}

void Tacos::ponerSalsa(){
    cout << "Le has puesto salsa a tu taquito de " << getTipo() << "." << endl;
}