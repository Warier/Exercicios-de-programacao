#include <stdio.h>
#include <stdlib.h>
#include "pilhavet.h"



int main()
{
    int *flagErro;
    char *expressao = "1 + 3(6 + 3(2*4))", *frase = "ABABBCBBABA";
    flagErro = malloc(sizeof(int));
    printf("\nPIlHA COM VETOR\n\n");
    pilhaVet *p1, *p2;
    p1 = cria();
    printf("\tP1\n\n");
    push(p1, 1);
    push(p1, 2);
    push(p1, 3);
    push(p1, 4);
    push(p1, 5);
    push(p1, 6);
    push(p1, 7);
    imprimir(p1);

    printf("\tP2\n\n");
    p2 = cria();
    push(p2, 1);
    push(p2, 2);
    push(p2, 3);
    imprimir(p2);

    printf("\np1 e maior que p2: %s \n", testaMaisElementos(p1, p2) ? "verdade" : "falso");
    transferirElementos(p1, p2, flagErro);
    printf("\nCopia de p1 para p2: %s \n", *flagErro ? "Nao Realizada" : "Realizada");
    printf("\nP1\n");
    imprimir(p1);
    printf("\nP2\n");
    imprimir(p2);

    printf("\n O inverso de P2: \n");
    inverter(p2);
    imprimir(p2);
    printf("\np1 e igual p2: %s \n", iguais(p1, p2) ? "verdade" : "falso");

    printf("\nA expressao %s esta: %s\n", expressao, verifExpressao(expressao)? "Correta" : "Incorreta");

    printf("\nA frase %s esta: %s\n", frase, verifXCY(frase)? "Correta" : "Incorreta");

    return 0;
}

