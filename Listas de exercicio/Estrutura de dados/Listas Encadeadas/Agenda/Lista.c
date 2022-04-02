#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <string.h>
#include "Lista.h"

struct lista{
	int ddd, contato;
	int dia, mes, ano;
	char complemento[50],rua[50], bairro[50], cidade[50],estado[50],pais[40];
	int cep, numero;
	char cpf[15], nome[100],email[100], obser[500];
	struct lista *prox;
};



void imprimir(Lista *L){
	Lista *p = L;
	printf("\n");
	while(p!=NULL){
		printf("\nnome: %s \n", p->nome);
		printf("CPF: %s \n", p->cpf);
		printf("e-mail: %s \n", p->email);
		printf("telefone: (%d) %d \n", p->ddd, p->contato);
		printf("Data de aniversario: %d/%d/%d\n", p->dia, p->mes, p->ano);
		printf("endereco: %s, %d, %s, %s, %d, %s, %s, %s \n", p->rua, p->numero, p->complemento, p->bairro, p->cep, p->cidade, p->estado, p->pais);
		printf("Observacao: %s \n\n", p->obser);
		p = p->prox;
	}
}

Lista* inserirPessoa(Lista* L){
	Lista *novo, *p=L;
	novo = (Lista*)malloc(sizeof(Lista));
	printf("\nINFORMACOES PESSOAIS\n");
	printf("Digite o nome do contato: ");
	scanf(" %[^\n]s", novo->nome);
    printf("Digite o cpf do contato: ");
	scanf(" %[^\n]s", novo->cpf);
    printf("Digite o e-mail do contato: ");
	scanf(" %[^\n]s", novo->email);
	printf("\nNUMERO DE TELEFONE\n");
	printf("Digite o ddd do contato: ");
	scanf(" %d", &novo->ddd);
	printf("Digite o numero de telefone do contato: ");
	scanf(" %d", &novo->contato);
	printf("\nENDERECO\n");
	printf("Digite a rua do contato: ");
	scanf(" %[^\n]s", novo->rua);
	printf("Digite o numero do endereco do contato: ");
	scanf(" %d", &novo->numero);
	printf("Digite o complemento do endereco do contato: ");
	scanf(" %[^\n]s", novo->complemento);
	printf("Digite o bairro do endereco do contato: ");
	scanf(" %[^\n]s", novo->bairro);
	printf("Digite o CEP do endereco do contato: ");
	scanf(" %d", &novo->cep);
	printf("Digite a cidade do endereco do contato: ");
	scanf(" %[^\n]s", novo->cidade);
	printf("Digite o estado do endereco do contato: ");
	scanf(" %[^\n]s", novo->estado);
	printf("Digite o pais do endereco do contato: ");
	scanf(" %[^\n]s", novo->pais);
	printf("\nDATA DE NASCIMENTO\n");
	printf("Digite o dia: ");
	scanf(" %d", &novo->dia);
	printf("Digite o mes: ");
	scanf(" %d", &novo->mes);
	printf("Digite o ano: ");
	scanf(" %d", &novo->ano);
	printf("\nOBSERVACOES\n");
	printf("Digite uma observacao: ");
	scanf(" %[^\n]s", novo->obser);
	novo->prox = NULL;

	if(L!=NULL){
		while(p->prox!=NULL){
			p = p->prox;
		}
		p->prox = novo;
		return L;
	}
	else{
		return novo;
	}
}

Lista* retirar(Lista* L){
	Lista *p=L, *ant=NULL;
	char cpf[15];
    printf("Qual o cpf do contato que voce deseja excluir: ");
    scanf(" %[^\n]s", cpf);
	while(p!=NULL && strcmp(p->cpf, cpf) != 0){
		ant = p;
		p = p->prox;
	}

	if (p==NULL){
		printf("\nElemento nao encontrado para retirar!!!\n");
		return L;
	}

	if (ant==NULL){
		L = p->prox; //retirando o elemento do início da lista
	}
	else{
		ant->prox = p->prox;
	}

	free(p);
	return L;
}

