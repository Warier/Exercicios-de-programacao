#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include "Lista.h"

int main() {
	Lista2 *L2 = NULL, *L1 = NULL;
	printf("LISTA DUPLAMENTE ENCADEADA\n\n");
	L2 = insereFim(L2, 1);
	L2 = insereFim(L2, 2);
	L2 = insereFim(L2, 3);
	L2 = insereFim(L2, 5);
	L2 = insereFim(L2, 5);
	L2 = insereFim(L2, 6);
	L2 = insereFim(L2, 7);
    L2 = insereFim(L2, 8);
    L2 = insereFim(L2, 9);
    L2 = insereFim(L2, 10);
    L2 = insereFim(L2, 11);
    L2 = insereFim(L2, 12);
    L2 = insereFim(L2, 13);
    L2 = insereFim(L2, 14);

	L1 = insereFim(L1, 1);
	L1 = insereFim(L1, 2);
	L1 = insereFim(L1, 3);
	L1 = insereFim(L1, 4);
	L1 = insereFim(L1, 5);
	L1 = insereFim(L1, 6);
	L1 = insereFim(L1, 7);
	imprimir(L2);
    printf("\n num: %d", conteListaRecursiva(L2));

    printf("\n num: %d", conteListaIterativa(L2));
    printf("\n%d\n\n", crescente(L2));
    imprimir(L1);

    printf("\n%d\n\n", compara(L1, L2));

    L2 = troca(L2, 14, 10);
    imprimir(L2);


	return 0;
}



