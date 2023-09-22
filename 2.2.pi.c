#include <stdio.h>
#include <math.h>

int main() {
    double x;
    double pi = 0.0;
    int i;
    double numerador = 4.0;
    
    printf("Digite o valor da diferença máxima: ");
    scanf("%lf", &x); // necessário que seja long float (lf)
    
    // fabs calcula o valor absoluto
    for(i = 0; fabs(M_PI - pi) >= x; i++) {
        pi += numerador / (2 * i + 1);
        numerador = -numerador;
    }
    printf("%d", i);
    return 0;
}
