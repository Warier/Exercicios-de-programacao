#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

#define TAM 1000

int main()
{
    int *cont, *input;
    input = constroiVetor(TAM, 1000);
    cont = (int*)malloc(sizeof(int) * 10);
    printf("\n INPUT \n");
    imprimir(input, TAM);
    printf("\n\n RADIX SORT\n");
    input = radixSort(input, cont, TAM);
    printf("\n\n TESTE\n");
    imprimir(input, TAM);
    return 0;
}
