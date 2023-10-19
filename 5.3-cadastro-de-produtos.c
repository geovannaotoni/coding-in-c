#include <stdio.h>
#include <string.h>

int main() {
    struct produto {
        char nome[50];
        char marca[50];
        float preco;
    };
    
    struct produto produtos[8];
    
    char marcas[8][50];
    int numeroMarcas = 0;
    int totalProdutosPorMarca[8] = {0};
    float somaPrecosPorMarca[8] = {0};
    float somaPrecosTotal = 0;
    
    for(int i = 0; i < 8; i++) {
        scanf("%s %s %f", produtos[i].nome, produtos[i].marca, &produtos[i].preco);
        somaPrecosTotal += produtos[i].preco;
        
        int marcaEncontrada = 0;
        for (int j = 0; j < numeroMarcas; j++) {
            if (strcmp(produtos[i].marca, marcas[j]) == 0) { // atualiza os valores de acordo com a marca 
                marcaEncontrada = 1;
                totalProdutosPorMarca[j]++;
                somaPrecosPorMarca[j] += produtos[i].preco;
                break;
            }
        }
        
        if(!marcaEncontrada) {
            strcpy(marcas[numeroMarcas], produtos[i].marca); // adiciona a marca na lista de marcas
            totalProdutosPorMarca[numeroMarcas]++;
            somaPrecosPorMarca[numeroMarcas] += produtos[i].preco;
            numeroMarcas++;
        }
    }
    
    float mediaPrecosTotal = somaPrecosTotal / 8.0;
    
    for(int i = 0; i < numeroMarcas; i++) {
        printf("%s %d\n", marcas[i], totalProdutosPorMarca[i]);
    }
    
    printf("media total %.2f\n", mediaPrecosTotal);
    
    for(int i = 0; i < numeroMarcas; i++) {
        float mediaPrecosPorMarca = somaPrecosPorMarca[i] / totalProdutosPorMarca[i];
        printf("media %s %.2f\n", marcas[i], mediaPrecosPorMarca);
    }
    
    return 0;
}
