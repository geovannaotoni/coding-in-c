#include <stdio.h>

int main() {
    int tamanhoAeds, tamanhoCalculo, i, j;
    
    // printf("Digite a quantidade de alunos em AEDS 1: ");
    scanf("%d", &tamanhoAeds);
    int aeds[tamanhoAeds];
    
    for(i = 1; i <= tamanhoAeds; i++) {
        // printf("Informe a matrícula do aluno %d na disciplina: ", i);
        scanf("%d", &aeds[i]);
    }
    
    // printf("Digite a quantidade de alunos em Calculo 1: ");
    scanf("%d", &tamanhoCalculo);
    int calculo[tamanhoCalculo];

    for(j = 1; j <= tamanhoCalculo; j++) {
        // printf("Informe a matrícula do aluno %d na disciplina: ", j);
        scanf("%d", &calculo[j]);
    }
    
    for(i = 1; i <= tamanhoAeds; i++) {
        for(j = 1; j <= tamanhoCalculo; j++) {
            if(aeds[i] == calculo[j]) {
                printf("%d\n", aeds[i]);
            }
        }
    }

    return 0;
}
