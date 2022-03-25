#include "Lista.h"

#ifdef _WIN32 // Declarando constantes de Windows

#define clear "cls"
#define pause "PAUSE"

#else // Declarando constantes de Linux

#define clear "clear"
#define pause "read -p '' var"

#endif

int main(){

    Lista miLista;
    miLista.Inicializar();
    string nombre;
    float precio;
    int opc, id, show_method = 0, insert_method, sort_method, pos;

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
            std::cout << "\t\t     [12] - Ordenamiento" << std::endl;
            std::cout << "\t\t     [13] - Salir" << std::endl;

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
                std::cout << "\n\t\t - Nombre del Producto: "; std::cin >> nombre;
                std::cout << "\t\t - ID del Producto: "; std::cin >> id;
                std::cout << "\t\t - Precio del Producto: "; std::cin >> precio;
                std::cout << "\t\t - Posición a Insertar: "; std::cin >> pos;

                if(pos - 1 > miLista.Tamanio()){
                    std::cout << "\n\t\t¡La posición es mayor al tamaño de la lista!" << std::endl;
                    std::cout << "\t\t  ¡Insertando el dato al final de la lista!" << std::endl;
                    system(pause);
                }

                Producto Nuevo(nombre,id,precio);
                miLista.InsertarPosicion(Nuevo,pos - 1);
            }else{
                std::cout << "\n\t\t - Nombre del Producto: "; std::cin >> nombre;
                std::cout << "\t\t - ID del Producto: "; std::cin >> id;
                std::cout << "\t\t - Precio del Producto: "; std::cin >> precio;
                
                Producto Nuevo(nombre,id,precio);
                if(insert_method == 1){
                    miLista.InsertarInicio(Nuevo);
                }else if(insert_method == 2){
                    miLista.InsertarFinal(Nuevo);
                }
            }
            break;
        case 5:
            std::cout << "\n\t\t - Nombre del Producto a Eliminar: "; std::cin >> nombre;
            if(miLista.Existe(nombre)){
                miLista.Eliminar(nombre);
            }else{
               system(clear);
               std::cout << "\n\t\t¡El Producto no existe en la Lista!" << std::endl;
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
            std::cout << "\n\t\t - Nombre del Producto a Buscar: "; std::cin >> nombre;
            if(!miLista.Vacia() and miLista.Existe(nombre)){
                std::cout << "\n\t\t¡La referencia de " << nombre << " es " << miLista.Buscar(nombre) << "!" <<  std::endl;
            }else{
                if(miLista.Vacia()){
                    std::cout << "\n\t\t¡La Lista esta Vacia!" << std::endl;
                }else{
                    std::cout << "\n\t\t¡Ese Producto no esta Registrado!" << std::endl;
                }
            }
            system(pause);
            break;
        case 10:
            std::cout << "\n\t\t - Nombre del Producto a Buscar: "; std::cin >> nombre;
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
                    std::cout << "\n\t\t¡Ese Producto no esta Registrado!" << std::endl;
                }
            }
            system(pause);
            break;
        case 11:
            std::cout << "\n\t\t - Nombre del Producto a Buscar: "; std::cin >> nombre;
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
                    std::cout << "\n\t\t¡Ese Producto no esta Registrado!" << std::endl;
                }
            }
            system(pause);
            break;
        case 12:
            system(clear);
            std::cout << "\n\t\t   --- Métodos de Ordenamiento ---" << std::endl;
            std::cout << "\n\t\t          [1] - BubbleSort" << std::endl;
            std::cout << "\t\t          [2] - InsertSort" << std::endl;
            std::cout << "\t\t          [3] - ShellSort" << std::endl;
            std::cout << "\t\t          [4] - SelectSort" << std::endl;
            std::cout << "\t\t          [5] - QuickSort" << std::endl;
            std::cout << "\t\t          [6] - MergeSort" << std::endl;
            std::cout << "\n\t\t     Selección -> "; std::cin >> sort_method;

            if(sort_method == 1){
                miLista.BubbleSort();
            }else if(sort_method == 2){
                miLista.InsertionSort();
            }else if(sort_method == 3){
                miLista.ShellSort();
            }else if(sort_method == 4){
                miLista.SelectSort();
            }else if(sort_method == 5){
                miLista.QuickSort(miLista, 0, miLista.Tamanio() - 1);
            }else if(sort_method == 6){
                miLista.MergeSort(0, miLista.Tamanio() / 2, miLista.Tamanio() - 1);
            }
        }
    }while(opc != 13);
    system(clear);
    return 0;
}
