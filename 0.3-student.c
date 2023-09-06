// 3) Para se matricular no colégio, um aluno tem que satisfazer as seguintes condições:
// a) Ter entre 12 (inclusivo) e 18 (exclusivo) anos
// b) Ter nota superior a 90 no ensino fundamental
// Como fazer um programa que determina se um aluno pode ou não se matricular?
#include <stdio.h>

int main() {
    int age, rate;
    printf("Digite sua idade: ");
    scanf("%d", &age);

    printf("Digite sua nota no ensino fundamental: ");
    scanf("%d", &rate);

    if (age >= 12 && age < 18 && rate > 90) {
        printf("O aluno pode se matricular.");
    } else {
        printf("O aluno não pode se matricular.");
    };
}
