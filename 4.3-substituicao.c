#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], char1, char2;
    printf("Digite a string: ");
    fgets(str1, 100, stdin);
    
    // necessário colocar um espaço antes de ler o caractere, pois se não ele considera o \n do enter como o caractere digitado
    printf("Digite o caractere a ser substituído: ");
    scanf(" %c", &char1);
    
    printf("Digite o caractere que o substituirá: ");
    scanf(" %c", &char2);
    
    int tamanho = strlen(str1);

    for(int i = 0; i < tamanho; i++) {
        if(str1[i] == char1) {
            str1[i] = char2;
            break;
        }
    }
    
    fputs(str1, stdout);
    
    return 0;
}
