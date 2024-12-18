#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

int m1[ROWS][COLUMNS];
int m2[ROWS][COLUMNS];
int temp[ROWS][COLUMNS];

int main(){
    int i, j, k;
    int sum;
    int row[ROWS];

    srand(time(NULL));
    //srand(1);
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLUMNS; j++){
            m1[i][j] = rand() % MAX_RAND;
        }
    }

    srand(time(NULL));
    //srand(1);
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLUMNS; j++){
            m2[i][j] = rand() % MAX_RAND;
        }
    }

    //inverte m2 para otimizar o uso da cache
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            temp[i][j] = m2[i][j];
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            m2[i][j] = temp[j][i];
        }
    }

    //printMatrix(m1);
    //printMatrix(m2);

    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLUMNS; j++){
            sum = 0;
            for(k = 0; k < COLUMNS; k++){
                
                sum += m1[i][k] * m2[j][k];
            }
            row[j] = sum;
        }
        for(j = 0; j < COLUMNS; j++)
            m1[i][j] = row[j];

    }
    //printMatrix(m1);


    return 0;
}