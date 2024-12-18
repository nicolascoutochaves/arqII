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

int search(pNodoA* a, int data) {
    if (a == NULL) {
        return -1;
    }
    if (a->info == data){
        return data;

    }
    if (data < a->info)
        return search(a->esq,data);
    else
        return search(a->dir,data);
}
