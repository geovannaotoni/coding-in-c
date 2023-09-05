#include <stdio.h>

int main() {
    int x, y, z;
    printf("Digite o valor de x: ");
    scanf("%d", &x);
    
    printf("Digite o valor de y: ");
    scanf("%d", &y);
    
    printf("Digite o valor de z: ");
    scanf("%d", &z);
    
    if (x % y == 0 && x % z == 0) {
        printf("O número é divisível");
    } else {
        printf("O número não é divisível");
    }

    return 0;
}
