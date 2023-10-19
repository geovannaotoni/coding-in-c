#include <stdio.h>
#include <string.h>

int main() {
    struct pessoa {
        char nome[50];
        int idade;
        float salario;
    };
    
    struct pessoa p[4];
    
    int continuar = 1; 
    int i = 0; // espaço ocupado na matriz p
    
    while(continuar) {
        char operacao[10];
        // printf("Digite a operação: ");
        fgets(operacao, 100, stdin);
        operacao[strlen(operacao) - 1] = '\0'; // remover o caractere de nova linha

        if(strcmp(operacao, "inserir") == 0) {
            scanf("%s %d %f", p[i].nome, &p[i].idade, &p[i].salario);
            getchar(); // consome o caractere de nova linha \n
            if(i < 4) {
                printf("Registro %s %d %.2f inserido\n", p[i].nome, p[i].idade, p[i].salario);
                i++;
            } else {
                printf("Espaco insuficiente\n");
            }
        } else if (strcmp(operacao, "mostrar") == 0) {
            char nome[50];
            // printf("Digite o nome da pessoa a ser mostrada: ");
            fgets(nome, 50, stdin);
            nome[strlen(nome) - 1] = '\0';
            int encontrou = 0;
            for(int j = 0; j < 4; j++) {
                if(strcmp(nome, p[j].nome) == 0) {
                    printf("Registro %s %d %.2f\n", p[j].nome, p[j].idade, p[j].salario);
                    encontrou = 1;
                    break;
                }
            }
            if (!encontrou) {
                printf("Registro ausente\n");
            }
        } else {
            continuar = 0;
        }
    }
    
    return 0;
}
