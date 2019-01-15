// Author: Marek K.

/*

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Dieses Programm ist Freie Software: Sie koennen es unter den Bedingungen
    der GNU General Public License, wie von der Free Software Foundation,
    Version 3 der Lizenz oder (nach Ihrer Wahl) jeder neueren
    veroeffentlichten Version, weiter verteilen und/oder modifizieren.

    Dieses Programm wird in der Hoffnung bereitgestellt, dass es nuetzlich sein wird, jedoch
    OHNE JEDE GEWAEHR,; sogar ohne die implizite
    Gewaehr der MARKTFAEHIGKEIT oder EIGNUNG FUER EINEN BESTIMMTEN ZWECK.
    Siehe die GNU General Public License fuer weitere Einzelheiten.

    Sie sollten eine Kopie der GNU General Public License zusammen mit diesem
    Programm erhalten haben. Wenn nicht, siehe <http://www.gnu.org/licenses/>.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

typedef struct matrix_s
{
    int * * ptr;
    size_t x;
    size_t y;
    int good;
} matrix_t;

int NQsolve(matrix_t *, size_t, size_t, size_t, size_t, int);
int NQsolveAll(matrix_t *, int);
matrix_t * cloneMatrix(matrix_t *);
int copyMatrix(matrix_t *, matrix_t *);
matrix_t * createMatrix(size_t, size_t);
int deleteMatrix(matrix_t *);
int * accessMatrix(matrix_t *, size_t, size_t);
int outputMatrix(matrix_t *);
int NQcheckMatrix(matrix_t *);
matrix_t * NQwhileNotFull(size_t, size_t, size_t, int);

int main()
{
    size_t siz = (size_t) -1;
    
    printf("Please enter the size of the matrix(If the size of the matrix is"
           "too large, it can take too long to calculate or the program crashes): ");
    // The program can crash (with me from 11), because too much memory is required.
    
    fflush(stdout);
    scanf("%u", &siz);
    if(siz == (size_t) -1)
        exit(EXIT_FAILURE);
    
    // OR create matrix: matrix_t * mat = createMatrix(4, 4);
    // matrix_t * mat = NQwhileNotFull(siz, siz, siz, 1);
    matrix_t * mat = createMatrix(siz, siz);
    if(mat == NULL)
        exit(EXIT_FAILURE);
    
    if(NQsolveAll(mat, 1))
        printf("\nA solution was found.\n");
    else
        printf("\nNo solution was found.\n");
    
    // AND access to the matrix: *accessMatrix(mat, 1, 0) = 1;
    // here too: *accessMatrix(mat, 0, 1) = 1;
    // AND read from the matrix: printf("%d\n", *accessMatrix(mat, 0, 0));
    
    outputMatrix(mat);
    if(NQcheckMatrix(mat))
        printf("There is no logical error in the program.\n");
    else
        printf("There is a logical error in the program.\n");
    
    deleteMatrix(mat);
    
    return EXIT_SUCCESS;
}

int NQsolveAll(matrix_t * mat, int setRandom)
{
    size_t i, j;
    
    matrix_t * buf;
    for(i = 0; i < mat->x; i++)
    {
        buf = cloneMatrix(mat);
        if(NQsolve(buf, 0, i, mat->x, mat->y, setRandom))
        {
            copyMatrix(buf, mat);
            deleteMatrix(buf);
            
            for(i = 0; i < mat->x; i++)
                for(j = 0; j < mat->y; j++)
                    if(mat->ptr[i][j] == 2)
                        mat->ptr[i][j] = 0;
            
            return 1;
        }
        deleteMatrix(buf);
    }
    
    return 0;
}

int NQsolve(matrix_t * mat, size_t yy, size_t xx, size_t x, size_t y, int setRandom)
{
    size_t pos;
    long i, j;
    matrix_t * buf;
    
    if(setRandom)
        srand( time(NULL) );
    
    if(mat == NULL)
        return 0;
    
    pos = x + 1;
    
    buf = cloneMatrix(mat);
    for(i = xx; i < (long) x; i++)
        if(buf->ptr[i][yy] == 0)
        {
            pos = i;
            break;
        }
    
    if(pos == x + 1)
        return 0;
    
    buf->ptr[pos][yy] = 1;
    if(pos != x - 1)
        for(i = pos + 1; i < (long) x; i++)
        {
            if(buf->ptr[i][yy] == 1)
                return 0;
            buf->ptr[i][yy] = 2;
        }
    
    if(pos != 0)
        for(i = pos - 1; i >= 0; i--)
        {
            if(buf->ptr[i][yy] == 1)
                return 0;
            buf->ptr[i][yy] = 2;
        }
    
    if(yy != y)
        for(i = yy + 1; i < (long) y; i++)
        {
            if(buf->ptr[pos][i] == 1)
                return 0;
            buf->ptr[pos][i] = 2;
        }
    
    if(yy != 0)
        for(i = yy - 1; i >= 0; i--)
        {
            if(buf->ptr[pos][i] == 1)
                return 0;
            buf->ptr[pos][i] = 2;
        }
    
    for(i = pos + 1, j = yy + 1; i < (long) x && j < (long) y; i++, j++)
        if(buf->ptr[i][j] == 1) return 0; else
        buf->ptr[i][j] = 2;
    
    for(i = pos - 1, j = yy - 1; i >= 0L && j >= 0L; i--, j--)
        if(buf->ptr[i][j] == 1) return 0; else
        buf->ptr[i][j] = 2;
    
    for(i = pos + 1, j = yy - 1; i < (long) x && j >= 0L; i++, j--)
        if(buf->ptr[i][j] == 1) return 0; else
        buf->ptr[i][j] = 2;
    
    for(i = pos - 1, j = yy + 1; i >= 0L && j < (long) y; i--, j++)
        if(buf->ptr[i][j] == 1) return 0; else
        buf->ptr[i][j] = 2;
    
    if(yy == y - 1)
    {
        if(NQcheckMatrix(buf))
        {
            copyMatrix(buf, mat);
            deleteMatrix(buf);
            return 1;
        }
        else
            return 0;
    }
    else
    {
        for(i = 0; i < (long) x; i++)
            if(NQsolve(buf, yy + 1, i, x, y, 0))
            {
                copyMatrix(buf, mat);
                deleteMatrix(buf);
                return 1;
            }
        return 0;
    }
    
    return 1;
}

matrix_t * cloneMatrix(matrix_t * mat)
{
    size_t i, j;
    matrix_t * clone = createMatrix(mat->x, mat->y);
    
    if(clone == NULL)
        return NULL;
    
    for(i = 0; i < mat->x; i++)
        for(j = 0; j < mat->y; j++)
            clone->ptr[i][j] = mat->ptr[i][j];
    
    return clone;
}

int copyMatrix(matrix_t * m1, matrix_t * m2)
{
    size_t i, j;
    
    if(m1->ptr == NULL || m1->good == 0 || m2->ptr == NULL || m2->good == 0)
        return 0;
    
    for(i = 0; i < m1->x; i++)
        for(j = 0; j < m1->y; j++)
            m2->ptr[i][j] = m1->ptr[i][j];
    
    return 1;
}

matrix_t * createMatrix(size_t x, size_t y)
{
    matrix_t * mat = malloc(sizeof(matrix_t));
    size_t i;
    
    if(mat == NULL)
        return NULL;
    
    mat->x = x;
    mat->y = y;
    
    mat->ptr = malloc(sizeof(int *) * y);
    if(mat->ptr == NULL)
        return NULL;
    
    for(i = 0; i < y; i++)
    {
        mat->ptr[i] = calloc(x, sizeof(int));
        if(mat->ptr[i] == NULL)
            return NULL;
    }
    
    mat->good = 1;
	
    return mat;
}

int deleteMatrix(matrix_t * mat)
{
    size_t i;
    for(i = 0; i < mat->y; i++)
        free(mat->ptr[i]);
    
    free(mat->ptr);
    mat->good = 0;
    free(mat);
    
    return 1;
}

int * accessMatrix(matrix_t * mat, size_t x, size_t y)
{
    if(mat->ptr == NULL || mat->good == 0) return NULL;
    return mat->ptr[x] + y;
}

int outputMatrix(matrix_t * mat)
{
    size_t i, j;
    
    if(mat->ptr == NULL || mat->good == 0) return 0;
    
    for(i = 0; i < mat->x; i++)
    {
        for(j = 0; j < mat->y; j++)
            printf("%d, ", mat->ptr[j][i]);
            
        printf("\n");
    }
    
    return 1;
}

int NQcheckMatrix(matrix_t * mat)
{
    long i, j, n, m;
    
    for(i = 0; i < (long) mat->x; i++)
        for(j = 0; j < (long) mat->y; j++)
            if(mat->ptr[i][j] == 1)
            {
                for(n = i + 1; n < (long) mat->x; n++)
                    if(mat->ptr[n][j] == 1)
                        return 0;
                    
                for(n = j + 1; n < (long) mat->x; n++)
                    if(mat->ptr[i][n] == 1)
                        return 0;
                    
                for(n = i + 1, m = j + 1; n < (long) mat->x && m < (long) mat->y; n++, m++)
                    if(mat->ptr[n][m] == 1)
                        return 0;
                    
                for(n = i - 1, m = j - 1; n > 0 && m >= 0; n--, m--)
                    if(mat->ptr[n][m] == 1)
                        return 0;
                    
                for(n = i + 1, m = j - 1; n < (long) mat->x && m >= 0; n++, m--)
                    if(mat->ptr[n][m] == 1)
                        return 0;
                    
                for(n = i - 1, m = j + 1; n >= 0 && m < (long) mat->y; n--, m++)
                    if(mat->ptr[n][m] == 1)
                        return 0;
            }
    
    return 1;
}

matrix_t * NQwhileNotFull(size_t x, size_t y, size_t f, int setRandom)
{
    matrix_t * ptr;
    size_t i;
    int r1, r2;
    
    if(setRandom)
        srand( time(NULL) );
    do
    {
        ptr = createMatrix(x, y);
        for(i = 0; i < f; i++)
        {
            do
            {
                r1 = rand() % x;
                r2 = rand() % y; 
            } while(ptr->ptr[r1][r2] == 1);
            ptr->ptr[r1][r2] = 1;
        }
    } while(NQcheckMatrix(ptr) == 0 && deleteMatrix(ptr));
    return ptr;
}
