#include <stdio.h>
#include <stdlib.h>

int **aloca_matriz(int linhas, int colunas) {
    int **M = (int **)calloc(linhas, sizeof(int));
    if (M == NULL) {
        printf("Erro: Memória Insuficiente!\n");
        exit(1);
    }
    
    for(int i = 0; i < linhas; i++) {
        M[i] = (int *)calloc(colunas, sizeof(int));
    }
    return M;
}

void leitura_matriz(int **m, int linhas, int colunas) {
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            scanf("%d", &m[i][j]);
        }
    }
}

void imprime_matriz(int **m, int linhas, int colunas) {
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

void libera_matriz(int **m, int linhas) {
    for(int i = 0; i < linhas; i++) {
        free(m[i]);
    }
    free(m);
}

int main() {
    int linhas, colunas;
    scanf("%d", &linhas);
    scanf("%d", &colunas);
    
    int **M = aloca_matriz(linhas, colunas);
    
    leitura_matriz(M, linhas, colunas);
    
    imprime_matriz(M, linhas, colunas);
    
    libera_matriz(M, linhas);
    
    return 0;
}
