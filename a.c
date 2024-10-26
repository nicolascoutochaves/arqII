#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N (10000)
int main(){
    int *vet = malloc(40000000000);
    printf("%d bytes\n", sizeof(int) * N * N);
    srand(time(NULL));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++) {
           ((int (*)[N])vet) [i][j] = rand() % 100;
        }
    }
    return 0;
}