#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contato {
    char nome[50];
    int idade;
    char telefone[20];
};

int main() {
    char arq[100];
    fgets(arq, 100, stdin); // solicitar o arquivo
    arq[strlen(arq) - 1] = '\0'; // altera o \n para \0
    
    FILE *arquivo; // manipulador do arquivo
    arquivo = fopen(arq, "rb"); // abertura do arquivo binário para leitura
    
    if(arquivo == NULL) {
        printf("Erro na abertura do arquivo\n");
        system("pause");
        exit(1);
    }
    
    struct contato contatos[100];
    
    int i = 0; // espaço ocupado na matriz contatos
    i = fread(contatos, sizeof(struct contato), 100, arquivo); // ler os dados armazenados no arquivo para o array contatos, se já houver algo
    rewind(arquivo); // retornar para o início do arquivo
    fclose(arquivo);
    

    char operacao[10];
    while(fgets(operacao, 100, stdin) != NULL) {
        operacao[strlen(operacao) - 1] = '\0'; // remover o caractere de nova linha

        if(strcmp(operacao, "Inserir") == 0) {
            if(i < 100) {
                scanf("%s %d %s", contatos[i].nome, &contatos[i].idade, contatos[i].telefone);
                getchar(); // consome o caractere de nova linha \n
                
                arquivo = fopen(arq, "ab"); // abertura do arquivo binário para escrita ao fim do arquivo
                fwrite(&contatos[i], sizeof(struct contato), 1, arquivo); // escrita de um bloco de dados da memória no arquivo
                rewind(arquivo); // retornar para o início do arquivo
                fclose(arquivo);
                
                printf("Registro %s %d %s inserido\n", contatos[i].nome, contatos[i].idade, contatos[i].telefone);
                i++;
            } else {
                printf("Espaco insuficiente\n");
            }
        } else if (strcmp(operacao, "Exibir") == 0) {
            char nome[50];
            fgets(nome, 50, stdin);
            nome[strlen(nome) - 1] = '\0';
            
            int encontrou = 0;
            for(int j = 0; j < i; j++) {
                if(strcmp(nome, contatos[j].nome) == 0) {
                    printf("Registro %s %d %s exibido\n", contatos[j].nome, contatos[j].idade, contatos[j].telefone);
                    encontrou = 1;
                    break;
                }
            }
            if (!encontrou) {
                printf("Registro %s invalido\n", nome);
            }
        } else if (strcmp(operacao, "Alterar") == 0) {
            struct contato alter;
            scanf("%s %d %s", alter.nome, &alter.idade, alter.telefone);
            getchar(); // consome o caractere de nova linha \n
            
            int encontrou = 0;
            for(int j = 0; j < i; j++) {
                if(strcmp(contatos[j].nome, alter.nome) == 0) {
                    contatos[j] = alter;
                    
                    arquivo = fopen(arq, "wb"); // abertura do arquivo binário para escrita ao início do arquivo
                    fwrite(contatos, sizeof(struct contato), i, arquivo);
                    rewind(arquivo); // retornar para o início do arquivo
                    fclose(arquivo);
                    
                    printf("Registro %s %d %s alterado\n", contatos[j].nome, contatos[j].idade, contatos[j].telefone);
                    encontrou = 1;
                    break;
                }
            }
            if (!encontrou) {
                printf("Registro %s invalido\n", alter.nome);
            }
        } else if (strcmp(operacao, "Excluir") == 0) {
            char nome[50];
            fgets(nome, 50, stdin);
            nome[strlen(nome) - 1] = '\0';
            int encontrou = 0;
            
            for(int j = 0; j < i; j++) {
                if(strcmp(nome, contatos[j].nome) == 0) {
                    printf("Registro %s %d %s excluido\n", contatos[j].nome, contatos[j].idade, contatos[j].telefone);
                    for (int pos = j; pos < i - 1; pos++) {
                        strcpy(contatos[pos].nome, contatos[pos + 1].nome);
                        contatos[pos].idade = contatos[pos + 1].idade;
                        strcpy(contatos[pos].telefone, contatos[pos + 1].telefone);
                    }
                    i--;
                    
                    arquivo = fopen(arq, "wb");
                    fwrite(contatos, sizeof(struct contato), i, arquivo);
                    rewind(arquivo); // retornar para o início do arquivo
                    fclose(arquivo);
                    
                    encontrou = 1;
                    break;
                }
            }
            if (!encontrou) {
                printf("Registro %s invalido\n", nome);
            }
        }
    }
    
    return 0;
}
