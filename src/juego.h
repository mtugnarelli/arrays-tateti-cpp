
#ifndef JUEGO_H_
#define JUEGO_H_


/* El Tablero será de TAMANIOxTAMANIO */
#define TAMANIO 3

/* Cada una de las posiciones que tiene el Tablero */
enum CasilleroTaTeTi {

    CRUZ, CIRCULO, VACIO
};

/* Tablero del Juego */
typedef CasilleroTaTeTi TableroTaTeTi[TAMANIO][TAMANIO];

void inicializar(TableroTaTeTi tablero);

bool tieneCasillerosVacios(TableroTaTeTi tablero);

bool formaLinea(TableroTaTeTi tablero);

bool formaLineaEnFila(TableroTaTeTi tablero, unsigned int fila);

bool formaLineaEnColumna(TableroTaTeTi tablero, unsigned int columna);

bool formaLineaEnDiagonal(TableroTaTeTi tablero);

bool formaLineaEnDiagonalSecundaria(TableroTaTeTi tablero);


#endif /* JUEGO_H_ */
