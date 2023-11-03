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
    
    long int matriz1[5][5];
    long int matriz2[5][5];
    long int matrizSoma[5][5];
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            fscanf(arquivo, "%ld", &matriz1[i][j]);
        }
    }
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            fscanf(arquivo, "%ld", &matriz2[i][j]);
            matrizSoma[i][j] = matriz1[i][j] + matriz2[i][j];
            printf("%ld ", matrizSoma[i][j]);
        }
        printf("\n");
    }
    
    fclose(arquivo);
    return 0;
}
