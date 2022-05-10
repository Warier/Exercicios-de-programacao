#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes.h"

void swap(int *a,int *b){ //inverte os valores das variaveis
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int* constroiVetor(int tamanho){ //gera valores aleatorios em um array
    int *vet, i;
    vet = (int*)malloc(sizeof(int) * tamanho);
    srand(time(NULL));
    for(i = 0; i < tamanho; i++){
        vet[i] = rand() % 10;
    }
    return vet;
}

void insertSort(int *vet,int tamanho){ //algoritmo de sorting O(n^2)
    int i, j, aux;
    if(tamanho <= 1){
        return vet;
    }
    for(i = 0; i < tamanho; i++){
        aux = i;
        for(j = tamanho - 1 ; j >= 0; j--){
            if(vet[aux] > vet[j]){
                swap(&vet[aux], &vet[j]);
                aux = j;
            }
            //imprimir(vet, tamanho);
        }
        //printf("\n\nTESTE %d\n", i);
        //imprimir(vet, tamanho);
    }

}

void imprimir(int *vet, int tamanho){
    int i;
    for(i = 0; i < tamanho; i++){
        printf("vet[%d]: %d\n", i + 1, vet[i]);
    }
}

