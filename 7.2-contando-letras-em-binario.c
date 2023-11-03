#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char arq[100];
    fgets(arq, 100, stdin); // solicitar o arquivo
    arq[strlen(arq) - 1] = '\0'; // altera o \n para \0
    
    FILE *arquivo; // manipulador do arquivo
    arquivo = fopen(arq, "rb"); // abertura do arquivo binário
    
    if(arquivo == NULL) {
        printf("Erro na abertura do arquivo\n");
        system("pause");
        exit(1);
    }
    
    char c;
    int count = 0;
    
    while((c = fgetc(arquivo)) != EOF) {
        if (c == 'a') count++;
    }
    
    fclose(arquivo);
    printf("%d", count);
    return 0;
}
