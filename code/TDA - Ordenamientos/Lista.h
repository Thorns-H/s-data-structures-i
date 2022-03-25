#include "Nodo.h"

class Lista{
    public:
        Lista(){};
        void Inicializar();
        bool Vacia();
        bool Existe(string); 
        int Tamanio();
        void Imprimir();
        void ImprimirInvertido(); 
        void InsertarInicio(Producto);
        void InsertarFinal(Producto); 
        void InsertarPosicion(Producto, int); 
        void Eliminar(string);
        void Anular();
        Nodo *Primero();
        Nodo *Ultimo();
        Nodo *Buscar(string);
        Nodo *Siguiente(string);
        Nodo *Anterior(string);
        // Experimental
        void BubbleSort();
        void InsertionSort();
        void ShellSort();
        void SelectSort();
        void MergeSort(int, int, int);
        void QuickSort(Lista, int, int);
        // Testing
        Producto &operator[](const int&);
        int Particion(Lista, int, int);
    private:
        Nodo *cabecera;
        Nodo *cola;
};

Producto &Lista::operator[](const int &pos) {
    Nodo *aux = this->cabecera;

    for (int i = 0; i < pos; i++){
        aux = aux->siguiente;
    }

    return aux->articulo;
}

void Lista::BubbleSort(){

    Producto tmp;

    if(!Vacia()){
        for (int i = 0; i < Tamanio(); i++){
            bool flag = false;
            for (int j = 0; j < Tamanio() - i - 1; j++){  
                if((*this)[j].getPrecio() > (*this)[j+1].getPrecio()){
                    flag = true;
                    tmp = (*this)[j];
                    (*this)[j] = (*this)[j+1];
                    (*this)[j+1] = tmp;
                }
            }
            if(!flag){
                return;
            }
        }
    }
}

void Lista::InsertionSort(){
    int j;
    float key;

    for (int i = 1; i < Tamanio(); i++){
        key = (*this)[i].getPrecio();  
        j = i - 1;
        while (j > -1 and (*this)[j].getPrecio() > key){
            (*this)[j + 1] = (*this)[j];
            j--;
        }
        (*this)[j + 1].setPrecio(key);
    }
}

void Lista::ShellSort(){
    
    for (int gap = Tamanio() / 2; gap > 0; gap /= 2){
        for (int i = gap; i < Tamanio(); i += 1){

            int temp = (*this)[i].getPrecio();
            int j;

            for (j = i; j >= gap && (*this)[j - gap].getPrecio() > temp; j -= gap){
                (*this)[j] = (*this)[j - gap];
            }
            (*this)[j].setPrecio(temp);
        }
    }
}

void Lista::SelectSort(){ 

    int min_idx;
    Producto tmp;
  
    for (int i = 0; i < Tamanio() - 1; i++){ 

        min_idx = i;

        for (int j = i + 1; j < Tamanio(); j++){
            if ((*this)[j].getPrecio() < (*this)[min_idx].getPrecio()){
                min_idx = j; 
            } 
        } 
        tmp = (*this)[min_idx];
        (*this)[min_idx] = (*this)[i];
        (*this)[i] = tmp;
    } 
}

void Lista::QuickSort(Lista, int izq, int der){ 
    int i = izq;
    int j = der;
    float x;
    Producto aux;

    x = (*this)[(izq + der) / 2].getPrecio();

    do{ 
        while(((*this)[i].getPrecio() < x) && (j <= der)){ 
            i++;
        } 
        while((x < (*this)[j].getPrecio()) && (j > izq))  { 
            j--;
        } 
        if(i <= j){ 
            aux = (*this)[i]; 
            (*this)[i] = (*this)[j]; 
            (*this)[j] = aux; 
            i++;  j--; 
        }
    }while(i <= j); 
 
    if(izq < j){
        QuickSort((*this), izq, j); 
    }
    if(i < der){
        QuickSort((*this), i, der); 
    }
}

void Lista::MergeSort(int left, int middle, int right) {

    int n1 = middle - left + 1;
    int n2 = right - middle;

    float L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = (*this)[left + i].getPrecio();
    for (int j = 0; j < n2; j++)
        M[j] = (*this)[middle + 1 + j].getPrecio();

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            (*this)[k].setPrecio(L[i]);
            i++;
        }else{
            (*this)[k].setPrecio(M[j]);
            j++;
        }
        k++;
    }
    while (i < n1) {
        (*this)[k].setPrecio(L[i]);
        i++;
        k++;
    }
    while (j < n2) {
        (*this)[k].setPrecio(M[j]);
        j++;
        k++;
    }
}

void Lista::Inicializar(){
    this->cabecera = nullptr;
    this->cola = nullptr;
}

bool Lista::Vacia(){
    if(this->cabecera and this->cola){
        return false;
    }else{
        return true;
    }
}

int Lista::Tamanio(){

    Nodo *aux = this->cabecera;
    int tamanio = 0;

    while(aux){
        aux = aux->siguiente;
        tamanio++;
    }
    return tamanio;
}

