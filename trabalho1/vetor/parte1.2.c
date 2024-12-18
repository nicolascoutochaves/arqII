/*
Lucas Gomes de Souza - 00580466
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <sysinfoapi.h>
#include "organizacao1.2.h"

int main()
{
    // Abertura dos arquivos de entrada e sa�da
    FILE *entrd = fopen("entrada2.txt", "r");   // Arquivo de entrada com os vetores a serem ordenados
    FILE *sda = fopen("saida2.txt", "w");       // Arquivo de sa�da para registrar os resultados

    // Verifica��o de erro ao abrir o arquivo de entrada
    if (entrd == NULL)
    {
        perror("Erro ao abrir o arquivo de entrada");
        return 1; // Termina o programa em caso de erro
    }

    // Verifica��o de erro ao abrir o arquivo de sa�da
    if (sda == NULL)
    {
        perror("Erro ao abrir o arquivo de sa�da");
        fclose(entrd);  // Fecha o arquivo de entrada
        return 1;       // Termina o programa em caso de erro
    }

    // Declara��o do vetor de incrementos de Ciura
    int ciura[] = {1, 4, 10, 23, 57, 132, 301, 701};  // Sequ�ncia padr�o de Ciura
    int gap = 701;   // �ltimo valor do vetor Ciura

    // Vari�vel do passo de incremento
    int k = 0;  // Vari�vel auxiliar para itera��o nos incrementos
    int h;      // Armazena o incremento atual

    // Vari�vel que recebe o tamanho do vetor de cada linha lida
    int size;

    // Vari�veis de report temporal
    long long int begin;
    long long int end;
    double elapsed;

    // Loop para leitura dos vetores do arquivo de entrada
    while (fscanf(entrd, "%d", &size) != EOF)    // L� o tamanho do vetor de cada linha
    {

        // Aloca��o din�mica para o vetor V de tamanho "size"
        int *V = (int *)malloc(size * sizeof(int));
        if (V == NULL)    // Verifica��o de erro na aloca��o de mem�ria
        {
            perror("Erro ao alocar mem�ria");
            fclose(entrd);
            fclose(sda);
            return 1;  // Termina o programa em caso de erro
        }

        // Leitura dos elementos do vetor do arquivo de entrada
        for (int i = 0; i < size; i++)
        {
            fscanf(entrd, "%d", &V[i]);
        }

        // Ordena��o com incremento Shell
        int *V_shell = malloc(size * sizeof(int));  // Cria��o de um novo vetor para o m�todo Shell
        memcpy(V_shell, V, size * sizeof(int));     // Copia os valores de V para V_shell
        // Inicializa��o da vari�vel de incremento h para o loop de ordena��o
        h = size;
        k = 0;

        // Loop de ordena��o com o m�todo Shell, enquanto o incremento for maior que 1
        begin = GetTickCount64();
        while (h > 1)
        {
            h = incremento_shell(k, size);       // Calcula o incremento Shell
            arrumacao_Shell(V_shell, h, size, 0); // Realiza a ordena��o parcial com o incremento atual
            k++;  // Incrementa o �ndice para calcular o pr�ximo valor de h
        }
        end = GetTickCount64();
        elapsed = (end - begin)*1e-3;
        fprintf(sda,"SHELL, %d, %f, 2.9 GH Quad-Core Intel Core I5\n", size, 1000*elapsed);

        // Ordena��o com incremento Knuth
        int *V_knuth = malloc(size * sizeof(int));  // Cria��o de um novo vetor para o m�todo Knuth
        memcpy(V_knuth, V, size * sizeof(int));     // Copia os valores de V para V_knuth
        h = size;  // Re-inicializa h com o tamanho do vetor
        k = 0;

        begin = GetTickCount64();
        printf("no knuth ");
        while (h > 1)
        {
            h = incremento_knuth(k, size);        // Calcula o incremento Knuth
            arrumacao_Shell(V_knuth, h, size, 0);  // Realiza a ordena��o parcial com o incremento atual
            k++;  // Incrementa o �ndice para calcular o pr�ximo valor de h
        }
        end = GetTickCount64();
        elapsed = (end - begin)*1e-3;
        fprintf(sda,"KNUTH, %d, %f, 2.9 GH Quad-Core Intel Core I5\n", size, 1000*elapsed);

        // Ordena��o com incremento Ciura
        int *V_ciura = malloc(size * sizeof(int));  // Cria��o de um novo vetor para o m�todo Ciura
        memcpy(V_ciura, V, size * sizeof(int));     // Copia os valores de V para V_ciura

        h = size;  // Re-inicializa h com o tamanho do vetor
        k = 0;

        begin = GetTickCount64();
        // Loop de ordena��o com o m�todo Ciura, enquanto o incremento for maior que 1
        printf("no ciura ");
        while (h > 1)
        {
            h = incremento_ciura(k, ciura, size, &gap);  // Calcula o incremento Ciura
            arrumacao_Shell(V_ciura, h, size, 0);        // Realiza a ordena��o parcial com o incremento atual
            k++;  // Incrementa o �ndice para calcular o pr�ximo valor de h
        }
        end = GetTickCount64();
        elapsed = (end - begin)*1e-3;
        fprintf(sda,"CIURA, %d, %f, 2.9 GH Quad-Core Intel Core I5\n", size, 1000*elapsed);

        // Libera��o da mem�ria alocada dinamicamente para os vetores
        free(V);
        free(V_shell);
        free(V_knuth);
        free(V_ciura);
    }

    // Fechamento dos arquivos de entrada e sa�da
    fclose(entrd);
    fclose(sda);

    return 0;  // Indica que o programa foi executado com sucesso
}
