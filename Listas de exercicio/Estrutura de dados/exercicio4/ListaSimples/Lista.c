
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include "Lista.h"

struct lista{
	int info;
	struct lista *prox;
};


Lista* insereFim(Lista *L, int v){
	Lista *novo, *aux=L;
	novo = (Lista*) malloc(sizeof(Lista));
	novo->info = v;
	novo->prox = NULL;
	if(L!=NULL){
		while(aux->prox!=NULL)
			aux = aux->prox;
		aux->prox = novo;
		return L;
	}
	else{
		return novo;
	}
}

void imprimir(Lista *L){
	Lista *aux=L;

	while(aux!=NULL){
		printf("[%d] -> ",aux->info);
		aux = aux->prox;
	}
}

int conteListaRecursiva (Lista* l){
    int b = 0;
    Lista *p = l;
    if(p == NULL){
        return b;
    } else{
        return 1 + conteListaRecursiva(p->prox);
    }
}

int conteListaIterativa(Lista* l) {
    Lista* p = l;
    int a = 0;
    while(p != NULL){
        a++;
        p = p->prox;
    }
    return a;
}

int crescente(Lista* l){ //retorna 1 se estiver em ordem crescente ou vazia e 0 se n estiver
    Lista* p = l;
    int a = -2147483647;
    while(p != NULL){
        if(p->info >= a){
            a = p->info;
            p = p->prox;
        } else {
            return 0;
        }
    }
    return 1;
}

int compara(Lista* l1, Lista* l2){
    Lista *p = l1, *o = l2;
    while(p != NULL && o != NULL){
        if( p->info != o->info){
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

Lista* troca(Lista* l, int a, int b){
    Lista *p = l, *o = l, *antp = l, *anto = l, *primeiro = l, *ultimo = l, *aux;
    int quant = conteListaRecursiva(l), i;
    if(a > quant || b > quant || a <= 0 || b <= 0){
        printf("\nPosicoes incorretas\n");
        return l;
    }

    if(a == b){
        return l;
    }
    if (a > b){
        a = a + b;
        b = a - b;
        a = a - b;
    }
    for( i = 0; i < quant - 1; i++){
        ultimo = ultimo->prox;
    }
    ultimo->prox = l;
    if(a == 1){
        antp = ultimo;
    }
    for( i = 0; i < b - 1; i++){
        if(i < a - 1){
            p = p->prox;
            if(a > 1 && i < a - 2){
                antp = antp->prox;
            }
        }
        o = o->prox;
        if(i < b - 2){
            anto = anto->prox;
        }
    }
    if(a == 1){
        primeiro = o;
    }
    aux = antp->prox;
    antp->prox = anto->prox;
    anto->prox = aux;
    aux = p->prox;
    p->prox = o->prox;
    o->prox = aux;
    ultimo = primeiro;
    for( i = 0; i < quant - 1; i++){
        ultimo = ultimo->prox;
    }
    ultimo->prox = NULL;
    return primeiro;
}


