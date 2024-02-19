#include <stdio.h>
#include <locale.h>

int bissexto(int ano) {
    if (ano % 400 == 0 || (ano % 100 != 0 && ano % 4 == 0)) {
        return 1;
    } else {
        return 0;
    }
}

int dias_entre_datas(int dia, int mes, int ano) {
    int dias = 0;
    int ano_atual = 1900;
    int mes_atual = 1;
    int dia_atual = 1;

    while (ano_atual < ano || mes_atual < mes || dia_atual < dia) {
        dias++;

        if (mes_atual == 2) {
            if (bissexto(ano_atual)) {
                dia_atual = (dia_atual == 29) ? 1 : dia_atual + 1;
            } else {
                dia_atual = (dia_atual == 28) ? 1 : dia_atual + 1;
            }
        } else if (mes_atual == 4 || mes_atual == 6 || mes_atual == 9 || mes_atual == 11) {
            dia_atual = (dia_atual == 30) ? 1 : dia_atual + 1;
        } else {
            dia_atual = (dia_atual == 31) ? 1 : dia_atual + 1;
        }

        if (dia_atual == 1) {
            mes_atual++;
        }

        if (mes_atual > 12) {
            mes_atual = 1;
            ano_atual++;
        }
    }

    return dias;
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    int dia, mes, ano;

    printf("Insira o dia (1-31): ");
    scanf("%d", &dia);

    printf("Insira o mês (1-12): ");
    scanf("%d", &mes);

    printf("Insira o ano (1900-9999): ");
    scanf("%d", &ano);

    int dias = dias_entre_datas(dia, mes, ano);

    printf("Dias entre %d/%d/%d e 01/01/1900: %d\n", dia, mes, ano, dias);

    return 0;
}


