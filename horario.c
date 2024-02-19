#include <stdio.h>
#include <locale.h>

void converte_segundos(int segundos, int *hora, int *minuto, int *segundo) {
    *hora = segundos / 3600;
    *minuto = (segundos % 3600) / 60;
    *segundo= segundos % 60;
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    int segundos, hora, minuto, segundo;

    printf("Digite a quantidade de segundos: ");
    scanf("%d", &segundos);

    converte_segundos(segundos, &hora, &minuto, &segundo);

    printf("O horário é: %dh %dmin %dseg.", hora, minuto, segundo);

    return 0;
}