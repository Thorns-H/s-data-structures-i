#include <iostream>
#include <stdlib.h>
#include "Tacos.h"

/*
    - Seminario de Estructura de Datos I
    - Abraham Magaña Hernández - 220791217
    - Clase del 21-01-2021 
*/

// $ g++ 21-01-2021.cpp && ./a.out && rm a.out

#ifdef _WIN32 // Declaring constants for Windows

#define clear "cls"
#define pause "PAUSE"

#else // Declaring constants for Linux

#define clear "clear"
#define pause "read -p '' var"

#endif

using std::string; // Using this only for comfort 
using std::cout;
using std::endl;

int main(){

    // Creating our objects

    Tacos taco("Tripa", 20);
    Tacos tacoDos;

    // Using getters and setters

    cout << "\n- Tipo del primer Taco: " << taco.getTipo() << "." << endl;
    cout << "- Costo del segundo Taco: " << tacoDos.getCosto() << ".\n" << endl;

    // Applying methods

    taco.preparar(5);
    tacoDos.serComido();
    tacoDos.serComido();
    tacoDos.serComido();
    tacoDos.ponerSalsa();

    return 0;
}