#include <iostream>
#include <stdlib.h>
#include "Tacos.h"
#include "Lista.h"

/*
    - Seminario de Estructura de Datos I
    - Abraham Magaña Hernández - 220791217
    - Clase del 28-01-2022 
*/

// $ g++ 28-01-2022.cpp && ./a.out && rm a.out

#ifdef _WIN32 // Declaring constants for Windows

#define clear "cls"
#define pause "PAUSE"

#else // Declaring constants for Linux

#define clear "clear"
#define pause "read -p '' var"

#endif

using std::string; // Using this only for comfort 

void Pointers(){
    int value = 10;
    int *ptr = &value;

    std::cout << "- ¿Donde esta mi puntero?: " << ptr << std::endl;
    std::cout << "\n- El valor de mi variable usando (*): "<< *ptr << std::endl;
    std::cout << "- El valor de mi variable usando (&): " << &ptr <<  std::endl;
}

void TacoExample(){
    Tacos *asada = new Tacos("Asada", 15.90);
    std::cout << asada->getCosto() << std::endl;
}

int main(){

    system(clear);
    // Pointers();
    // TacoExample();

    List myList;
    myList.Initial();

    myList.Insert(10);
    myList.Insert(20);
    myList.Insert(15);

    myList.PrintIn();

    myList.Delete(0);

    myList.PrintIn();
    
    return 0;
}