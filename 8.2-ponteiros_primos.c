#include <stdio.h>
#include <math.h>

int calcular_primo(int num) {
    if (num < 2) {
        return -1;
    }
    
    int eh_primo = 1;
    for(int i = 2; i <= sqrt(num); i++) {
        if(num % i == 0) {
            eh_primo = 0;
        }
    }
    return eh_primo;
}

void primos(int m, int *p1, int *p2) {
    *p1 = 0; // maior número primo que é menor do que m
    *p2 = 0; // menor número primo que é maior do que m

    for(int i = m - 1; i > 1; i--) {
        if(calcular_primo(i)) {
            *p1 = i;
            break;
        }
    }
    
    for(int i = m + 1;; i++) {
        if(calcular_primo(i)) {
            *p2 = i;
            break;
        }
    }
}

int main() {
    int num;
    scanf("%d", &num);
    
    int p1, p2; 
    primos(num, &p1, &p2);
    printf("%d\n%d", p1, p2);
    
    return 0;
}
