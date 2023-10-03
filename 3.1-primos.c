#include <stdio.h>
#define MAX 10000

int main() {
    int a, b, i, j;
    printf("Digite o primeiro valor: ");
    scanf("%d", &a);
    
    printf("Digite o segundo valor: ");
    scanf("%d", &b);
    
    if (a <= 0 || b <= 0 || a > MAX || b > MAX) {
        printf("Os valores devem ser inteiros positivos menores que %d\n", MAX);
        return 1;
    }
    
    if (a < 2) {
        a = 2;
    }
    
    for(i = a; i <= b; i++) {
        int ehprimo = 1;
        for(j = 2; j < i; j++) {
            if(i % j == 0) {
                ehprimo = 0;
                break;
            }
        }
        if (ehprimo) {
            printf("%d\n", i);
        }
    }

    return 0;
}
