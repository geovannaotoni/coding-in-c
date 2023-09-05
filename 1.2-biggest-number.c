#include <stdio.h>

int main() {
    int biggest, num1, num2, num3;
    printf("Digite o valor do primeiro número inteiro: ");
    scanf("%d", &num1);
    
    printf("Digite o valor do segundo número inteiro: ");
    scanf("%d", &num2);
    
    printf("Digite o valor do terceiro número inteiro: ");
    scanf("%d", &num3);
    
    if (num1 > num2 && num1 > num3) {
        biggest = num1;
    } else if (num2 > num1 && num2 > num3) {
        biggest = num2;
    } else {
        biggest = num3;
    }
    
    printf("%d", biggest);

    return 0;
}
