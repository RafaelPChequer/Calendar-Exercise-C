#include <stdio.h>
#include <locale.h>

int primo(int num) {
    int sum = 0;

    if(num < 1) {
        return 2;
    } else if (num == 1) {
        return 0;
    } else {
        for(int i = num-1; i > 1; i--) {
            if(num % i == 0)
              sum++;
        }
    }
    if(sum == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main(void) {
setlocale(LC_ALL, "Portuguese");

int val, ver;
printf("Informe um n�mero inteiro positivo: ");
scanf("%d",&val);

ver = primo(val);

if(ver == 0) {
    printf("N�o � primo!");
} else if(ver == 1) {
    printf("� primo!");
} else {
    printf("Valor inv�lido!");
}

return 0;
}