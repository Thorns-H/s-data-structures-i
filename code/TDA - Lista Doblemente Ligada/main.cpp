#include "Lista.h"

int main(){

    Lista miLista;
    miLista.Inicializar();

    Alumno Abraham("Abraham",20);
    Alumno Gera("Gera",19);
    Alumno Diego("Diego",19);
    Alumno Javi("Javier", 19);

    miLista.InsertarFinal(Abraham);
    miLista.InsertarFinal(Gera);
    miLista.InsertarInicio(Diego);
    miLista.InsertarPosicion(Javi, 3);

    miLista.Imprimir();

    std::cout << std::endl;

    return 0;
}