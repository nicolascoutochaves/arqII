/*
Lucas Gomes de Souza - 00580466
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <sysinfoapi.h>
#include "organizacao.h"

int main()
{
    // Abertura dos arquivos de entrada e saída
    FILE *entrd = fopen("entrada1.txt", "r");   // Arquivo de entrada com os vetores a serem ordenados
    FILE *sda = fopen("saida1.txt", "w");       // Arquivo de saída para registrar os resultados

    // Verificação de erro ao abrir o arquivo de entrada
    if (entrd == NULL)
    {
        perror("Erro ao abrir o arquivo de entrada");
        return 1; // Termina o programa em caso de erro
    }

    // Verificação de erro ao abrir o arquivo de saída
    if (sda == NULL)
    {
        perror("Erro ao abrir o arquivo de saída");
        fclose(entrd);  // Fecha o arquivo de entrada
        return 1;       // Termina o programa em caso de erro
    }

    // Declaração do vetor de incrementos de Ciura
    int ciura[] = {1, 4, 10, 23, 57, 132, 301, 701};  // Sequência padrão de Ciura
    int gap = 701;   // Último valor do vetor Ciura

    // Variável do passo de incremento
    int k = 0;  // Variável auxiliar para iteração nos incrementos
    int h;      // Armazena o incremento atual

    // Variável que recebe o tamanho do vetor de cada linha lida
    int size;

    // Loop para leitura dos vetores do arquivo de entrada
    while (fscanf(entrd, "%d", &size) != EOF)    // Lê o tamanho do vetor de cada linha
    {

        // Alocação dinâmica para o vetor V de tamanho "size"
        int *V = (int *)malloc(size * sizeof(int));
        if (V == NULL)    // Verificação de erro na alocação de memória
        {
            perror("Erro ao alocar memória");
            fclose(entrd);
            fclose(sda);
            return 1;  // Termina o programa em caso de erro
        }

        // Leitura dos elementos do vetor do arquivo de entrada
        for (int i = 0; i < size; i++)
        {
            fscanf(entrd, "%d", &V[i]);
        }

        // Ordenação com incremento Shell
        int *V_shell = malloc(size * sizeof(int));  // Criação de um novo vetor para o método Shell
        memcpy(V_shell, V, size * sizeof(int));     // Copia os valores de V para V_shell

        // Reporta o vetor original no arquivo de saída e indica que será usado o método Shell
        for (int i = 0; i < size; i++)
        {
            fprintf(sda, "%d ", V_shell[i]);
        }
        fprintf(sda, "SEQ == SHELL\n");

        // Inicialização da variável de incremento h para o loop de ordenação
        h = size;
        k = 0;

        // Loop de ordenação com o método Shell, enquanto o incremento for maior que 1
        while (h > 1)
        {
            h = incremento_shell(k, size);       // Calcula o incremento Shell
            arrumacao_Shell(V_shell, h, size, 0); // Realiza a ordenação parcial com o incremento atual

            // Reporta o vetor parcialmente ordenado e o incremento utilizado
            for (int i = 0; i < size; i++)
            {
                fprintf(sda, "%d ", V_shell[i]);
            }
            fprintf(sda, "INCR == %d\n", h);
            k++;  // Incrementa o índice para calcular o próximo valor de h
        }

        // Ordenação com incremento Knuth
        int *V_knuth = malloc(size * sizeof(int));  // Criação de um novo vetor para o método Knuth
        memcpy(V_knuth, V, size * sizeof(int));     // Copia os valores de V para V_knuth

        // Reporta o vetor original no arquivo de saída e indica que será usado o método Knuth
        for (int i = 0; i < size; i++)
        {
            fprintf(sda, "%d ", V_knuth[i]);
        }
        fprintf(sda, "SEQ == KNUTH\n");

        h = size;  // Re-inicializa h com o tamanho do vetor
        k = 0;

        // Loop de ordenação com o método Knuth, enquanto o incremento for maior que 1
        while (h > 1)
        {
            h = incremento_knuth(k, size);        // Calcula o incremento Knuth
            arrumacao_Shell(V_knuth, h, size, 0);  // Realiza a ordenação parcial com o incremento atual

            // Reporta o vetor parcialmente ordenado e o incremento utilizado
            for (int i = 0; i < size; i++)
            {
                fprintf(sda, "%d ", V_knuth[i]);
            }
            fprintf(sda, "INCR == %d\n", h);
            k++;  // Incrementa o índice para calcular o próximo valor de h
        }

        // Ordenação com incremento Ciura
        int *V_ciura = malloc(size * sizeof(int));  // Criação de um novo vetor para o método Ciura
        memcpy(V_ciura, V, size * sizeof(int));     // Copia os valores de V para V_ciura

        // Reporta o vetor original no arquivo de saída e indica que será usado o método Ciura
        for (int i = 0; i < size; i++)
        {
            fprintf(sda, "%d ", V_ciura[i]);
        }
        fprintf(sda, "SEQ == CIURA\n");

        h = size;  // Re-inicializa h com o tamanho do vetor
        k = 0;

        // Loop de ordenação com o método Ciura, enquanto o incremento for maior que 1
        while (h > 1)
        {
            h = incremento_ciura(k, ciura, size, &gap);  // Calcula o incremento Ciura
            arrumacao_Shell(V_ciura, h, size, 0);        // Realiza a ordenação parcial com o incremento atual

            // Reporta o vetor parcialmente ordenado e o incremento utilizado
            for (int i = 0; i < size; i++)
            {
                fprintf(sda, "%d ", V_ciura[i]);
            }
            fprintf(sda, "INCR == %d\n", h);
            k++;  // Incrementa o índice para calcular o próximo valor de h
        }

        // Liberação da memória alocada dinamicamente para os vetores
        free(V);
        free(V_shell);
        free(V_knuth);
        free(V_ciura);
    }

    // Fechamento dos arquivos de entrada e saída
    fclose(entrd);
    fclose(sda);

    return 0;  // Indica que o programa foi executado com sucesso
}
