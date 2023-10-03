#include <stdio.h>
int main() {
  int num1, num2;
  printf("Digite o primeiro número: "); // considerando que o primeiro numero digitado é maior que o segundo
  scanf("%d", &num1);
  
  printf("Digite o segundo número: ");
  scanf("%d", &num2);

  int mmc = num1;
  int aux;
  for(int i = 2; i <= num1; i++) {
    aux = num2 * i;
    if ((aux % num1) == 0) {
      mmc = aux;
      break;
    }
  }
  
  printf("%d", mmc);
  return 0;
}

/* 
outra solução:
#include <stdio.h>
int main() {
  int num1, num2;
  printf("Digite o primeiro número: "); // considerando que o primeiro numero digitado é maior que o segundo
  scanf("%d", &num1);
  
  printf("Digite o segundo número: ");
  scanf("%d", &num2);

  int resto, a = num1, b = num2;
  do {
    resto = a % b;
    a = b;
    b = resto;
  } while (resto != 0);

  int mmc = num1 * num2 / a;
  
  printf("%d", mmc);
  return 0;
}
*/
