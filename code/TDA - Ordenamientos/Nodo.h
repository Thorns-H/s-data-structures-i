#include "Producto.h"

class Nodo{
    public:
        Nodo();
        Nodo(Producto);
    private:
        Nodo *siguiente;
        Nodo *anterior;
        Producto articulo;
    friend class Lista;
};

Nodo::Nodo(){
    this->siguiente = nullptr;
    this->anterior = nullptr;
}

Nodo::Nodo(Producto registro){
    this->siguiente = nullptr;
    this->anterior = nullptr;
    this->articulo = registro;
}