#include <stdio.h>
#include <stdlib.h>

int **aloca_matriz(int linhas, int colunas) {
    int **M = (int **)calloc(linhas, sizeof(int *));
    if (M == NULL) {
        printf("Erro: Memória Insuficiente!\n");
        exit(1);
    }
    
    for(int i = 0; i < linhas; i++) {
        M[i] = (int *)calloc(colunas, sizeof(int));
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &M[i][j]);
        }
    }
    
    return M;
}

void imprime_e_libera_matriz(int **M, int linhas, int colunas) {
    for(int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
        free(M[i]);
    }
    
    free(M);
}

int main() {
    int linhas, colunas;
    scanf("%d", &linhas);
    scanf("%d", &colunas);
    
    int **M = aloca_matriz(linhas, colunas);
    
    imprime_e_libera_matriz(M, linhas, colunas);
    
    return 0;
}
