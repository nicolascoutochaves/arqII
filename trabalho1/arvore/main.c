#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "abp.h"
#define MAX 1000000
int main(){
    pNodoA* a = NULL;
    for(int i = 0; i < N_DATA; i++){
        srand(time(NULL));
        a = InsereArvore(a,rand()%MAX);
    }
    search(a, 10);
    /* int c = search(a, 10);
    if (c != -1)
        printf ("Elemento encontrado: %d\n", c);
    else 
        printf ("Elemento não encontrado\n"); */
    return 0;
}
