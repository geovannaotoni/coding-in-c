#include <stdio.h>
#include <stdlib.h>

//  Passar passar um arquivo como parâmetro para o programa, é necessário passar 2 paramêtros para a função: 
// argc: número de argumentos passados para o programa na linha de comando
// argv: um array de strings que contém os argumentos passados para o programa
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Digite o nome do arquivo em txt\n");
        system("pause");
        exit(1);
    }
    
    FILE *arquivo; // manipulador do arquivo
    arquivo = fopen(argv[1], "r"); // abertura do arquivo
    
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
