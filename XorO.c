#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, r; 
    int x, y; //Выбор игрока
    char myArray[3][3]; //Поле
    int xoro = 0; //Кто сейчас ходит
    
    for ( i = 0; i < 3; i++ ) { //Заполняем поле
        for ( j = 0; j < 3; j++ )
        myArray[i][j] = '_';
    }

    for ( i = 0; i < 3; i++ ) {
        printf("| %c | %c | %c | \n", myArray[i][0], myArray[i][1], myArray[i][2]); //Вывод
    }

    while (1) {
        scanf("%d %d", &y, &x);
        while (myArray[y-1][x-1] != '_') { //Если там уже есть значение
            printf("Там уже есть значение! \n");
            scanf("%d %d", &y, &x);
        }
        if (xoro == 0) { //Ставим крестик или нолик
            myArray[y-1][x-1] = 'x';
            xoro = 1;
        } else {
            myArray[y-1][x-1] = 'o';
            xoro = 0; 
        }
        for ( i = 0; i < 3; i++ ) {
        printf("| %c | %c | %c | \n", myArray[i][0], myArray[i][1], myArray[i][2]); //Вывод
        }

        //Этап проверки крестиков

        for ( i = 0; i < 3; i++ ) {
            r = 0;
            for ( j = 0; j < 3; j++ ) {
                if (myArray[i][j] == 'x') { r++; }
                if (r == 3) {
                    printf("Крестики победили! \n");
                    exit(1);
                }
            }
        }
        for ( i = 0; i < 3; i++ ) {
            r = 0;
            for ( j = 0; j < 3; j++ ) {
                if (myArray[j][i] == 'x') { r++; }
                if (r == 3) {
                    printf("Крестики победили! \n");
                    exit(1);
                }
            }
        }
        if (myArray[0][0] == 'x' && myArray[1][1] == 'x' && myArray[2][2] == 'x') { printf("Крестики победили! \n"); exit(1); }
        if (myArray[0][2] == 'x' && myArray[1][1] == 'x' && myArray[2][0] == 'x') { printf("Крестики победили! \n"); exit(1); }

        //Этап проверки ноликов

        for ( i = 0; i < 3; i++ ) {
            r = 0;
            for ( j = 0; j < 3; j++ ) {
                if (myArray[i][j] == 'o') { r++; }
                if (r == 3) {
                    printf("Нолики победили! \n");
                    exit(1);
                }
            }
        }
        for ( i = 0; i < 3; i++ ) {
            r = 0;
            for ( j = 0; j < 3; j++ ) {
                if (myArray[j][i] == 'o') { r++; }
                if (r == 3) {
                    printf("Нолики победили! \n");
                    exit(1);
                }
            }
        }
        if (myArray[0][0] == 'o' && myArray[1][1] == 'o' && myArray[2][2] == 'o') { printf("Нолики победили! \n"); exit(1); }
        if (myArray[0][2] == 'o' && myArray[1][1] == 'o' && myArray[2][0] == 'o') { printf("Нолики победили! \n"); exit(1); }
    }
    
}