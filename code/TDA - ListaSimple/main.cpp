#include <iostream>
#include "Lista.h"

#ifdef _WIN32 // Declarando constantes de Windows

#define clear "cls"
#define pause "PAUSE"

#else // Declarando constantes de Linux

#define clear "clear"
#define pause "read -p '' var"

#endif

using std::string;

int main(){

    int opc, edad, pos;
    string nombre;
    Lista MiLista;
    MiLista.Inicializar();
    Alumno Persona;

    do{
        system(clear);
        std::cout << "\t--- Menú Principal de Operaciones (Lista Simple) ---\n" << std::endl;
        std::cout << "\t\t 1.- Agregar Alumno al Inicio" << std::endl;
        std::cout << "\t\t 2.- Agregar Alumno al Final" << std::endl;
        std::cout << "\t\t 3.- Agregar Alumno por Posición" << std::endl;
        std::cout << "\t\t 4.- Eliminar Alumnos" << std::endl;
        std::cout << "\t\t 5.- Imprimir la Lista" << std::endl;
        std::cout << "\t\t 6.- Comprobar Lista Vacia" << std::endl;
        std::cout << "\t\t 7.- Tamaño de Lista" << std::endl;
        std::cout << "\t\t 8.- Primer Alumno en Lista" << std::endl;
        std::cout << "\t\t 9.- Ultimo Alumno en Lista" << std::endl;
        std::cout << "\t\t 10.- Siguente Alumno en Lista" << std::endl;
        std::cout << "\t\t 11.- Anterior Alumno en Lista" << std::endl;
        std::cout << "\t\t 12.- Buscar Alumno" << std::endl;
        std::cout << "\t\t 13.- Anular Toda la Lista" << std::endl;

        std::cout << "\n\t Digita una opción ~ "; std::cin >> opc;
        switch(opc){
        case 1:
            std::cout << "\n\t- Nombre del Alumno: "; std::cin >> nombre;
            Persona.setNombre(nombre);
            std::cout << "\t- Edad del Alumno: "; std::cin >> edad;
            Persona.setEdad(edad);

            MiLista.Insertar(Persona); break;
        case 2:
            std::cout << "\n\t- Nombre del Alumno: "; std::cin >> nombre;
            Persona.setNombre(nombre);
            std::cout << "\t- Edad del Alumno: "; std::cin >> edad;
            Persona.setEdad(edad);

            MiLista.InsertarFinal(Persona); break;
        case 3:
            std::cout << "\n\t- Nombre del Alumno: "; std::cin >> nombre;
            Persona.setNombre(nombre);
            std::cout << "\t- Edad del Alumno: "; std::cin >> edad;
            Persona.setEdad(edad);
            std::cout << "\t- Posición donde Agregar: "; std::cin >> pos;

            MiLista.InsertarPosicion(Persona, pos); break;
        case 4:
            std::cout << "\n\t- Nombre del Alumno: "; std::cin >> nombre; 
            if(MiLista.Existe(nombre)){
                MiLista.Eliminar(nombre); break;
            }else{
                std::cout << "\n\t¡El Alumno no existe en la Lista!" << std::endl;
                system(pause); break;
            }
        case 5:
            MiLista.MostrarTodo();
            system(pause); break;
        case 6:
            if(MiLista.Vacia()){
                std::cout << "\n\t\t¡La Lista esta Vacia!" << std::endl;;
                system(pause);
            }else{
                std::cout << "\n\t\t¡La Lista NO esta Vacia!" << std::endl;;
                system(pause);
            }
            break;
        case 7:
            std::cout << "\n\t¡La Lista tiene registrados " << MiLista.Tamanio() << " Alumnos!" << std::endl;
            system(pause); break;
        case 8:
            if(MiLista.Vacia()){
                std::cout << "\n\t¡La Lista esta Vacia!" << std::endl;
            }else{
                std::cout << "\n\t¡El Primer Alumno de la Lista es " << MiLista.Primero().getNombre() << "!" << std::endl;;
            }
            system(pause); break;
        case 9:
            if(MiLista.Vacia()){
                std::cout << "\n\t¡La Lista esta Vacia!" << std::endl;
            }else{
                std::cout << "\n\t¡El Ultimo Alumno de la Lista es " << MiLista.Ultimo().getNombre() << "!" << std::endl;;
            }
            system(pause); break; 
        case 10:
            std::cout << "\n\t- Nombre del Alumno: "; std::cin >> nombre; 
            if(MiLista.Existe(nombre) && MiLista.Ultimo().getNombre() != nombre){
                std::cout << "\n\t¡El Alumno Siguente a "<< nombre << " es " << MiLista.Siguente(nombre).getNombre()+"!" << std::endl; 
            }else{
                std::cout << "\n\t¡El Alumno no existe en la Lista o es el último!" << std::endl;
            }
            system(pause); break;
        case 11:
            std::cout << "\n\t- Nombre del Alumno: "; std::cin >> nombre;
            if(MiLista.Existe(nombre) && MiLista.Primero().getNombre() != nombre){
                std::cout << "\n\t¡El Alumno Anterior a "<< nombre << " es " << MiLista.Anterior(nombre).getNombre()+"!" << std::endl;
            }else{
                std::cout << "\n\t¡El Alumno no existe en la o es el primero!" << std::endl;
            }
            system(pause); break;
        case 12:
            std::cout << "\n\t- Nombre del Alumno: "; std::cin >> nombre;
            if(MiLista.Existe(nombre)){
                std::cout << "\n\t¡El Alumno "<< nombre << " tiene " << MiLista.Buscar(nombre).getEdad() << " años de edad y esta en la lista!" << std::endl; 
            }else{
                std::cout << "\n\t¡El Alumno no existe en la Lista!" << std::endl;
            }
            system(pause); break;
        case 13:
            MiLista.EliminarTodo();
            break;
        }
    }while (opc != 14);
    
    return 0;
}