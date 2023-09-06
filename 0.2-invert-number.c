// 2) Faça um programa para ler um número inteiro positivo de 3 dígitos. Imprima na tela o número invertido. Ex? 123 -> 321

int main() {
    int number, c, d, u;
    printf("Digite um número inteiro de 3 dígitos: ");
    scanf("%d", &number);

    c = number / 100;
    d = (number % 100) / 10;
    u = (number % 100) % 10;

    printf("O número invertido é %d%d%d", u, d, c);
}
