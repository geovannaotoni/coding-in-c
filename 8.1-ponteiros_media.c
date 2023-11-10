#include <stdio.h>
#include <math.h>

void media(double vet[], int n, int *i) {
    int total = 0, media;
    for (int j = 0; j < n; j++) {
        total += vet[j];
    }
    
    media = total / n;
    
    // fabs: retorna o valor absoluto de um número de ponto flutuante
    double diferenca = fabs(media - vet[0]);
    // i armazena a posição do elemento que tem o valor mais proximo da media
    *i = 0;
    for (int j = 1; j < n; j++) {
        if(fabs(media - vet[j]) < diferenca) {
            diferenca = fabs(media - vet[j]);
            *i = j;
        }
    }
    
}

int main() {
    int tamanho;
    scanf("%d", &tamanho);
    
    double vet[tamanho];
    for (int j = 0; j < tamanho; j++) {
        scanf("%lf", &vet[j]); // &vet[j] = vet + j
    }
    
    int i; 
    media(vet, tamanho, &i); 
    printf("%d", i);
    
    return 0;
}
