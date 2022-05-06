#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilhavet.h"

#define max 50

struct pilha{
    float v[max];
    int n;
};


pilhaVet* cria(){
    pilhaVet *p1;
    p1 = (pilhaVet*)malloc(sizeof(pilhaVet));
    p1->n = 0;
    return p1;
}

void push(pilhaVet *p1, float v){
    if(p1->n == max){
        printf("PILHA CHEIA");
        return;
    } else{
        p1->n++;
        p1->v[p1->n-1] = v;
    }
}

float pop(pilhaVet *p1){
    if(p1->n == 0){
        printf("PILHA VAZIA");
        return;
    } else{
        p1->n--;
        return p1->v[p1->n];
    }
}

void imprimir(pilhaVet *p1){
    printf("\n\n[");
    int i;
    for(i = p1->n - 1; i >= 0; i--){
        printf(" %.2f \n", p1->v[i]);
    }
    printf("     ]\n\n");
}

int testaMaisElementos(pilhaVet *p1, pilhaVet *p2){
    if(p1->n > p2->n){
        return 1;
    } else {
        return 0;
    }
}

void transferirElementos(pilhaVet *p1, pilhaVet *p2, int *flag){
    int i;
    for(i = p1->n - 1; i >= 0; i--){
        p2->v[i] = p1->v[i];
    }
    p2->n = p1->n;
    *flag = 0;
}

void inverter(pilhaVet *p1){
    int i;
    for(i = 0; i <= (p1->n - 1)/2; i++){
        if(i!= (p1->n - 1)/2 || 1 != p1->n%2){
            p1->v[i] += p1->v[p1->n - 1 - i];
            p1->v[p1->n - 1 - i] = p1->v[i] - p1->v[p1->n - 1 - i];
            p1->v[i] = p1->v[i] - p1->v[p1->n - 1 - i];
        }
    }
}

int iguais(pilhaVet *p1, pilhaVet *p2){
    if(p1->n != p2->n){
        return 0;
    }
    int i;
    for(i = p1->n - 1; i >= 0; i--){
        if(p1->v[i] != p2->v[i]){
            return 0;
        }
    }
    return 1;
}

int verifExpressao(char *e){
    pilhaVet *p1 = cria();
    int i, verif = 0;
    for(i = 0; i < strlen(e); i++){
        if(e[i] == '('){
            push(p1, 1);
        }
        if(e[i] == ')'){
            push(p1, -1);
        }
    }
    for(i = 0; i < p1->n; i++){
        verif += p1->v[i];
        if(verif < 0){
            return 0;
        }
    }
    if(verif == 0){
        return 1;
    } else {
        return 0;
    }
}

int verifXCY(char *frase){
    int i;
    pilhaVet *p1 = cria();
    if(frase[strlen(frase)/2] != 'C' || strlen(frase) % 2 != 1){
        return 0;
    }
    for(i = 0; i < (strlen(frase)/2); i++){
        if(frase[i]!= 'A'){
            if(frase[i] != 'B'){
                return 0;
            } else {
                push(p1, 66);
            }
        } else {
            push(p1, 65);
        }
    }

    for(i = (strlen(frase)/2) + 1; i < strlen(frase) - 1; i++){
        if(frase[i] != pop(p1)){
            return 0;
        }
    }
    return 1;
}
