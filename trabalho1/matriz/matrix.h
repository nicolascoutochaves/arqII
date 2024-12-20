#include <limits.h>
#define N_DATA (6*1024)/2 //36MB to overflow cache L3 (divided by 2 cause the sizeof int is 4 bytes and ROWS/2 * COLUNS/2 = ROWS*COLUNS/4)
#define ROWS N_DATA
#define COLUMNS N_DATA
#define MAX_RAND 20 //small number because the focus is to measure the time of memory access and cache hit/miss, not the quality of the algorithm
void populateVec(int v[], int length);
void populateMatrix(int m[ROWS][COLUMNS]);
void printMatrix(int m[ROWS][COLUMNS]);
void printVec(int v[], int length);
void composeVector(int m[ROWS][COLUMNS], int v1[], int length);
void invertMatrix(int m[ROWS][COLUMNS]);