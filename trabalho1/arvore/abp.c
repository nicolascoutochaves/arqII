#include <stdio.h>
#include <stdlib.h>
#include "abp.h"

pNodoA* InsereArvore(pNodoA *a, int ch){
    if (a == NULL){
        a = (pNodoA*) malloc(sizeof(pNodoA));
        a->info = ch;
        a->esq = NULL;
        a->dir = NULL;
    }
    else if (ch < a->info)
        a->esq = InsereArvore(a->esq,ch);
    else
        a->dir = InsereArvore(a->dir,ch);
    return a;
}

int PreFixado(pNodoA *a){
    if (a!= NULL){

        printf("%d\n",a->info);

        PreFixado(a->esq);
        PreFixado(a->dir);
    }
}

int Count(pNodoA *a, int *c){
    if (a!= NULL){
        Count(a->esq, c);
        Count(a->dir, c);
        return ++(*c);
    }
}

void ShowLevels(pNodoA *a, int n){
    if (a!= NULL){
        for(int i = n; i >=  0; i--){
            printf("=");
        }
        printf("%d\n", a->info);

        ShowLevels(a->esq, n+1);
        ShowLevels(a->dir, n+1);
    }
}
