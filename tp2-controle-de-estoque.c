#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produto {
    int codigo;
    char nome[100];
    int quantidade;
    float preco;
    char estado[20];
};

void ordem_alfabetica(struct produto *estoque, int quant) {
    for (int i = 0; i < quant; i++) {
        for (int j = i + 1; j < quant; j++) {
            if (strcmp(estoque[i].nome, estoque[j].nome) > 0) {
                struct produto temp = estoque[i];
                estoque[i] = estoque[j];
                estoque[j] = temp;
            }
        }
    }
}

void gerar_relatorio(struct produto *estoque, int quant, char *arquivo_saida) {
    FILE *arquivo;
    arquivo = fopen(arquivo_saida, "w");

    ordem_alfabetica(estoque, quant);

    for (int i = 0; i < quant; i++) {
        fprintf(arquivo, "%d\n%s\n%d\n%.2f\n%s\n", estoque[i].codigo, estoque[i].nome, estoque[i].quantidade, estoque[i].preco, estoque[i].estado);
    }

    fclose(arquivo);
}

void produto_por_codigo(struct produto *estoque, int quant, char *cod) {
    struct produto p;
    int cod_num = atoi(cod); // converter a string do código para um inteiro

    for (int i = 0; i < quant; i++) {
        if (estoque[i].codigo == cod_num) {
            p = estoque[i];
            break;
        }
    }

    // imprimir o produto encontrado
    printf("%d\n%s\n%d\n%.2f\n%s\n", p.codigo, p.nome, p.quantidade, p.preco, p.estado);
}

void menor_quantidade_geral(struct produto *estoque, int quant) {
    // encontrar o produto com menor estoque
    struct produto menor_prod = estoque[0];

    for (int i = 1; i < quant; i++) {
        if (estoque[i].quantidade < menor_prod.quantidade) {
            menor_prod = estoque[i];
        }
    }

    // imprimir o produto encontrado
    printf("%d\n%s\n%d\n%.2f\n%s\n", menor_prod.codigo, menor_prod.nome, menor_prod.quantidade, menor_prod.preco, menor_prod.estado);
}

void produtos_por_estado(struct produto *estoque, int quant, char *est) {
    ordem_alfabetica(estoque, quant);

    for (int i = 0; i < quant; i++) {
        if (strcmp(estoque[i].estado, est) == 0) {
            printf("%d\n%s\n%d\n%.2f\n%s\n", estoque[i].codigo, estoque[i].nome, estoque[i].quantidade, estoque[i].preco, estoque[i].estado);
        }
    }
}

void menor_quantidade_estado(struct produto *estoque, int quant, char *est) {
    // encontrar o produto com menor estoque do estado
    struct produto menor_prod;
    int menor_quant = -1;

    for (int i = 0; i < quant; i++) {
        if (strcmp(estoque[i].estado, est) == 0) {
            if (menor_quant == -1 || estoque[i].quantidade < menor_quant) {
                menor_prod = estoque[i];
                menor_quant = estoque[i].quantidade;
            }
        }
    }

    // imprimir o produto encontrado
    printf("%d\n%s\n%d\n%.2f\n%s\n", menor_prod.codigo, menor_prod.nome, menor_prod.quantidade, menor_prod.preco, menor_prod.estado);
}


void quantidade_total(struct produto *estoque, int quant) {
    int total = 0;
    for (int i = 0; i < quant; i++) {
        total += estoque[i].quantidade;
    }
    printf("%d\n", total);
}

// Passar passar um arquivo como parâmetro para o programa, é necessário passar 2 paramêtros para a função main: 
// argc: número de argumentos passados para o programa na linha de comando
// argv: um array de strings que contém os argumentos passados para o programa
int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 4) {
        printf("Argumentos inválidos\n");
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
    
    int quantidade;
    fscanf(arquivo, "%d", &quantidade);
    fgetc(arquivo); // pular o \n

    struct produto estoque[quantidade];
    
    for(int i = 0; i < quantidade; i++) {
        // codigo
        fscanf(arquivo, "%d", &estoque[i].codigo);
        fgetc(arquivo); // pular o \n

        // nome
        fgets(estoque[i].nome, 100, arquivo);
        estoque[i].nome[strlen(estoque[i].nome) - 1] = '\0'; // remover o \n

        // quantidade
        fscanf(arquivo, "%d", &estoque[i].quantidade);
        fgetc(arquivo); // pular o \n

        // preco
        fscanf(arquivo, "%f", &estoque[i].preco);
        fgetc(arquivo); // pular o \n

        // estado
        fgets(estoque[i].estado, 20, arquivo);
        if (i != quantidade - 1) {
            estoque[i].estado[strlen(estoque[i].estado) - 1] = '\0'; // remover o \n
        }
    }

    fclose(arquivo);

    // 1. Gerar relatório de estoque
    if (strcmp(argv[2], "1") == 0) {
        gerar_relatorio(estoque, quantidade, argv[3]);
    }

    // 2. Pesquisar por produto pelo código
    if (strcmp(argv[2], "2") == 0) {
        produto_por_codigo(estoque, quantidade, argv[3]);
    }

    // 3. Listar dados do produto com menor quantidade em estoque
    if (strcmp(argv[2], "3") == 0) {
        menor_quantidade_geral(estoque, quantidade);
    }

    // 4. Listar produtos por estado
    if (strcmp(argv[2], "4") == 0) {
        produtos_por_estado(estoque, quantidade, argv[3]);
    }
    
    // 5. Encontrar produto com menor quantidade em estoque do estado
    if (strcmp(argv[2], "5") == 0) {
        menor_quantidade_estado(estoque, quantidade, argv[3]);
    }

    // 6. Calcular a quantidade total de itens no estoque
    if (strcmp(argv[2], "6") == 0) {
        quantidade_total(estoque, quantidade);
    }

    return 0;
}
