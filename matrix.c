#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void populateVec(int v[], int length){
    int i;
    srand(time(NULL)+(time_t)v); //using the addres of each vec to avoid same values
    for(i = 0; i < length; i++){
        
        v[i] = rand() % MAX_RAND;
        
    }
}
void populateMatrix(int m[ROWS][COLUMNS]){
    int i, j;
    //srand(time(NULL));
    srand(1);
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLUMNS; j++){
            m[i][j] = rand() % MAX_RAND;
        }
    }
}


void printMatrix(int m[ROWS][COLUMNS]){
    int i, j;
    printf("        ");
    for(j = 0; j < COLUMNS; j++){
        printf("%02d  ", j+1);
    }
    printf("\n\n");
    for(i = 0; i < ROWS; i++){
        printf("%02d   ", i+1);
        
        for(j = 0; j < COLUMNS; j++){
            printf("%4d", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printVec(int v[], int length){
    int i;
    for(i = 0; i < length; i++){
        printf("%5d", v[i]);
    }
    printf("\n");
}

void composeVector(int m[ROWS][COLUMNS], int v1[], int length){
    int i, j, c;
    for(i = 0; i < length; i++){
        c = 0;
        for(j = 0; j < COLUMNS; j++){
            c += m[i][j];
        }
        v1[i] = c;
    }
}

void invertMatrix(int m[ROWS][COLUMNS]) {
    int *temp = malloc(sizeof(int) * COLUMNS * ROWS);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            ((int (*)[COLUMNS])temp)[i][j] = m[i][j];
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            m[i][j] = ((int (*)[COLUMNS])temp)[j][i];
        }
    }
}