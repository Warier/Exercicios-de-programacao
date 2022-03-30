#include <stdio.h>
#include <stdlib.h>

int main()
{
    int linhaVS, linhaVDP, colunaVS, colunaVDP, *matrizVSimples, **matrizVDePonteiros, **matrizFinal;
    do{                                                               //guarda o tamanho da linha e da coluna de cada matriz e verifica se a multiplicaçao é possivel
        printf("Digite o numero de linhas da primeira matriz:");
        scanf("%d", &linhaVS);
        printf("Digite o numero de colunas da primeira matriz:");
        scanf("%d", &colunaVS);
        printf("Digite o numero de linhas da segunda matriz:");
        scanf("%d", &linhaVDP);
        printf("Digite o numero de colunas da segunda matriz:");
        scanf("%d", &colunaVDP);
        if(colunaVS != linhaVDP) {
            printf("\n\nPARA REALIZAR A MULTIPLICACAO DE MATRIZES, O NUMERO DE COLUNAS DA PRIMEIRA MATRIZ TEM QUE SER IGUAL AO NUMERO DE LINHAS DA SEGUNDA MATRIZ\n\n");
        }
    } while (colunaVS != linhaVDP);

    matrizVSimples = (int*)malloc(sizeof(int) * linhaVS * colunaVS); //aloca espaço para as matrizes
    matrizVDePonteiros = (int**)malloc(linhaVDP*sizeof(int*));
    for(int i = 0; i < linhaVDP; i++){
        matrizVDePonteiros[i] = (int*)malloc(sizeof(int)*colunaVDP);
    }
    matrizFinal = (int**)malloc(linhaVS*sizeof(int*));
    for(int i = 0; i < linhaVS; i++){
        matrizFinal[i] = (int*)malloc(sizeof(int)*colunaVDP);
    }

    for(int l = 0; l < linhaVS; l++){ //coloca como zero o valor de todas as posiçoes da matriz
        for(int c = 0; c < colunaVDP; c++){
            matrizFinal[l][c] = 0;
        }
    }

    for(int l = 0; l < linhaVS; l++){   //pega o valor de cada posiçao das matrizes
        for(int c = 0; c < colunaVS; c++){
            printf("Digite o valor da primeira matriz[%d][%d]: ", l + 1, c + 1);
            scanf("%d", &matrizVSimples[l*colunaVS + c]);
        }
    }
    printf("\n\n\n");
    for(int l = 0; l < linhaVDP; l++){
        for(int c = 0; c < colunaVDP; c++){
            printf("Digite o valor da segunda matriz[%d][%d]: ", l + 1, c + 1);
            scanf("%d", &matrizVDePonteiros[l][c]);
        }
    }

    printf("\n\nPRIMEIRA MATRIZ: \n");  //imprime as duas primeiras matrizes
    for(int l = 0; l < linhaVS; l++){
        for(int c = 0; c < colunaVS; c++){
            printf(" %d", matrizVSimples[l*colunaVS + c]);
        }
        printf(" \n");
    }
    printf("\n\nSEGUNDA MATRIZ:\n");
    for(int l = 0; l < linhaVDP; l++){
        for(int c = 0; c < colunaVDP; c++){
            printf(" %d", matrizVDePonteiros[l][c]);
        }
        printf(" \n");
    }


    printf("\n\nRESULTADO: \n");  // faz a multiplicaçao das matrizes e imprime
    for(int l = 0; l < linhaVS; l++){
        for(int c = 0; c < colunaVDP; c++){
            for(int i = 0; i < linhaVDP; i++){
                matrizFinal[l][c] += matrizVSimples[l*colunaVS + i] * matrizVDePonteiros[i][c];
            }
            printf(" %d", matrizFinal[l][c]);
        }
        printf(" \n");
    }

    return 0;
}
