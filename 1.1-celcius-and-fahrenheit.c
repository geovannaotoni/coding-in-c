#include <stdio.h>

int main() {
    float celsius, fahrenheit;
    printf("Digite o valor da temperatura em graus Celsius: ");
    scanf("%f", &celsius);
    
    fahrenheit =  (1.8 * celsius + 32);
    
    printf("%.0f", fahrenheit);

    return 0;
}
