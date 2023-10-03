#include <stdio.h>

int main() {
    int fibonacci[800];
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    
    int i, x;
    for(i = 2; i < 800; i++) {
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
    }
    
    while(x >= 0 && x < 800) {
        scanf("%d", &x);
        printf("%d\n", fibonacci[x]);
    }
    
    return 0;
}
