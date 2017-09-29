#ifdef PRINT_OUTPUT
#include <stdio.h>
#endif

#define MATRIX_SIZE 10

typedef int array_row_of_int[MATRIX_SIZE];
char dspm[4096];

int main() {
    array_row_of_int *dspm_int = (array_row_of_int *)dspm;
    array_row_of_int *A = dspm_int;
    array_row_of_int *B = &dspm_int[MATRIX_SIZE];
    array_row_of_int *C = &dspm_int[2*MATRIX_SIZE];

    int i, j, k;
    for(i=0; i<MATRIX_SIZE; i++) {
        for(j=0; j<MATRIX_SIZE; j++) {
            A[i][j] = i+j;
            B[i][j] = i*j;
            C[i][j] = 0;
        }
    }

    for(i=0; i<MATRIX_SIZE; i++) {
        for(j=0; j<MATRIX_SIZE; j++) {
            for(k=0; k<MATRIX_SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

#ifdef PRINT_OUTPUT

    for(i=0; i<MATRIX_SIZE; i++) {
        for(j=0; j<MATRIX_SIZE; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

#endif

    return 0;
}
