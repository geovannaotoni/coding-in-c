#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], str3[200];
    printf("Digite a primeira string: ");
    fgets(str1, 100, stdin);
    // a função fgets lê o caractere de nova linha '\n', necessário substituí-lo por um caractere nulo
    str1[strlen(str1)-1] = '\0';
    
    printf("Digite a segunda string: ");
    fgets(str2, 100, stdin);
    
    strcpy(str3, str1);
    strcat(str3, str2);
    fputs(str3, stdout);
    
    return 0;
}
