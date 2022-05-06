#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include "Lista.h"


struct lista2{
	struct lista2 *ant;
	int info;
	struct lista2 *prox;
};


Lista2* insereFim(Lista2 *L, int v){
	Lista2 *novo, *aux=L;
	novo = (Lista2*) malloc(sizeof(Lista2));
	novo->info = v;
	novo->prox = NULL;
	if(L!=NULL){
		while(aux->prox!=NULL)
			aux = aux->prox;
		novo->ant = aux;
		aux->prox = novo;
		return L;
	}
	else{
		novo->ant = NULL;
		return novo;
	}

}

void imprimir(Lista2 *L){
	Lista2 *aux=L;

	while(aux!=NULL){
		printf("[%d] -> ",aux->info);
		aux = aux->prox;
	}
}


int conteListaRecursiva (Lista2* l){
    int b = 0;
    Lista2 *p = l;
    if(p == NULL){
        return b;
    } else{
        return 1 + conteListaRecursiva(p->prox);
    }
}

int conteListaIterativa (Lista2* l) {
    Lista2* p = l;
    int a = 0;
    while(p != NULL){
        a++;
        p = p->prox;
    }
    return a;
}

int crescente(Lista2* l){ //retorna 1 se estiver em ordem crescente ou vazia e 0 se n estiver
    Lista2* p = l;
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

int compara(Lista2* l1, Lista2* l2){
    Lista2 *p = l1, *o = l2;
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

Lista2* troca(Lista2* l, int a, int b){
    Lista2* p = l, *o = l, *anterior, *proximo, *primeiro = l, *ultimo = l;
    int i, c = conteListaRecursiva(l);

    if(a > c || b > c){
        printf("Posicoes incorretas");
        return 0;
    }
    if(a == b){
        return l;
    }
    if( b < a){
        a = a + b;
        b = a - b;
        a = a - b;
    }
    for(i = 0;i < a - 1; i++){
        p = p->prox;
    }
    for(i = 0;i < b - 1; i++){
        o = o->prox;
    }
    while(ultimo->prox != NULL){
        ultimo = ultimo->prox;
    }
    ultimo->prox = primeiro;
    primeiro->ant = ultimo;
    if(a == 1 || b == 1){
        if(a ==1){
            primeiro = o;
        }
    }
    anterior = o->ant;
    proximo = o->prox;
    p->ant->prox = o;
    o->ant->prox = p;
    p->prox->ant = o;
    o->prox->ant = p;
    o->prox = p->prox;
    o->ant = p->ant;
    p->prox = proximo;
    p->ant = anterior;
    ultimo = primeiro;
    for (i = 0; i < c - 1; i++){
        ultimo = ultimo->prox;
    }
    ultimo->prox = NULL;
    primeiro->ant = NULL;
    return primeiro;
}


