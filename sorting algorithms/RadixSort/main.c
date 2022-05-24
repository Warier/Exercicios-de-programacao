#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

#define TAM 20000

int main()
{
    int *cont, *input;
    input = constroiVetor(TAM, 100000);
    cont = (int*)malloc(sizeof(int) * 10);
    printf("\n INPUT \n");
    imprimir(input, TAM);
    printf("\n\n RADIX SORT\n");
    input = radixSort(input, cont, TAM);
    imprimir(input, TAM);
    return 0;
}
