#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Digite o grau: ");
    scanf("%d", &n);
    
    int coeficientes[n+1];
    printf("Digite os coeficientes: ");
    for(int i = 0; i <= n; i++) {
        scanf("%d", &coeficientes[i]);
    }
    
    int x;
    printf("Digite o valor de x: ");
    scanf("%d", &x);
    
    int resultado = 0;
    for(int i = 0; i <= n; i++) {
        resultado += coeficientes[i] * pow(x, i);
    }
    
    printf("%d", resultado);

    return 0;
}
// exemplo: x² + 12*x - 64. 
// Entradas: 2; -64 12 1; 4. 
// Saídas: 0  
