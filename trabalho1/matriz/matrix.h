#include <limits.h>
#define FILL_L1_CACHE 443 //L1 == 768KB (sqrt(768*1024/4) = 443)
#define FILL_L2_CACHE 886 //L2 == 3MB (sqrt(3*1024*1024/4) = 886)
#define FILL_L3_CACHE 2804 //L3 == 30MB (sqrt(30*1024*1024/4) = 2804)
#define OVERFLOW_L3_CACHE 3000

#define ROWS FILL_L3_CACHE
#define COLUMNS FILL_L3_CACHE
#define MAX_RAND (INT_MAX >> 24)

void populateVec(int v[], int length);
void populateMatrix(int m[ROWS][COLUMNS]);
void printMatrix(int m[ROWS][COLUMNS]);
void printVec(int v[], int length);
void composeVector(int m[ROWS][COLUMNS], int v1[], int length);
void invertMatrix(int m[ROWS][COLUMNS]);