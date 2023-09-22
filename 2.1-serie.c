#include <stdio.h>

int main() {
    int n, x0, x1, xn, i;
    printf("Digite o valor de termos da série: ");
    scanf("%d", &n);
    printf("Digite o termo x0: ");
    scanf("%d", &x0);
    printf("Digite o termo x1: ");
    scanf("%d", &x1);
    printf("X0: %d\n", x0);
    printf("X1: %d\n", x1);
    
    for(i = 2; i <= n; i++) {
        xn = 4 * x1 - 2 * x0;
        printf("X%d: %d\n", i, xn);
        x0 = x1;
        x1 = xn;
    }
    
    return 0;
}
