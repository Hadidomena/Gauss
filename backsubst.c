#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int backsubst(Matrix *x, Matrix *mat, Matrix *b)
{
    int k; // iteracja po kolumnach
    int w; // iteracja po wierszach
    if (mat->c != mat->r || mat->r != b->r)
    {
        return 2;
    }
    for (w = x->r - 1; w >= 0; w--)
    {
        if (mat->data[w][w] != 0) // sprawdzenie czy element na diagonali nie jest rowny 0
        {
            x->data[w][0] = b->data[w][0] / mat->data[w][w];
            for (k = (x->r) - 1; k > w; k--)
            {
                x->data[w][0] -= x->data[k][0] * mat->data[w][k] / mat->data[w][w];
            }
        }
        else
        {
            return 1;
        }
    }

    return 0;
}
