#include <stdio.h>
#include <math.h>

int primo(long long int numero) {
    int eh_primo = 1;
    
    // otimização para retirar os pares da verificação
    if (numero % 2 == 0) {
        eh_primo = 0;
    }
    
    for(int i = 2; i <= sqrt(numero); i++) {
        if(numero % i == 0) {
            eh_primo = 0;
        }
    }
    return eh_primo;
}

long long int soma_primos(long long int quantidade_primos) {
    // já começa do número 2, que é primo, para otimizar o código
    long long int primos_encontrados = 1;
    long long int soma = 2;
    long long int num_atual = 3;
    
    while(primos_encontrados < quantidade_primos) {
        if(primo(num_atual)) {
            // primos[primos_encontrados] = num_atual;
            soma += num_atual;
            primos_encontrados++;
        }
        num_atual++;
    }
   
    return soma;
}

int main() {
    long long int numero;
    while(scanf("%lld", &numero) != EOF) { // EOF = end of file
        printf("%lld\n", soma_primos(numero));
    }
}
