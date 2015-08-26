
#include "juego.h"

int main() {

    TableroTaTeTi tablero;

    inicializar(tablero);

    do {



    } while (tieneCasillerosVacios(tablero) && ! formaLinea(tablero));

    return 0;
}


