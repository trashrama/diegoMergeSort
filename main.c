#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int chamadas = 1;

void printarLista(int lista[], int tam_lista)
{
    printf("\nLISTA!\n");

    for (int i = 0; i < tam_lista; i++)
    {
        if (i == 0)
        {
            printf("{");
            printf("%i", lista[i]);
        }
        else
        {
            printf(", %i", lista[i]);
        }
        if (i == tam_lista - 1)
            printf("}");
    }
    printf("\nFIM DA LISTA\n\n");
}
void comb(int lista[], int inicio, int meio, int fim)
{
    int tam_esq = meio - inicio + 1;
    int tam_dir = fim - meio;
    int *lista_esq = (int *)malloc(sizeof(int) * tam_esq);
    int *lista_dir = (int *)malloc(sizeof(int) * tam_dir);
    int topo_esq = 0, topo_dir = 0;

    for (int i = 0; i < tam_esq; i++)
    {
        lista_esq[i] = lista[inicio + i];
    }

    for (int i = 0; i < tam_dir; i++)
    {
        lista_dir[i] = lista[meio + i + 1];
    }

    for (int i = inicio; i <= fim; i++)
    {
        if (topo_esq >= tam_esq)
        {
            lista[i] = lista_dir[topo_dir];
            topo_dir += 1;
        }
        else if (topo_dir >= tam_dir)
        {
            lista[i] = lista_esq[topo_esq];
            topo_esq += 1;
        }
        else if (lista_esq[topo_esq] < lista_dir[topo_dir])
        {
            lista[i] = lista_esq[topo_esq];
            topo_esq += 1;
        }
        else
        {
            lista[i] = lista_dir[topo_dir];
            topo_dir += 1;
        }
        printf("CHAMADA DO COMB: %i", chamadas);
        printarLista(lista, fim + 1);
    }

    chamadas += 1;

    free(lista_esq);
    free(lista_dir);
}

void merge(int lista[], int inicio, int fim, int tam_lista)
{
    // printarLista(lista, tam_lista);
    if ((fim - inicio) > 0)
    {
        int meio = (int)(fim + inicio) / 2;
        merge(lista, inicio, meio, tam_lista);
        merge(lista, meio + 1, fim, tam_lista);
        comb(lista, inicio, meio, fim);
    }
}

int main(int argc, char *argv[])
{
    int listaPequena[] = {6, 3, 13, 9, 7, 1};

    int ini = 0;
    int tam = ((sizeof(listaPequena) / sizeof(int)));

    int fim = tam - 1;
    clock_t inicio_tempo, fim_tempo;
    inicio_tempo = clock();

    merge(listaPequena, ini, fim, tam);
    fim = clock();
    // printf("Tempo: %fs\n", ((double)(fim_tempo - inicio_tempo) / CLOCKS_PER_SEC));
    // printarLista(listaPequena, (sizeof(listaPequena) / sizeof(int)));

    return 0;
}