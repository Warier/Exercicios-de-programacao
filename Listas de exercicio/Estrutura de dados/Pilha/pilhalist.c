#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilhalist.h"

struct no{
    float info;
    struct no *prox;
};


struct pilhaL{
    no *prim;
};


pilhaList* criaL(pilhaList *p1){
    pilhaList *p;
    p = (pilhaList*)malloc(sizeof(pilhaList));
    p->prim = NULL;
    return p;
}


pilhaList* pushL(pilhaList* p1, float v){
    no *novo;
    novo = (no*)malloc(sizeof(no));
    novo->info = v;
    novo->prox = p1->prim;
    p1->prim = novo;
    return p1;
}

float popL(pilhaList *p1){
    float x = p1->prim->info;
    no *p = p1->prim;
    if(p == NULL){
        printf("\nPILHA VAZIA\n");
        return;
    } else {
        p1->prim = p1->prim->prox;
        free(p);
        return x;
    }
}

void imprimirL(pilhaList *p1){
    no *p = p1->prim;
    printf("\n\n[");
    while(p != NULL){
        printf(" %.2f \n", p->info);
        p = p->prox;
    }
    printf("     ]\n\n");
}

void limpa(pilhaList *p1){
    no *p = p1->prim, *aux;
    while(p != NULL){
        aux = p;
        p = p->prox;
        free(aux);
    }
    p1->prim = p;
}

int testaMaisElementosL(pilhaList *p1, pilhaList *p2){
    no *p = p1->prim, *o = p2->prim;
    while(p != NULL && o != NULL){
        p = p->prox;
        o = o->prox;
    }
    if(p != NULL && o == NULL){
        return 1;
    } else {
        return 0;
    }
}

void inverterL(pilhaList *p1){
    no *p = p1->prim, *o = NULL;
    while(p != NULL){
        no *novo;
        novo = (no*)malloc(sizeof(no));
        novo->info = p->info;
        novo->prox = o;
        o = novo;
        p = p->prox;
    }
    limpa(p1);
    p1->prim = o;
}

void transferirElementosL(pilhaList *p1, pilhaList *p2, int *flag){
    no *p = p1->prim, *o = NULL, *aux;
    limpa(p2);
    while(p != NULL){
        no *novo;
        novo = (no*)malloc(sizeof(no));
        novo->info = p->info;
        novo->prox = NULL;
        if(o == NULL){
            o = novo;
            aux = o;
        } else{
            aux->prox = novo;
            aux = novo;
        }
        p = p->prox;
    }
    p2->prim = o;
    *flag = 0;
}

int iguaisL(pilhaList *p1, pilhaList *p2){
    no *p = p1->prim, *o = p2->prim;
    while(p != NULL && o != NULL){
        if(p->info != o->info){
            return 0;
        }
        p = p->prox;
        o = o->prox;
    }
    if(p == NULL && o == NULL){
        return 1;
    } else {
        return 0;
    }
}

int verifExpressaoL(char *e){
    pilhaList *p1 = criaL(p1);
    int verif = 0, i;
    for(i = 0; i < strlen(e); i++){
        if(e[i] == '('){
            pushL(p1, -1);
        }
        if(e[i] == ')'){
            pushL(p1, 1);
        }
    }
    no *p = p1->prim;
    imprimirL(p1);
    while(p != NULL){
        verif += p->info;
        if(verif < 0){
            return 0;
        }
        p = p->prox;
    }
    limpa(p1);
    if(verif == 0){
        return 1;
    } else {
        return 0;
    }
}

int verifXCYL(char *frase){
    pilhaList *p1 = criaL(p1);
    int i, cont;
    if(frase[strlen(frase)/2] != 'C' || strlen(frase) % 2 != 1){
        return 0;
    }
    for(i = 0; frase[i] != 'C'; i++){
        if(frase[i]!= 'A'){
            if(frase[i] != 'B'){
                return 0;
            } else {
                pushL(p1, 66);
            }
        } else {
            pushL(p1, 65);
        }
    }
    i++;
    while(p1->prim != NULL){
        if(frase[i] != p1->prim->info){
            return 0;
        }
        i++;
        p1->prim = p1->prim->prox;
    }
    return 1;
}
