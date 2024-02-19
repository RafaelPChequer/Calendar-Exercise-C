#include <stdio.h>
#include <locale.h>

void dias_para_data(int dias, int *ano, int *mes, int *dia) {
    int dias_ate_ultimo_aniversario = dias;
    *ano = 1900;

    while (dias_ate_ultimo_aniversario >= 365) {
        int ano_bissexto = (*ano % 4 == 0 && (*ano % 100 != 0 || *ano % 400 == 0));
        dias_ate_ultimo_aniversario -= ano_bissexto ? 366 : 365;
        (*ano)++;
    }

    for (int i = 1; i <= 12; i++) {
        int dias_no_mes;
        switch (i) {
            case 2: {
                int ano_bissexto = (*ano % 4 == 0 && (*ano % 100 != 0 || *ano % 400 == 0));
                dias_no_mes = ano_bissexto ? 29 : 28;
                break;
            }
            case 4:
            case 6:
            case 9:
            case 11:
                dias_no_mes = 30;
                break;
            default:
                dias_no_mes = 31;
                break;
        }

        if (dias_ate_ultimo_aniversario >= dias_no_mes) {
            dias_ate_ultimo_aniversario -= dias_no_mes;
            *mes = i;
        } else {
            break;
        }
    }

    *dia = dias_ate_ultimo_aniversario + 1;
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    int dias, ano = 0, mes = 0, dia = 0;

    printf("Digite o número de dias: ");
    scanf("%d", &dias);

    dias_para_data(dias, &ano, &mes, &dia);
    printf("Dias: %d -> Data: %02d/%02d/%04d\n", dias, dia, mes, ano);

    return 0;
}
