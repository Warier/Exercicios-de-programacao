#include <stdio.h>
#include <stdlib.h>

int main()
{
    int linha, coluna, *matrizVSimples, **matrizVDePonteiro;
    printf("Digite a quantidade de linhas da matriz: ");
    scanf("%d", &linha);
    printf("Digite a quantidade de colunas da matriz: ");
    scanf("%d", &coluna);
    matrizVSimples = (int*)malloc(sizeof(int)*linha*coluna);
    matrizVDePonteiro = (int**)malloc(linha*sizeof(int*));
    for(int l = 0; l< linha; l++){
        matrizVDePonteiro[l] = (int*)malloc(sizeof(int)*coluna);
    }
    for(int l = 0; l < linha; l++){
        for(int c = 0; c < coluna; c++){
            printf("Digite o valor de matriz[%d][%d]: ", l + 1, c + 1);
            scanf("%d", &matrizVSimples[l*coluna + c]);
            matrizVDePonteiro[l][c] = matrizVSimples[l*coluna + c];
        }
    }
    printf("MATRIZ ORIGINAL:\n");
    for(int l = 0; l < linha; l++){
        for(int c = 0; c < coluna; c++){
            printf(" %d", matrizVSimples[l*coluna + c]);
        }
        printf(" \n");
    }
    printf("\n");
    printf("MATRIZ TRANSPOSTA COM VETOR SIMPLES:\n");
    for(int l = 0; l < coluna; l++){
        for(int c = 0; c < linha; c++){
            printf(" %d", matrizVSimples[c*coluna + l]);
        }
        printf(" \n");
    }
    printf("\n");
    printf("MATRIZ TRANSPOSTA COM VETOR DE PONTEIROS: \n");
    for(int l = 0; l < coluna; l++){
        for(int c = 0; c < linha; c++){
            printf(" %d", matrizVDePonteiro[c][l]);
        }
        printf(" \n");
    }
    return 0;
}
