#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include "abp.h"
#define MAX INT_MAX
int main(){
    pNodoA* a = NULL;
    for(int i = 0; i < N_DATA; i++){
        srand(time(NULL));
        a = InsereArvore(a,rand()%MAX);
    }
    srand(time(NULL));
    search(a, rand()%MAX);
    /* int c = search(a, 10);
    if (c != -1)
        printf ("Elemento encontrado: %d\n", c);
    else 
        printf ("Elemento não encontrado\n"); */
    return 0;
}
