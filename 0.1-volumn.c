// 1) Leia a altura e raio de um cilindro circular e imprima o volume desse cilindro. V = pi*r^2*h, em que pi = 3.141592
#include <stdio.h>
#define pi 3.141592

int main() {
    float height, radius, volumn;
    printf("Digite a altura do cilindro circular: ");
    scanf("%f", &height);

    printf("Digite o raio do cilindro circular: ");
    scanf("%f", &radius);

    volumn = pi * radius * radius * (float) height;

    printf("O volume é de %f", volumn);
    return 0;
}
