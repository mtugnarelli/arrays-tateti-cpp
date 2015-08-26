
#include "juego.h"

void inicializar(TableroTaTeTi tablero) {

    for (int fila = 0; fila < TAMANIO; fila++) {

        for (int columna = 0; columna < TAMANIO; columna++) {

            tablero[fila][columna] = VACIO;
        }
    }
}

bool tieneCasillerosVacios(TableroTaTeTi tablero) {

    bool existeCasilleroVacio = false;

    for (unsigned int fila = 0; (fila < TAMANIO) && (! existeCasilleroVacio); fila++) {

        for (unsigned int columna = 0; (columna < TAMANIO) && (! existeCasilleroVacio); columna++) {

            existeCasilleroVacio = (tablero[fila][columna] == VACIO);
        }
    }

    return existeCasilleroVacio;
}

bool formaLinea(TableroTaTeTi tablero) {

    bool formaLinea = formaLineaEnDiagonal(tablero) || formaLineaEnDiagonalSecundaria(tablero);

    for (unsigned int posicion = 0; (! formaLinea) && (posicion < TAMANIO); posicion++) {

        formaLinea = (formaLineaEnFila(tablero, posicion) || formaLineaEnColumna(tablero, posicion));
    }

    return formaLinea;
}

bool formaLineaEnFila(TableroTaTeTi tablero, unsigned int fila) {

    CasilleroTaTeTi casilleroInicial = tablero[fila][0];

    bool formaLinea = (casilleroInicial != VACIO);

    for (unsigned int columna = 1; formaLinea && (columna < TAMANIO); columna++) {

        formaLinea = (casilleroInicial == tablero[fila][columna]);
    }

    return formaLinea;
}

bool formaLineaEnColumna(TableroTaTeTi tablero, unsigned int columna) {

    CasilleroTaTeTi casilleroInicial = tablero[0][columna];

    bool formaLinea = (casilleroInicial != VACIO);

    for (unsigned int fila = 1; formaLinea && (fila < TAMANIO); fila++) {

        formaLinea = (casilleroInicial == tablero[fila][columna]);
    }

    return formaLinea;
}

bool formaLineaEnDiagonal(TableroTaTeTi tablero) {

    CasilleroTaTeTi casilleroInicial = tablero[0][0];

    bool formaLinea = (casilleroInicial != VACIO);

    for (unsigned int diagonal = 1; formaLinea && (diagonal < TAMANIO); diagonal++) {

        formaLinea = (casilleroInicial == tablero[diagonal][diagonal]);
    }

    return formaLinea;
}

bool formaLineaEnDiagonalSecundaria(TableroTaTeTi tablero) {

    CasilleroTaTeTi casilleroInicial = tablero[0][TAMANIO - 1];

    bool formaLinea = (casilleroInicial != VACIO);

    for (unsigned int diagonal = 1; formaLinea && (diagonal < TAMANIO); diagonal++) {

        formaLinea = (casilleroInicial == tablero[diagonal][TAMANIO - 1 - diagonal]);
    }

    return formaLinea;
}
