#include <stdio.h>
#include <math.h>

struct iris {
  float comp_sepala;
  float larg_sepala;
  float comp_petala;
  float larg_petala;
  char tipo[50];
};

void classificar(struct iris nao_identificada, struct iris registros_identificados[], int n) {
    float dist_euclidiana = 0;
    float menor_valor = -1;
    struct iris flor;
    
    for(int i = 0; i < n; i++) {
        dist_euclidiana = sqrt(pow(registros_identificados[i].comp_sepala - nao_identificada.comp_sepala, 2) + pow(registros_identificados[i].larg_sepala - nao_identificada.larg_sepala, 2) + pow(registros_identificados[i].comp_petala - nao_identificada.comp_petala, 2) + pow(registros_identificados[i].larg_petala - nao_identificada.larg_petala, 2));
        if (dist_euclidiana < menor_valor || menor_valor == -1) {
            menor_valor = dist_euclidiana;
            flor = registros_identificados[i];
        }
    }
    
    printf("%s", flor.tipo);
};

int main () {
    int n;
    scanf("%d", &n);
    
    struct iris registros_identificados[n];
    for(int i = 0; i < n; i++) {
        scanf("%f %f %f %f %s", &registros_identificados[i].comp_sepala, &registros_identificados[i].larg_sepala, &registros_identificados[i].comp_petala, &registros_identificados[i].larg_petala, registros_identificados[i].tipo);
    }
    
    struct iris nao_identificada;
    scanf("%f %f %f %f", &nao_identificada.comp_sepala, &nao_identificada.larg_sepala, &nao_identificada.comp_petala, &nao_identificada.larg_petala);

    classificar(nao_identificada, registros_identificados, n);
    
    return 0;
}
