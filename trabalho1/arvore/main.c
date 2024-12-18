#include <stdio.h>
#include <stdlib.h>
#include "abp.h"

int main(){
    pNodoA* a = NULL;
    a = InsereArvore(a, 8);
    a = InsereArvore(a, 4);
    a = InsereArvore(a, 2);
    a = InsereArvore(a, 6);
    a = InsereArvore(a, 1);
    a = InsereArvore(a, 3);
    a = InsereArvore(a, 7);
    a = InsereArvore(a, 9);
    a = InsereArvore(a, 11);
    a = InsereArvore(a, 10);
    int num = 0;
    PreFixado(a);
    printf("\nEsta arvore tem %d elementos\n", Count(a, &num));
    num = 0;
    ShowLevels(a,0);
}
