#include <stdio.h>
#include <locale.h>

int segundos(int h, int m, int s) {
    int segundos;

    h *= 3600;
    m *= 60;

    segundos = h + m + s;

    return segundos;
}

int main(void) {
setlocale(LC_ALL, "Portuguese");

int hora, minuto, segundo, total;
scanf("%d %d %d",&hora, &minuto, &segundo);

printf("Segundos: %d", segundos(hora, minuto, segundo));

return 0;
}