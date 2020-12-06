#include <stdio.h>
#include <stdlib.h>

void check(char xo, char arr[3][3]) 
{
    int i, r, j;
    for ( i = 0; i < 3; i++ ) {
        r = 0;
        for ( j = 0; j < 3; j++ ) {
            if (arr[i][j] == xo) { r++; }
            if (r == 3) {
                printf("Победили %c! \n", xo);
                exit(1);
            }
        }
    }
    for ( i = 0; i < 3; i++ ) {
        r = 0;
        for ( j = 0; j < 3; j++ ) {
            if (arr[j][i] == xo) { r++; }
            if (r == 3) {
                printf("Победили %c! \n", xo);
                exit(1);
            }
        }
    }
    if (arr[0][0] == xo && arr[1][1] == xo && arr[2][2] == xo) { printf("Победили %c! \n", xo); exit(1); }
    if (arr[0][2] == xo && arr[1][1] == xo && arr[2][0] == xo) { printf("Победили %c! \n", xo); exit(1); }
}

int main()
{
    int i, j, r, a, yes; 
    int x, y; //Выбор игрока
    char myArray[3][3]; //Поле
    int xoro = 0; //Кто сейчас ходит
    int hd = 0; //Сколько ходов прошёл бот
    
    for ( i = 0; i < 3; i++ ) { //Заполняем поле
        for ( j = 0; j < 3; j++ )
        myArray[i][j] = '_';
    }

    while (1) {
        if (xoro == 0) { //Ставим крестик или нолик
            for ( i = 0; i < 3; i++ ) {
                r = 0;
                a = 0;
                for ( j = 0; j < 3; j++ ) {
                    if (myArray[i][j] == 'x') { r++; }
                    if (myArray[i][j] == 'o') { a++; }
                    if (r == 2 && a == 0) {
                        for ( j = 0; j < 3; j++ ) {
                            if (myArray[i][j] == '_') {
                                y = i+1;
                                x = j+1;
                                yes = 1;
                            }
                        }
                        if (yes == 1) {break;}
                    }
                }
                if (yes == 1) {break;}
                r = 0;
                a = 0;
                for ( j = 0; j < 3; j++ ) {
                    if (myArray[j][i] == 'x') { r++; }
                    if (myArray[j][i] == 'o') { a++; }
                    if (r == 2 && a == 0) {
                        for ( j = 0; j < 3; j++ ) {
                            if (myArray[j][i] == '_') {
                                y = j+1;
                                x = i+1;
                                yes = 1;
                            }
                        }
                        if (yes == 1) {break;}
                    }
                }
                if (yes == 1) {break;}
            }
            if (yes == 0) {
                for ( i = 0; i < 3; i++ ) {
                    r = 0;
                    a = 0;
                    for ( j = 0; j < 3; j++ ) {
                        if (myArray[i][j] == 'x') { r++; }
                        if (myArray[i][j] == 'o') { a++; }
                        if (a == 2 && r == 0) {
                            for ( j = 0; j < 3; j++ ) {
                                if (myArray[i][j] == '_') {
                                    y = i+1;
                                    x = j+1;
                                    yes = 1;
                                }
                            }
                            if (yes == 1) {break;}
                        }
                    }
                    if (yes == 1) {break;}

                    r = 0;
                    a = 0;
                    for ( j = 0; j < 3; j++ ) {
                        if (myArray[j][i] == 'x') { r++; }
                        if (myArray[j][i] == 'o') { a++; }
                        if (a == 2 && r == 0) {
                            for ( j = 0; j < 3; j++ ) {
                                if (myArray[j][i] == '_') {
                                    y = j+1;
                                    x = i+1;
                                    yes = 1;
                                }
                            }
                            if (yes == 1) {break;}
                        }
                    }
                    if (yes == 1) {break;}
                }
            }

            if (yes == 0) {
                if(hd == 0) {
                    y = 3;
                    x = 3;
                    hd++;
                } else if (hd == 1 && myArray[0][2] == '_') {
                    y = 1;
                    x = 3;
                    hd++;
                } else if (hd == 1 && myArray[0][2] != '_') {
                    y = 3;
                    x = 1;
                    hd++;
                } else if (hd == 2 && myArray[0][0] == '_') {
                    y = 1;
                    x = 1;
                    hd++;
                }
            }
            
            myArray[y-1][x-1] = 'x';
            xoro = 1;
        } else {
            scanf("%d %d", &y, &x);
            while (myArray[y-1][x-1] != '_') { //Если там уже есть значение
                printf("Там уже есть значение! \n");
                scanf("%d %d", &y, &x);
            }
            myArray[y-1][x-1] = 'o';
            xoro = 0; 
        }
        if (xoro == 1) {
            for ( i = 0; i < 3; i++ ) {
            printf("| %c | %c | %c | \n", myArray[i][0], myArray[i][1], myArray[i][2]); //Вывод
            }
        }

        check('x', myArray); //Этап проверки крестиков
        check('o', myArray); //Этап проверки ноликов
        
    }
    
}