#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    printf("Digite a primeira string: ");
    fgets(str1, 100, stdin);
    
    printf("Digite a segunda string: ");
    fgets(str2, 100, stdin);
    
    int substring = 0;
    int tamanhoStr1 = strlen(str1) - 1; // removendo o último caractere '\n';
    int tamanhoStr2 = strlen(str2) - 1;

    for(int i = 0; i <= tamanhoStr1 - tamanhoStr2; i++) {
        if(str1[i] == str2[0]) {
            int j = 0;
            for(j = 0; j < tamanhoStr2; j++) {
               if(str1[i+j] != str2[j]) {
                   break;
                }
            }
           
            if(j == tamanhoStr2) {
                substring = 1;
            }
        }
    }
    
    if(substring) {
        printf("É substring");
    } else {
        printf("Não é substring");
    }
    
    return 0;
}
