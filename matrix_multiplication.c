#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
typedef struct{
    int *res;
}Result;

Result multiplicateMatrix(int m1[ROWS][COLUMNS], int m2[ROWS][COLUMNS], Result result){
    int i, j, k, l;
    int tmp;
   
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLUMNS; j++){
            tmp = 0;
            for(k = 0; k < COLUMNS; k++){
                
                tmp += m1[i][k] * m2[k][j];
            }
           ((int (*)[COLUMNS])result.res)[i][j] = tmp;
        }

    }
    return result;
}
int main(){
    printf("%d Kbytes\n",sizeof(int) * COLUMNS * ROWS/1024);
    int *m1 = malloc(sizeof(int) * COLUMNS * ROWS);
    int *m2 = malloc(sizeof(int) * COLUMNS * ROWS);
    Result result;
    result.res = malloc(sizeof(int) * COLUMNS * ROWS);
    if(!m1 || !m2 || !result.res){
        puts("Error during memory allocation");
        return 1;
    }
    populateMatrix((int (*)[COLUMNS]) m1);
    populateMatrix((int (*)[COLUMNS]) m2);
    //printMatrix((int (*)[COLUMNS]) m1);
    //printMatrix((int (*)[COLUMNS]) m2);
    invertMatrix((int (*)[COLUMNS]) m2);
    //printMatrix((int (*)[COLUMNS]) m2);
    result = multiplicateMatrix((int (*)[COLUMNS]) m1,(int (*)[COLUMNS]) m2, result);
    //printMatrix((int (*)[COLUMNS]) result.res);


    return 0;
}