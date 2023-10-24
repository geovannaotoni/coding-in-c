#include <stdio.h>

int bissexto(int ano) {
    int bissexto = 0;
    if((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0) {
        bissexto = 1;
    }
    return bissexto;
}

int contagem(int dia, int mes, int ano) {
    int diasAno[13] = {0, 31,28,31,30,31,30,31,31,30,31,30,31};
    int diasBissexto[13] = {0, 31,29,31,30,31,30,31,31,30,31,30,31}; // 2020 é bissexto
    int dias = 18; // contagem dos dias, inicia-se com 18, pois a data da contagem é 17/09/2020
    
    
    if (ano == 2020) {
        // contagem do mês fornecido na função até setembro
        for(int i = mes + 1; i < 9; i++){
            dias += diasBissexto[i];
        }
        
        // se o mês já for setembro, só realiza a contagem dos dias
        if(mes == 9) {
            dias += - dia;
        }
        
        // se o mês for anterior a setembro, conta-se a diferença dos dias
        if(mes < 9) {
            dias += (diasBissexto[mes] - dia);
        }
    }

    if (ano < 2020) {
        // contagem dos anos
        for(int i = ano + 1; i < 2020; i++) {
            dias += bissexto(i) ? 366 : 365;
        }
        
        // contagem dos meses a partir do mês fornecido na função até dezembro
        for(int i = mes + 1; i < 13; i++) {
            dias += bissexto(ano) ? diasBissexto[i] : diasAno[i];
        }
        
        // contagem dos dias do ano de 2020, que é bissexto
        for (int i=0; i < 9; i++) {
			dias += diasBissexto[i];
        }
        
        dias += ((bissexto(ano) ? diasBissexto[mes] : diasAno[mes])- dia);
    }
    
    return dias;
}

int main() {
    int dia, mes, ano;

    while (scanf("%d %d %d", &dia, &mes, &ano) != EOF)
		printf("%d\n", contagem(dia, mes, ano));
	return 0;
}
