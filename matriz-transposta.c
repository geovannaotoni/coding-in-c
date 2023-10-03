#include <stdio.h>

int main() {
    int linhas, colunas;
    printf("Digite o número de linhas e de colunas da matriz: ");
    scanf("%d %d", &linhas, &colunas);
    int matriz[linhas][colunas];
    
    for(int l = 0; l < linhas; l++) {
        for(int c = 0; c < colunas; c++) {
            int valor;
            printf("Digite o valor da posição %d %d: ", l, c);
            scanf("%d", &valor);
            matriz[l][c] = valor;
        }
    }
    
    for(int c = 0; c < colunas; c++){
        for(int l = 0; l < linhas; l++){
            printf("%d ", matriz[l][c]);
        }
        printf("\n");
    }

    return 0;
}
