#include <stdio.h>
#include <math.h>

int primo(long long int numero) {
    if (numero < 2) {
        return -1;
    }
    
    int eh_primo = 1;
    for(int i = 2; i <= sqrt(numero); i++) {
        if(numero % i == 0) {
            eh_primo = 0;
        }
    }
    return eh_primo;
}

int main() {
    long long int numero;
    while(scanf("%lld", &numero) != EOF) { // EOF = end of file
        printf("%d\n", primo(numero));
    }
}
