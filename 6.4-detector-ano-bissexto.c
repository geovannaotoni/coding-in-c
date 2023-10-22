#include <stdio.h>

int bissexto(int ano) {
    int bissexto = 0;
    if((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0) {
        bissexto = 1;
    }
    return bissexto;
}

int main() {
    int ano;
    while(scanf("%d", &ano) != EOF) { // EOF = end of file
        printf("%d\n", bissexto(ano));
    }
}
