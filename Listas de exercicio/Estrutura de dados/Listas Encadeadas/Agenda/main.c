#include<conio.h>
#include<stdlib.h>
#include "Lista.h"

int main(){
	Lista *L1=NULL;
    int escolha = 0;
    do{
        printf("\n\tAGENDA\n\n");
        printf("1 - ADICIONAR CONTATO\n");
        printf("2 - MOSTRAR TODOS OS CONTATOS\n");
        printf("3 - EXCLUIR CONTATO\n");
        printf("4 - BUSCAR CONTATOS\n");
        printf("5 - ALTERAR UM CONTATO\n");
        printf("6 - MOSTRAR ANIVERSARIANTES DE UM MES\n");
        printf("0 - SAIR\n\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &escolha);
        switch(escolha){
        case 0:
            break;
        case 1:
            L1 = inserirPessoa(L1);
            break;
        case 2:
            imprimir(L1);
            printf("\n\nPRESSIONE ENTER PARA CONTINUAR\n");
            getch();
            break;
        case 3:
            L1 = retirar(L1);
            break;
        case 4:
            printf("\n1 - BUSCAR CONTATO PELO NOME\n");
            printf("2 - BUSCAR CONTATO PELO CPF\n");
            scanf("%d", &escolha);
            switch(escolha){
            case 1:
                procurarNome(L1);
                printf("\n\nPRESSIONE ENTER PARA CONTINUAR\n");
                getch();
                break;
            case 2:
                procurarCpf(L1);
                printf("\n\nPRESSIONE ENTER PARA CONTINUAR\n");
                getch();
                break;
            default:
                printf("\nOPCAO INVALIDA\n");
            }
            break;
        case 5:
            L1 = editarContato(L1);
            break;
        case 6:
            aniversariantes(L1);
            printf("\n\nPRESSIONE ENTER PARA CONTINUAR\n");
            getch();
            break;
        default:
            printf("\nOPCAO INVALIDA\n");
            break;
        }
    }while (escolha != 0);
    printf("\n\nPRESSIONE ENTER PARA SAIR\n");
	getch();

}
