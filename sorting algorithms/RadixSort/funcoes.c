#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes.h"

void swap(int *a,int *b){ //inverte os valores das variaveis
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}


int* constroiVetor(int tamanho, int intervalo){ //gera valores aleatorios em um array
    int *vet, i;
    vet = (int*)malloc(sizeof(int) * tamanho);
    srand(time(NULL));
    for(i = 0; i < tamanho; i++){
        vet[i] = rand() % intervalo;
    }
    return vet;
}

void imprimir(int *vet, int tamanho){
    int i;
    for(i = 0; i < tamanho; i++){
        printf("vet[%d]: %d\n", i, vet[i]);
    }
}

int pot(int base, int potencia){
    int i, x = base;
    if(potencia == 0){
        return 1;
    }
    for(i = 1; i < potencia; i++){
        x = x * base;
    }
    return x;
}

int lerDigito(int num, int digito){
    return ((num % pot(10, digito)) - (num % pot(10, digito - 1))) / pot(10, digito - 1);
}

void prefixSum(int *cont, int tamanho){
    int i;
    for(i = 1; i < tamanho; i++){
        cont[i] += cont[i-1];
    }
}

void restartArray(int *cont, int tamanho){
    int i;
    for(i = 0; i < tamanho; i++){
        cont[i] = 0;
    }
}

void counting(int *cont, int *input, int tamanho, int digito){
    int i;
    restartArray(cont, 10);
    for(i = 0; i < tamanho; i++){
        cont[lerDigito(input[i], digito)]++;
    }
}

int* radixSort(int *input, int *cont, int tamanho){
    int *output, i = 1, j, aux, *troca;
    output = (int*)malloc(sizeof(int)* tamanho);
    restartArray(cont, 10);
    for(i = 1; cont[0] < tamanho; i++){
        counting(cont, input, tamanho, i);
        prefixSum(cont, 10);
        if(cont[0] == tamanho){
            return input;
        }
        for(j = tamanho - 1; j >= 0; j--){
            aux = lerDigito(input[j], i);
            cont[aux]--;
            output[cont[aux]] = input[j];
        }
        troca = input;
        input = output;
        output = troca;
    }
    return input;
}

