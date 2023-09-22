#include <stdio.h>

int main() {
    int num = 233, fim = 457;
    do {
        printf("%d\n", num);
        if(num >= 300 && num <= 400) {
            num += 3;
        } else {
            num += 5;
        }

    } while (num <= fim);
    return 0;
}
