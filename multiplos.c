#include <stdio.h>

int main () {
    int mult2 = 0, mult3 = 0, mult5 = 0, multAll = 0, i = 1, x;
    printf("Digite o valor de x: ");
    scanf("%d", &x);
    
    while(i <= x) {
        if(i % 2 == 0) {
            mult2 += 1;
        }
        if(i % 3 == 0) {
            mult3 += 1;
        }
        if(i % 5 == 0) {
            mult5 += 1;
        }
        if (i % 2 == 0 && i % 3 == 0 && i % 5 == 0) {
            multAll += 1;
        }
        i++;
    }
    
    printf("Múltiplos de 2: %d\n", mult2);
    printf("Múltiplos de 3: %d\n", mult3);
    printf("Múltiplos de 5: %d\n", mult5);
    printf("Múltiplos de todos: %d\n", multAll);
    
    return 0;
}
