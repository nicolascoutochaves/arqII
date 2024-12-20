#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "organizacao.h"



int shellSort(int *V, int n)
{
    int i, j, aux;
    for (int gap = n/2; gap > 0; gap /= 2)
    {
       
        for (i = gap; i < n; i += 1)
        {
            aux = V[i];      
            for (j = i; j >= gap && V[j - gap] > aux; j -= gap)
                V[j] = V[j - gap];
  
            V[j] = aux;
        }
    }
    return 0;
}


void print_vetor(int *V, int lng)
{
    for (int i = 0; i < lng; i++)
    {
        printf("%d ", V[i]);
    }
    printf("\n");
}
