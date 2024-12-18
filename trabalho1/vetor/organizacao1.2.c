
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "organizacao1.2.h"

void arrumacao_Insert(int *V, int lgn)
{
    int i, j, aux;
    int trocas = 0;
    for (i = 1; i < lgn; i++)
    {
        aux = V[i];
        j = i - 1;
        while (j >= 0 && aux < V[j])
        {
            V[j + 1] = V[j];
            j = j - 1;
            trocas++;
        }
        V[j + 1] = aux;
    }
    return;
}

int incremento_shell(int k, int s)
{
    float aux = pow(2, k);
    aux = s / aux;
    aux = floor(aux);
    if (aux == 0)
    {
        return 1;
    }
    return (int)aux;
}

int incremento_knuth(int k, int s) {
    float aux = 3 * k + 1;
    aux = s / aux;
    aux = ceil(aux); // Arredonda para cima para garantir um valor positivo

    // Garante que o retorno seja pelo menos 1
    return (int)aux > 0 ? (int)aux : 1;
}

int incremento_ciura(int k, int *ciura, int s, int *gap)
{
    int h;
    if (k > 7)
    {
        *gap = (int)ceil(*gap * 2.25);  // Incremento progressivo do gap
        h = (int)ceil((double)s / *gap); // Cálculo do incremento h
    }
    else
    {
        h = (int)ceil((double)s / ciura[k]); // Uso do valor da sequência Ciura
    }

    // Garantir que h nunca seja menor que 1
    if (h < 1)
    {
        h = 1;
    }

    return h;
}


void arrumacao_Shell(int *V, int h, int s, int c)
{
    int i, j, aux;
    int trocas = 0;
    for (i = c + h; i < s; i += h)
    {
        aux = V[i];
        for (j = i; j >= h && V[j - h] > aux; j -= h)
        {
            V[j] = V[j - h];
            trocas++;
        }
        V[j] = aux;
    }
}


void report_ordenado(int *V, int trocas, int lng)
{
    printf("********* Array ordenado ************\n");
    print_vetor(V, lng);
    printf("O número de trocas para esse método foi de: %d\n", trocas);
}

void print_vetor(int *V, int lng)
{
    for (int i = 0; i < lng; i++)
    {
        printf("%d ", V[i]);
    }
    printf("\n");
}
