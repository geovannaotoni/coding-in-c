#include <stdio.h>

int main() {
    int linhas, colunas, i, j;
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
    
    for(i = 0; i < linhas; i++) {
        for(j = 0; j < colunas; j++) {
            printf("%d ",- matriz[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
