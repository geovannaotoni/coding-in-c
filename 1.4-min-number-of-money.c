#include <stdio.h>

int main() {
    int reais, notas100, notas50, notas20, notas10, notas5, notas2, notas1;
    printf("Digite o valor inteiro em reais: ");
    scanf("%d", &reais);
    
    notas100 = reais / 100;
    reais = reais % 100;
    printf("100: %d\n", notas100);
    
    notas50 = reais / 50;
    reais = reais % 50;
    printf("50: %d\n", notas50);
    
    notas20 = reais / 20;
    reais = reais % 20;
    printf("20: %d\n", notas20);
    
    notas10 = reais / 10;
    reais = reais % 10;
    printf("10: %d\n", notas10);
    
    notas5 = reais / 5;
    reais = reais % 5;
    printf("5: %d\n", notas5);
    
    notas2 = reais / 2;
    reais = reais % 2;
    printf("2: %d\n", notas2);
    
    notas1 = reais / 1;
    reais = reais % 1;
    printf("1: %d\n", notas1);
    
    return 0;
}
