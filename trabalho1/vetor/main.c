/*
Lucas Gomes de Souza - 00580466
*/

//Ordenação de vetores utilizando o método de Shell Sort

#include <stdio.h>
#include "organizacao.h"

#define N N_DATA
int vet[N];
int main()
{
    //print_vetor(vet, N);
    shellSort(vet, N);
    //print_vetor(vet, N);

    return 0; 
}
