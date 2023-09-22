#include <stdio.h>

int main () {
    int x, soma = 0, i;
    printf("Digite um número inteiro: ");
    scanf("%d", &x);
    
    for(i = 1; i <= x; i++) {
        soma += i;
    }
    printf("%d", soma);
    
    return 0;
}
