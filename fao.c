#include <stdio.h>

int main() 
{
    double g = 1;
    double z = 1;
    int d = 1;
    char f;

    printf("Что надо сделать(f - факториал, s - сумма, o - и то, и другое): ");
    scanf("%c", &f);
    printf("Введите число:");
    scanf("%d", &d);
    switch (f) {
        case 'f':
            for (int i = 1; i <= d; i++) {
                g *= i;
            }
            printf("%g\n", g);
            break;
        case 's':
            for (int i = 0; i <= d; i++) {
                g += i;
            }
            printf("%g\n", g);
            break;
        case 'o':
            for (int i = 1; i <= d; i++) {
                g *= i;
            }
            for (int i = 0; i <= d; i++) {
                z += i;
            }
            printf("%g\n", g);
            printf("%g\n", z);
            break;
        default:
            printf("Вы ввели неправильно");
    }
}