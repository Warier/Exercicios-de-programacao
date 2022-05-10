#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

#define tamanho 5

int main() {
    int *vet = constroiVetor(tamanho) , i;
    printf("VETOR ORIGINAL\n");
    imprimir(vet, tamanho);

    printf("VETOR ORDENADO\n");
    insertSort(vet, tamanho);
    imprimir(vet, tamanho);
    return 0;
}
