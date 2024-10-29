#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"


int main(){
    int *m1 = malloc(sizeof(int) * COLUMNS * ROWS);
    FILE *f = fopen("matrixnormal.bin", "wb");
    if(!m1){
        puts("Error during memory allocation");
        return 1;
    }
    
    populateMatrix((int (*)[COLUMNS]) m1);
    size_t a = fwrite(m1, sizeof(int), COLUMNS * ROWS, f);
    printf("%llu bytes\n", a);
    if (a != COLUMNS * ROWS){
        puts("Error during writing to file");
        return 1;
    }
    fclose(f);

    return 0;
}