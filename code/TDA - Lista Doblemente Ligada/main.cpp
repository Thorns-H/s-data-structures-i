#include "Lista.h"

int main(){

    Lista miLista;
    miLista.Inicializar();
    string nombre;
    int opc, edad, show_method = 0, insert_method, pos;

    do{
        system(clear);
        if(show_method == 1){
            std::cout << "\n\t   --- Lista en Orden Ascendente ---\n" << std::endl;
            miLista.Imprimir();
            std::cout << "\n\t\t     [0] - Volver" << std::endl;
            show_method = 0;
        }else if(show_method == 2){
            std::cout << "\n\t   --- Lista en Orden Descendente ---\n" << std::endl;
            miLista.ImprimirInvertido();
            std::cout << "\n\t\t     [0] - Volver" << std::endl;
            show_method = 0;
        }else{
            std::cout << "\n\t --- Lista Doblemente Ligada (Operaciones) ---" << std::endl;
            std::cout << "\n\t\t     [1] - Vacia" << std::endl;
            std::cout << "\t\t     [2] - Tamaño" << std::endl;
            std::cout << "\t\t     [3] - Imprimir" << std::endl;
            std::cout << "\t\t     [4] - Insertar" << std::endl;
            std::cout << "\t\t     [5] - Eliminar" << std::endl;
            std::cout << "\t\t     [6] - Anular" << std::endl;
            std::cout << "\t\t     [7] - Primero" << std::endl;
            std::cout << "\t\t     [8] - Último" << std::endl;
            std::cout << "\t\t     [9] - Buscar" << std::endl;
            std::cout << "\t\t     [10] - Siguiente" << std::endl;
            std::cout << "\t\t     [11] - Anterior" << std::endl;
            std::cout << "\t\t     [12] - Salir" << std::endl;

        }
        std::cout << "\n\t\t     Selección -> "; std::cin >> opc;
        switch (opc){
        case 0:
            system(clear); break;
        case 1:
            system(clear);

            if(miLista.Vacia()){
                std::cout << "\n\t\t¡La Lista esta Vacia!" << std::endl;
            }else{
                std::cout << "\n\t\t¡La Lista contiene Registros!" << std::endl;
            }
            system(pause);

            break;
        case 2:
            system(clear);

            if(!miLista.Vacia()){
                std::cout << "\n\t\t¡La Lista contiene " << miLista.Tamanio() << " elementos!" << std::endl;
            }else{
                std::cout << "\n\t\t¡No hay elementos para contar!" << std::endl;
            }

            system(pause);
            break;
        case 3:
            system(clear);
            std::cout << "\n\t\t   --- Métodos de Impresión ---" << std::endl;
            std::cout << "\n\t\t     [1] - Imprimir Normal" << std::endl;
            std::cout << "\t\t     [2] - Imprimir Invertido" << std::endl;
            std::cout << "\n\t\t     Selección -> "; std::cin >> show_method;
            break;
        case 4:
            system(clear);
            std::cout << "\n\t\t   --- Métodos de Inserción ---" << std::endl;
            std::cout << "\n\t\t     [1] - Insertar al Inicio" << std::endl;
            std::cout << "\t\t     [2] - Insertar al Final" << std::endl;
            std::cout << "\t\t     [3] - Insertar en una Posición" << std::endl;
            std::cout << "\n\t\t     Selección -> "; std::cin >> insert_method;

            if(insert_method == 3){
                std::cout << "\n\t\t - Nombre del Alumno: "; std::cin >> nombre;
                std::cout << "\t\t - Edad del Alumno: "; std::cin >> edad;
                std::cout << "\t\t - Posición a Insertar: "; std::cin >> pos;
                Alumno Nuevo(nombre,edad);
                miLista.InsertarPosicion(Nuevo,pos);
            }else{
                std::cout << "\n\t\t - Nombre del Alumno: "; std::cin >> nombre;
                std::cout << "\t\t - Edad del Alumno: "; std::cin >> edad;
                Alumno Nuevo(nombre,edad);
                if(insert_method == 1){
                    miLista.InsertarInicio(Nuevo);
                }else if(insert_method == 2){
                    miLista.InsertarFinal(Nuevo);
                }
            }
            break;
        case 5:
            std::cout << "\n\t\t - Nombre del Alumno a Eliminar: "; std::cin >> nombre;
            if(miLista.Existe(nombre)){
                miLista.Eliminar(nombre);
            }else{
               system(clear);
               std::cout << "\n\t\t¡El Alumno no existe en la Lista!" << std::endl;
               system(pause);
            }
            break;
        case 6:
            system(clear);
            miLista.Anular();
            std::cout << "\n\t\t¡La Lista ha sido Eliminada Totalmente!" << std::endl;
            system(pause);
            break;
        case 7:
            system(clear);
            if(!miLista.Vacia()){
                std::cout << "\n\t\t¡La primera referencia es " << miLista.Primero() << "!" <<  std::endl; 
            }else{
                std::cout << "\n\t\t¡La Lista esta Vacia!" << std::endl;
            }
            system(pause);
            break;
        case 8:
            system(clear);
            if(!miLista.Vacia()){
                std::cout << "\n\t\t¡La ultima referencia es " << miLista.Ultimo() << "!" <<  std::endl; 
            }else{
                std::cout << "\n\t\t¡La Lista esta Vacia!" << std::endl;
            }
            system(pause);
            break;
        case 9:
            std::cout << "\n\t\t - Nombre del Alumno a Buscar: "; std::cin >> nombre;
            if(!miLista.Vacia() and miLista.Existe(nombre)){
                std::cout << "\n\t\t¡La referencia de " << nombre << " es " << miLista.Buscar(nombre) << "!" <<  std::endl; 
            }else{
                if(miLista.Vacia()){
                    std::cout << "\n\t\t¡La Lista esta Vacia!" << std::endl;
                }else{
                    std::cout << "\n\t\t¡Ese Alumno no esta Registrado!" << std::endl;
                }
            }
            system(pause);
            break;
        case 10:
            std::cout << "\n\t\t - Nombre del Alumno a Buscar: "; std::cin >> nombre;
            if(!miLista.Vacia() and miLista.Existe(nombre)){
                if(miLista.Siguiente(nombre)){
                    std::cout << "\n\t\t¡La referencia siguiente es " << miLista.Siguiente(nombre) << "!" << std::endl; 
                }else{
                    std::cout << "\n\t\t¡No existe referencia siguiente a "<< nombre+"!" << std::endl; 
                }
            }else{
                if(miLista.Vacia()){
                    std::cout << "\n\t\t¡La Lista esta Vacia!" << std::endl;
                }else{
                    std::cout << "\n\t\t¡Ese Alumno no esta Registrado!" << std::endl;
                }
            }
            system(pause);
            break;
        case 11:
            std::cout << "\n\t\t - Nombre del Alumno a Buscar: "; std::cin >> nombre;
            if(!miLista.Vacia() and miLista.Existe(nombre)){
                if(miLista.Anterior(nombre)){
                    std::cout << "\n\t\t¡La referencia anterior es " << miLista.Anterior(nombre) << "!" << std::endl; 
                }else{
                    std::cout << "\n\t\t¡No existe referencia anterior a "<< nombre+"!" << std::endl; 
                }
            }else{
                if(miLista.Vacia()){
                    std::cout << "\n\t\t¡La Lista esta Vacia!" << std::endl;
                }else{
                    std::cout << "\n\t\t¡Ese Alumno no esta Registrado!" << std::endl;
                }
            }
            system(pause);
            break;
        }
    }while(opc != 12);
    system(clear);
    return 0;
}