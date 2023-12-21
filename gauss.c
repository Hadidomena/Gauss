#include "gauss.h"
int eliminate(Matrix *mat, Matrix *b)
{
    for (int x = 0; x < mat->r; x++)
    {
        if (mat->data[x][x] != 0) // jesli element na diagonali jest niezerowy mozemy dokonac normalnego zerowania kolumny
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
                } // jesli element w zerowanej kolumnie jest juz rowny 0 pomijamy ja
            }
        }
        else // ta czesc kodu odpowiada za zmiane kolejnosci wierszy
        {
            double *tmp1 = mat->data[x];
            double *tmp2 = b->data[x];
            int z = x;
            int max_index;
            int max = 0;
            while (z < mat->r)
            {
                if (mat->data[z][x] > max)
                {
                    max = mat->data[z][x];
                    max_index = z;
                }
                z++;
            }
            mat->data[x] = mat->data[max_index];
            b->data[x] = b->data[max_index];
            mat->data[max_index] = tmp1;
            b->data[max_index] = tmp2;
            x--;
        }
    }

    return 0;
}
