#include <stdio.h>

int main() {
    int num1, num2;
    printf("Digite o primeiro número: ");
    scanf("%d", &num1);
    
    printf("Digite o segundo número: ");
    scanf("%d", &num2);
    
    while(num1 % num2 != 0) {
        int resto = num1 % num2;
        num1 = num2;
        num2 = resto;
    }
    
    printf("%d", num2);

    return 0;
}
