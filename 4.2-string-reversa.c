#include <stdio.h>
#include <string.h>

int main() {
    char str1[100];
    printf("Digite a string: ");
    fgets(str1, 100, stdin);
    
    int tamanho = strlen(str1);

    // retirar o \n ao final da string e substituir por caractere nulo
    str1[tamanho - 1] = '\0';

    for(int i = tamanho - 1; i >= 0; i--) {
        printf("%c", str1[i]);
    }
    
    return 0;
}
