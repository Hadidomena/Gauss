#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b)
{
    /**
     * Tutaj należy umieścić właściwą implemntację.
     */
    for (int x = 0; x < mat->r; x++)
    {
        if (mat->data[x][x] != 0)
        {
            for (int y = x + 1; y < mat->r; y++)
            {
                if (mat->data[y][x] != 0)
                {
                    double wyznacznik = mat->data[x][x] / mat->data[y][x];
                    for (int z = x; z < mat->c; z++)
                    {
                        mat->data[y][z] -= mat->data[x][z] / wyznacznik;
                    }
                    b->data[y][0] -= b->data[x][0] / wyznacznik;
                }
                else
                {
                }
            }
        }
        else
        {
			double *tmp1 = mat->data[x];
			double *tmp2 = b->data[x];
			int z = x;
			while ( mat->data[z][x] == 0 && z < mat->r ) { z++; }
			if ( z != mat->r ) {
				mat->data[x] = mat->data[z];
				b->data[x] = b->data[z];
				mat->data[z] = tmp1;
				b->data[z] = tmp2;
			}
			x--;
        }
    }
    return 0;
}