bool Lista::Existe(string nombre){

    Nodo *aux = this->cabecera;

    if(!Vacia()){
        while(aux){
            if(nombre == aux->articulo.getNombre()){
                return true;
            }
            aux = aux->siguiente;
        }
    }
    return false;
}

void Lista::InsertarInicio(Producto articulo){

    Nodo *tmp = new Nodo;
    tmp->articulo = articulo;

    if(!Vacia()){
        tmp->siguiente = cabecera;
        this->cabecera->anterior = tmp;
        this->cabecera = tmp;
    }else{
        this->cabecera = tmp;
        this->cola = tmp;
    }
}

void Lista::InsertarFinal(Producto articulo){

    Nodo *tmp = new Nodo;
    tmp->articulo = articulo;

    if(!Vacia()){
        tmp->anterior = cola;
        this->cola->siguiente = tmp;
        this->cola = tmp;
    }else{
        this->cabecera = tmp;
        this->cola = tmp;
    }
}

void Lista::InsertarPosicion(Producto articulo, int Posicion){

    Nodo *tmp = new Nodo;
    tmp->articulo = articulo;

    if(!Posicion){
        InsertarInicio(articulo);
        delete tmp;
    }else if(Posicion == Tamanio()){
        InsertarFinal(articulo);
        delete tmp;
    }else{
        if(!Posicion > Tamanio()){
            Nodo *aux = this->cabecera;

            for(int i = 0; i < Posicion; i++){
                aux = aux->siguiente;
            }

            aux->anterior->siguiente = tmp;
            tmp->siguiente = aux;
            tmp->anterior = aux->anterior;
            aux->anterior = tmp;
        }else{
            InsertarFinal(articulo);
            delete tmp;
        }
    }
}

void Lista::Eliminar(string nombre){
    if(Vacia()){
        std::cout << "¡NO hay valores para eliminar!" << std::endl;
    }else if(Existe(nombre)){

        Nodo *aux = this->cabecera;
        bool not_found = true;

        while(aux and not_found){
            if(nombre == aux->articulo.getNombre()){
                not_found = false;
            }else{
                aux = aux->siguiente;
            }
        }

        if(aux == cabecera and aux != cola){
            cabecera = aux->siguiente;
            cabecera->anterior = nullptr;
            delete aux;
        }else if(aux == cabecera and aux == cola){
            cabecera = nullptr;
            cola = nullptr;
            delete aux;
        }else if(aux == cola and aux != cabecera){
            cola = aux->anterior;
            cola->siguiente = nullptr;
            delete aux;
        }else{
            aux->anterior->siguiente = aux->siguiente;
            aux->siguiente->anterior = aux->anterior;
            delete aux;
        }
    }
}

void Lista::Anular(){

    if(!Vacia()){
        while(Tamanio() > 0){
            Eliminar(Primero()->articulo.getNombre());
        }
    }
}

Nodo* Lista::Primero(){

    if(!Vacia()){
        return this->cabecera;
    }
    return nullptr;
}

Nodo* Lista::Ultimo(){

    if(!Vacia()){
        return this->cola;
    }
    return nullptr;
}

Nodo* Lista::Buscar(string nombre){

    Nodo *aux = this->cabecera;

    if(!Vacia() and Existe(nombre)){
        while(aux){
            if(nombre == aux->articulo.getNombre()){
                return aux;
            }else{
                aux = aux->siguiente;
            }
        }
    }
    return nullptr;
}

Nodo* Lista::Siguiente(string nombre){

    Nodo *aux = this->cabecera;

    if(!Vacia() and Existe(nombre)){
        while(aux){
            if(nombre == aux->articulo.getNombre()){
                if(aux->siguiente){
                    return aux->siguiente;
                }else{
                    return nullptr;
                }
            }else{
                aux = aux->siguiente;
            }
        }
        return nullptr;
    }
    return nullptr;
}

Nodo* Lista::Anterior(string nombre){

    Nodo *aux = this->cabecera;

    if(!Vacia() and Existe(nombre)){
        while(aux){
            if(nombre == aux->articulo.getNombre()){
                if(aux->anterior){
                    return aux->anterior;
                }else{
                    return nullptr;
                }
            }else{
                aux = aux->siguiente;
            }
        }
        return nullptr;
    }
    return nullptr;
}

void Lista::Imprimir(){

    Nodo *aux = this->cabecera;
    int index = 1;

    if(Vacia()){
        std::cout << "  ¡NO hay elementos para mostrar, la lista esta vacia!\n";
    }else{
        while(aux){
            std::cout << "\t\t[" << aux->articulo.getId() << "] - " << aux->articulo.getNombre()+", $" << aux->articulo.getPrecio() << "." << std::endl;
            aux = aux->siguiente;
            index++;
        }
    }
}

void Lista::ImprimirInvertido(){

    Nodo *aux = this->cola;
    int index = Tamanio();

    if(Vacia()){
        std::cout << "  ¡NO hay elementos para mostrar, la lista esta vacia!";
    }else{
        while(aux){
            std::cout << "\t\t[" << aux->articulo.getId() << "] - " << aux->articulo.getNombre()+", $" << aux->articulo.getPrecio() << "." << std::endl;
            aux = aux->anterior;
            index--;
        }
    }
}
