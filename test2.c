#include <stdio.h>

int main()
{
    int i; // максимальное число
    int c; // текущее число
    int l; // текущая длина строки
    int m; // максимальная длина строки

    scanf("%d", &i);

    for (c = 0, l = 0, m = 1; c < i; c++) {
        if( c%10 == 5 || c%10 == 8 ) continue;

        printf("%d ", c);
        l++;
        if( l >= m ) {
            printf("\n");
            l = 0;
            m++;
        }
    }
    printf("\n");
}