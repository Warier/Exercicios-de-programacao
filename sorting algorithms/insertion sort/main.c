#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

#define TAMANHO 5000

int main() {
    int *vet = constroiVetor(TAMANHO, 100) , i;
    printf("VETOR ORIGINAL\n");
    imprimir(vet, TAMANHO);

    printf("VETOR ORDENADO\n");
    insertSort(vet, TAMANHO);
    imprimir(vet, TAMANHO);
    return 0;
}
