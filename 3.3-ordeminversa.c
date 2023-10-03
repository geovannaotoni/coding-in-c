#include <stdio.h>

int main() {
    int vetor[10];
    int i;
    for(i = 0; i <= 9; i++) {
        printf("Digite o valor: ");
        scanf("%d", &vetor[i]);
    }
    
    for(i = 9; i >= 0; i--) {
        printf("%d\n", vetor[i]);
    }
    
    return 0;
}
