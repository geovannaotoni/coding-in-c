#include <stdio.h>
#include <string.h>

int main() {
    struct endereco {
        char rua[50];
        int numero;
        char estado[50];
    };
    struct pessoa {
        char nome[50];
        int idade;
        float salario;
        struct endereco end;
    };
    
    struct pessoa p[5];
    
    int continuar = 1; 
    int i = 0; // espaço ocupado na matriz p
    
    while(continuar) {
        char operacao[10];
        // printf("Digite a operação: ");
        fgets(operacao, 100, stdin);
        operacao[strlen(operacao) - 1] = '\0'; // remover o caractere de nova linha

        if(strcmp(operacao, "inserir") == 0) {
            scanf("%s %d %f %s %d %s", p[i].nome, &p[i].idade, &p[i].salario, p[i].end.rua, &p[i].end.numero, p[i].end.estado);
            getchar(); // consome o caractere de nova linha \n
            if(i < 5) {
                printf("Registro %s %d %.2f %s %d %s inserido\n", p[i].nome, p[i].idade, p[i].salario, p[i].end.rua, p[i].end.numero, p[i].end.estado);
                i++;
            } else {
                printf("Espaco insuficiente\n");
            }
        } else if (strcmp(operacao, "mostrar") == 0) {
            char nome[50];
            fgets(nome, 50, stdin);
            nome[strlen(nome) - 1] = '\0';
            int encontrou = 0;
            for(int j = 0; j < 5; j++) {
                if(strcmp(nome, p[j].nome) == 0) {
                    printf("Registro %s %d %.2f %s %d %s\n", p[j].nome, p[j].idade, p[j].salario, p[j].end.rua, p[j].end.numero, p[j].end.estado);
                    encontrou = 1;
                    break;
                }
            }
            if (!encontrou) {
                printf("Registro ausente\n");
            }
        } else if (strcmp(operacao, "alterar") == 0) {
            struct pessoa alter;
            scanf("%s %d %f %s %d %s", alter.nome, &alter.idade, &alter.salario, alter.end.rua, &alter.end.numero, alter.end.estado);
            getchar(); // consome o caractere de nova linha \n
            int encontrou = 0;
            for(int j = 0; j < 5; j++) {
                if(strcmp(p[j].nome, alter.nome) == 0) {
                    p[j] = alter;
                    printf("Registro %s %d %.2f %s %d %s alterado\n", p[j].nome, p[j].idade, p[j].salario, p[j].end.rua, p[j].end.numero, p[j].end.estado);
                    encontrou = 1;
                    break;
                }
            }
            if (!encontrou) {
                printf("Registro ausente para alteracao\n");
            }
        } else {
            continuar = 0;
        }
    }
    
    return 0;
}
