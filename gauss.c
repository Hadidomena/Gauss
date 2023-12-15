#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
    /**
  	 * Tutaj należy umieścić właściwą implemntację.
		 */
	for ( int x = 0; x < mat->r; x++ ) {

		for ( int y = x + 1; y < mat->r; y++ ) {
			if ( mat->data[y][x] != 0 ) {
				double wyznacznik = mat->data[x][x] / mat->data[y][x] ;
				for ( int z = x; z < mat->c; z++ ) {
					mat->data[y][z] -= mat->data[x][z] / wyznacznik; 	
				}	
				b->data[y][0] -= b->data[x][0] / wyznacznik;
			} else {
				return 1;
			}
		}

	}
	return 0;
}

