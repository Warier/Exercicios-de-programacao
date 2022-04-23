#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include "Lista.h"


int main(){
    Lista *L3 = NULL, *L4 = NULL;
    printf("\n\nLISTA SIMPLES\n\n");

    L3 = insereFim(L3, 1);
	L3 = insereFim(L3, 2);
	L3 = insereFim(L3, 3);
	L3 = insereFim(L3, 4);
	L3 = insereFim(L3, 5);
	L3 = insereFim(L3, 6);
	L3 = insereFim(L3, 7);
    L3 = insereFim(L3, 8);
    L3 = insereFim(L3, 9);
    L3 = insereFim(L3, 10);
    L3 = insereFim(L3, 11);
    L3 = insereFim(L3, 12);
    L3 = insereFim(L3, 13);
    L3 = insereFim(L3, 14);

	L4 = insereFim(L4, 1);
	L4 = insereFim(L4, 2);
	L4 = insereFim(L4, 3);
	L4 = insereFim(L4, 4);
	L4 = insereFim(L4, 5);
	L4 = insereFim(L4, 6);
	L4 = insereFim(L4, 7);
	imprimir(L3);
    printf("\n num: %d", conteListaRecursiva(L3));

    printf("\n num: %d", conteListaIterativa(L3));
    printf("\ncrescente:%d\n\n", crescente(L3));
    imprimir(L4);

    printf("\ncompara: %d\n\n", compara(L3, L4));

    L3 = troca(L3, 1,14);
    imprimir(L3);
	return 0;
}
