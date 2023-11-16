#include <stdio.h>
#include <stdlib.h>

enum meses { janeiro = 1, fevereiro, marco, abril, maio, junho, julho, agosto, setembro, outubro, novembro, dezembro };

struct Data {
    int dia;
    enum meses mes;
    int ano;
};

struct Evento {
    char nome[100];
    char local[100];
    struct Data d;
};

void cadastrar_eventos(struct Evento *agenda, int n) {
    for(int i = 0; i < n; i++) {
        scanf("%s %s %d %u %d", agenda[i].nome, agenda[i].local, &agenda[i].d.dia, &agenda[i].d.mes, &agenda[i].d.ano);
    }
};

void imprimir_eventos(struct Evento agenda[], struct Data d, int n) {
    int encontrou = 0;
    for(int i = 0; i < n; i++) {
        if(d.dia == agenda[i].d.dia && d.mes == agenda[i].d.mes && d.ano == agenda[i].d.ano) {
            printf("%s %s\n", agenda[i].nome, agenda[i].local);
            encontrou++;
        }
    }
    
    if (!encontrou) {
        printf("Nenhum evento encontrado!");
    }
};

int main () {
    int n;
    scanf("%d", &n);
    
    struct Evento agenda[n];
    cadastrar_eventos(agenda, n);
    
    struct Data data;
    scanf("%d %u %d", &data.dia, &data.mes, &data.ano);
    imprimir_eventos(agenda, data, n);
    
    return 0;
}