void procurarCpf(Lista* L){
	Lista *p=L;
	char cpf[15];
    printf("Qual o cpf do contato que voce deseja visualizar: ");
    scanf(" %[^\n]s", cpf);
    while(p!=NULL && strcmp(p->cpf, cpf) != 0){
        p = p->prox;
    }
    if(p == NULL){
        printf("\nElemento nao encontrado para visualizar!!!\n");
		return L;
    } else {
        printf("\nnome: %s \n", p->nome);
		printf("CPF: %s \n", p->cpf);
		printf("e-mail: %s \n", p->email);
		printf("telefone: (%d) %d \n", p->ddd, p->contato);
		printf("Data de aniversario: %d/%d/%d\n", p->dia, p->mes, p->ano);
		printf("endereco: %s, %d, %s, %s, %d, %s, %s, %s \n", p->rua, p->numero, p->complemento, p->bairro, p->cep, p->cidade, p->estado, p->pais);
		printf("Observacao: %s \n\n", p->obser);
    }
}

void procurarNome(Lista* L){
	Lista *p=L;
	char nome[25];
    printf("Qual o primeiro nome do contato que voce deseja visualizar: ");
    scanf("%s", nome);
    while(p!=NULL && strncmp(p->nome, nome, strlen(nome) - 1) != 0){
        p = p->prox;
    }
    if(p == NULL){
        printf("\nElemento nao encontrado para visualizar!!!\n");
    } else {
        printf("\nnome: %s \n", p->nome);
		printf("CPF: %s \n", p->cpf);
		printf("e-mail: %s \n", p->email);
		printf("telefone: (%d) %d \n", p->ddd, p->contato);
		printf("Data de aniversario: %d/%d/%d\n", p->dia, p->mes, p->ano);
		printf("endereco: %s, %d, %s, %s, %d, %s, %s, %s \n", p->rua, p->numero, p->complemento, p->bairro, p->cep, p->cidade, p->estado, p->pais);
		printf("Observacao: %s \n\n", p->obser);
    }
}

Lista* editarContato(Lista* L){
	Lista *p=L;
	char cpf[15];
    printf("Qual o cpf do contato que voce deseja editar: ");
    scanf(" %[^\n]s", cpf);
    while(p!=NULL && strcmp(p->cpf, cpf) != 0){
        p = p->prox;
    }
    if(p == NULL){
        printf("\nElemento nao encontrado para visualizar!!!\n");
		return L;
    } else {
        printf("\nINFORMACOES PESSOAIS\n");
        printf("Digite o nome do contato: ");
        scanf(" %[^\n]s", p->nome);
        printf("Digite o cpf do contato: ");
        scanf(" %[^\n]s", p->cpf);
        printf("Digite o e-mail do contato: ");
        scanf(" %[^\n]s", p->email);
        printf("\nNUMERO DE TELEFONE\n");
        printf("Digite o ddd do contato: ");
        scanf(" %d", &p->ddd);
        printf("Digite o numero de telefone do contato: ");
        scanf(" %d", &p->contato);
        printf("\nENDERECO\n");
        printf("Digite a rua do contato: ");
        scanf(" %[^\n]s", p->rua);
        printf("Digite o numero do endereco do contato: ");
        scanf(" %d", &p->numero);
        printf("Digite o complemento do endereco do contato: ");
        scanf(" %[^\n]s", p->complemento);
        printf("Digite o bairro do endereco do contato: ");
        scanf(" %[^\n]s", p->bairro);
        printf("Digite o CEP do endereco do contato: ");
        scanf(" %d", &p->cep);
        printf("Digite a cidade do endereco do contato: ");
        scanf(" %[^\n]s", p->cidade);
        printf("Digite o estado do endereco do contato: ");
        scanf(" %[^\n]s", p->estado);
        printf("Digite o pais do endereco do contato: ");
        scanf(" %[^\n]s", p->pais);
        printf("\nDATA DE NASCIMENTO\n");
        printf("Digite o dia: ");
        scanf(" %d", &p->dia);
        printf("Digite o mes: ");
        scanf(" %d", &p->mes);
        printf("Digite o ano: ");
        scanf(" %d", &p->ano);
        printf("\nOBSERVACOES\n");
        printf("Digite uma observacao: ");
        scanf(" %[^\n]s", p->obser);
    }
    return L;
}

void* aniversariantes(Lista* L){
    Lista *p=L;
    int mes;
    printf("Digite o mes para buscar aniversariantes: ");
    scanf("%d", &mes);
    printf("\n\tANIVERSARIANTES DO MES\n\n");
    while(p!=NULL){
        if(p->mes == mes){
            printf("\nnome: %s \n", p->nome);
            printf("CPF: %s \n", p->cpf);
            printf("e-mail: %s \n", p->email);
            printf("telefone: (%d) %d \n", p->ddd, p->contato);
            printf("Data de aniversario: %d/%d/%d\n", p->dia, p->mes, p->ano);
        }
        printf("\n");
        p = p->prox;
    }
}
