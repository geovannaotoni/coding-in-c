#include <stdio.h>
#include <stdlib.h>

void leitura_vetor(int *p, int n) {
    for(int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
}

void imprime_vetor(int *p, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d\n", p[i]);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    int *p = (int *)calloc(n, sizeof(int));
    if (p == NULL) {
        printf("Erro: Memória Insuficiente!\n");
    }
    
    leitura_vetor(p, n);
    
    imprime_vetor(p, n);
    
    free(p);
}
