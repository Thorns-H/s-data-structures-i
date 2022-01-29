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

    int opc, edad;
    string nombre;
    Lista MiLista;
    MiLista.Inicializar();
    Alumno Persona;

    do{
        system(clear);
        std::cout << "\t--- Menú Principal de Operaciones (Lista Simple) ---\n" << std::endl;
        std::cout << "\t\t 1.- Agregar Alumnos" << std::endl;
        std::cout << "\t\t 2.- Eliminar Alumnos" << std::endl;
        std::cout << "\t\t 3.- Imprimir la Lista" << std::endl;
        std::cout << "\t\t 4.- Comprobar Lista Vacia" << std::endl;
        std::cout << "\t\t 5.- Tamaño de Lista" << std::endl;
        std::cout << "\t\t 6.- Primer Alumno en Lista" << std::endl;
        std::cout << "\t\t 7.- Ultimo Alumno en Lista" << std::endl;
        std::cout << "\t\t 8.- Siguente Alumno en Lista" << std::endl;
        std::cout << "\t\t 9.- Anterior Alumno en Lista" << std::endl;
        std::cout << "\t\t 10.- Buscar Alumno" << std::endl;
        std::cout << "\t\t 11.- Anular Toda la Lista" << std::endl;

        std::cout << "\n\t Digita una opción ~ "; std::cin >> opc;
        switch (opc){
        case 1:
            std::cout << "\n\t- Nombre del Alumno: "; std::cin >> nombre;
            Persona.setNombre(nombre);
            std::cout << "\t- Edad del Alumno: "; std::cin >> edad;
            Persona.setEdad(edad);

            MiLista.Insertar(Persona); break;
        case 2:
            std::cout << "\n\t- Nombre del Alumno: "; std::cin >> nombre; 
            MiLista.Eliminar(nombre); break;
        case 3:
            MiLista.MostrarTodo();
            system(pause);
            break;
        case 4:
            if(MiLista.Vacia()){
                std::cout << "\n\t¡La Lista esta Vacia!" << std::endl;;
                system(pause);
            }else{
                std::cout << "\n\t¡La Lista NO esta Vacia!" << std::endl;;
                system(pause);
            }
            break;
        case 5:
            std::cout << "\n\t¡La Lista tiene registrados " << MiLista.Tamanio() << " Alumnos!" << std::endl;
            system(pause); break;
        case 6:
            std::cout << "\n\t¡El Primer Alumno de la Lista es " << MiLista.Primero().getNombre() << "!" << std::endl;;
            system(pause); break;
        case 7:
            std::cout << "\n\t¡El Ultimo Alumno de la Lista es " << MiLista.Ultimo().getNombre() << "!" << std::endl;;
            system(pause); break; 
        case 8:
            std::cout << "\n\t- Nombre del Alumno: "; std::cin >> nombre; 
            std::cout << "\n\t¡El Alumno Siguente a "<< nombre << " es " << MiLista.Siguente(nombre).getNombre()+"!" << std::endl; 
            system(pause); break;
        case 9:
            std::cout << "\n\t- Nombre del Alumno: "; std::cin >> nombre; 
            std::cout << "\n\t¡El Alumno Anterior a "<< nombre << " es " << MiLista.Anterior(nombre).getNombre()+"!" << std::endl; 
            system(pause); break;
        case 10:
            std::cout << "\n\t- Nombre del Alumno: "; std::cin >> nombre; 
            std::cout << "\n\t¡El Alumno "<< nombre << " esta guardado en el Nodo #: " << MiLista.Buscar(nombre) << "!" << std::endl; 
            system(pause); break;
        case 11:
            MiLista.EliminarTodo();
            break;
        }
    }while (opc != 12);

    return 0;
}