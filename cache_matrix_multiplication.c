#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void multiplicateMatrix(int *m1, int m2[ROWS][COLUMNS]){
    int i, j, k;
    int sum;
    int row[ROWS];
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLUMNS; j++){
            sum = 0;
            for(k = 0; k < COLUMNS; k++){
                
                sum += ((int (*)[COLUMNS])m1)[i][k] * m2[j][k];
            }
            row[j] = sum;
        }
        for(j = 0; j < COLUMNS; j++)
            ((int (*)[COLUMNS])m1)[i][j] = row[j];

    }
}
int main(){
    //printf("%d bytes\n",sizeof(int) * COLUMNS * ROWS);
    int *m1 = malloc(sizeof(int) * COLUMNS * ROWS);
    int *m2 = malloc(sizeof(int) * COLUMNS * ROWS);

    if(!m1 || !m2){
        puts("Error during memory allocation");
        return 1;
    }
    populateMatrix((int (*)[COLUMNS]) m1);

    FILE *f = fopen("matrixcache.bin", "rb");
    if (!f){
        puts("Error during opening file");
        return 1;
    }
    if(fread(m2, sizeof(int), COLUMNS * ROWS, f) != COLUMNS * ROWS){
        puts("Error during reading from file");
        return 1;
    }
    fclose(f);

    //printMatrix((int (*)[COLUMNS]) m1);
    //printMatrix((int (*)[COLUMNS]) m2);

    multiplicateMatrix(m1,(int (*)[COLUMNS]) m2);
    //printMatrix((int (*)[COLUMNS]) m1);


    return 0;
}