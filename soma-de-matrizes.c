#include <stdio.h>

int main() {
    int linhas, colunas;
    printf("Digite o número de linhas e de colunas das matrizes: ");
    scanf("%d %d", &linhas, &colunas);
    int matriz1[linhas][colunas];
    int matriz2[linhas][colunas];
    
    printf("### Matriz 1: ###\n");
    for(int l = 0; l < linhas; l++) {
        for(int c = 0; c < colunas; c++) {
            int valor;
            printf("Digite o valor da posição %d %d: ", l, c);
            scanf("%d", &valor);
            matriz1[l][c] = valor;
        }
    }
    
    printf("### Matriz 2: ###\n");
    for(int l = 0; l < linhas; l++) {
        for(int c = 0; c < colunas; c++) {
            int valor;
            printf("Digite o valor da posição %d %d: ", l, c);
            scanf("%d", &valor);
            matriz2[l][c] = valor;
        }
    }
    
    for(int l = 0; l < linhas; l++) {
        for(int c = 0; c < colunas; c++) {
            printf("%d ", matriz1[l][c] + matriz2[l][c]);
        }
        printf("\n");
    }

    return 0;
}
