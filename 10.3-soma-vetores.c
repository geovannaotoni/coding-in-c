#include <stdio.h>
#include <stdlib.h>

int *leitura_vetor(int n) {
    int *p = (int *)calloc(n, sizeof(int));
    if (p == NULL) {
        printf("Erro: Memória Insuficiente!\n");
    }
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    
    return p;
}

void imprime_vetor(int *p, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d\n", p[i]);
    }
}

int *soma_vetores(int *vetor1, int *vetor2, int *vetor3, int n) {
    for(int i = 0; i < n; i++) {
        vetor3[i] = vetor1[i] + vetor2[i];
    }
}

int main() {
    int tamanho;
    scanf("%d", &tamanho);
    
    int *vetor1 = leitura_vetor(tamanho);
    int *vetor2 = leitura_vetor(tamanho);
    int *vetor3 = leitura_vetor(tamanho);
    
    soma_vetores(vetor1, vetor2, vetor3, tamanho);
    
    imprime_vetor(vetor3, tamanho);
    
    free(vetor1);
    free(vetor2);
    free(vetor3);
    
    return 0;
}
