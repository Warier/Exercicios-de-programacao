#include <stdio.h>
#include <stdlib.h>
#include "pilhalist.h"
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
    printf("\nPrimeiro pop: %.2f", pop(p2));
    printf("\nSegundo pop: %.2f", pop(p2));

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


    printf("\nPIlHA COM LISTA ENCADEADA\n\n");

    pilhaList* *pl1, *pl2;
    pl1 = criaL(pl1);
    pl2 = criaL(pl2);

    printf("\nPL1\n");
    pl1 = pushL(pl1, 1);
    pl1 = pushL(pl1, 2);
    pl1 = pushL(pl1, 3);
    pl1 = pushL(pl1, 4);
    pl1 = pushL(pl1, 5);
    pl1 = pushL(pl1, 6);
    pl1 = pushL(pl1, 7);

    imprimirL(pl1);
    printf("\nPrimeiro pop: %.2f", popL(pl1));
    printf("\nSegundo pop: %.2f", popL(pl1));

    printf("\nPL1\n");
    imprimirL(pl1);

    printf("\nPL2\n");
    pl2 = pushL(pl2, 1);
    pl2 = pushL(pl2, 2);
    pl2 = pushL(pl2, 3);
    imprimirL(pl2);

    printf("\nPL1 e maior que PL2: %s \n", testaMaisElementosL(pl1, pl2) ? "verdade" : "falso");
    transferirElementosL(pl1, pl2, flagErro);

    printf("\nCopia de PL1 para PL2: %s \n", *flagErro ? "Nao Realizada" : "Realizada");
    printf("\nPL1\n");
    imprimirL(pl1);
    printf("\nPL2\n");
    imprimirL(pl2);

    printf("\n O inverso de PL1: \n");
    inverterL(pl1);
    imprimirL(pl1);

    printf("\nPL1 e igual PL2: %s \n", iguaisL(pl1, pl2) ? "verdade" : "falso");

    printf("\nA expressao %s esta: %s\n", expressao, verifExpressaoL(expressao)? "Correta" : "Incorreta");

    printf("\nA frase %s esta: %s\n", frase, verifXCY(frase)? "Correta" : "Incorreta");

    return 0;
}

