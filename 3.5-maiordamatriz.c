#include <stdio.h>

int main() {
    int linhas, colunas, i, j, maior;
    printf("Digite o número de linhas: ");
    scanf("%d", &linhas);
    
    printf("Digite o número de colunas: ");
    scanf("%d", &colunas);
    
    int matriz[linhas][colunas];
    
    for(i = 0; i < linhas; i++) {
        for(j = 0; j < colunas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
    
    maior = matriz[0][0];
    for(i = 0; i < linhas; i++) {
        for(j = 0; j < colunas; j++) {
            if (matriz[i][j] > maior) {
                maior = matriz[i][j];
            }
        }
    }
    
    printf("%d", maior);
    
    return 0;
}
