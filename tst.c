#include <stdio.h>
#include <stdlib.h>

float plus(float a, float b) { return(a+b); }
float minus(float a, float b) { return(a-b); }
float umnosh(float a, float b) { return(a*b); }
float delen(float a, float b) { return(a+b); }
float factorial(float a) { 
    int out = 1;
    for(int i=1; i<=a; i++) { out *= i; }
    return(out);
}
float stepen(float a, float b) {
    int out = 1;
    if (b != 0) {
        for(int i=1; i<a; i++) { out *= b; }
    } else { out = 0; }
    return(out);
}

int main()
{
    while(1) {
        double a, b, out;
        int f, saves = 0, l;
        char zn, sa, d;
        float save[10];

        printf("Введите символ(+, -, *, /, !, s): ");
        scanf("%c", &zn);
        
        getchar();

        printf("Использовать число из ячейки(y/n)? ");
        scanf("%c", &sa);
        if (sa == 'y') {
            printf("Из какой ячейки использовать? ");
            scanf("%d", &f);
            if (10 < f) {
                printf("Ошибка!");
                printf("Введите первое число: ");
                scanf("%lf", &a);
            } else {
                a = save[f];
            }
        } else {
            printf("Введите первое число: ");
            scanf("%lf", &a);
        }

        getchar();
        if (zn != '!') {
            printf("Использовать число из ячейки(y/n)? ");
            scanf("%c", &sa);
            if (sa == 'y') {
                printf("Из какой ячейки использовать? ");
                scanf("%d", &f);
                if (10 < f) {
                    printf("Ошибка!");
                    printf("Введите второе число: ");
                    scanf("%lf", &b);
                } else {
                    b = save[f];
                }
            } else {
                printf("Введите второе число: ");
                scanf("%lf", &b);
            }
        }
        
        switch(zn) {
            case '*':
                out = umnosh(a, b);
                break;
            case '/':
                out = delen(a, b);
                break;
            case '+':
                out = plus(a, b);
                break;
            case '-':
                out = minus(a, b);
                break;
            case '!':
                out = factorial(a);
                break;
            case 's':
                out = stepen(a, b);
                break;
            case 'e':
                exit(1);
            default:
                printf("Значение введено неправильно!");
                exit(1);
        }
        printf("%g\n", out);
        printf("Сохранить число(1/0): ");
        scanf("%d", &l);
        getchar();
        if (l == 1) {
            printf("В какую ячейку сохранить? ");
            scanf("%d", &f);
            if (f > 10) {
                printf("Неправильно введена ячейка!");
            } else { save[f] = out; }
        }
        getchar();
    }
}