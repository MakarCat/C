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

int draw(char arr[3][3]) 
{
    int i, r, j, out;
    for ( i = 0; i < 3; i++ ) {
        r = 0;
        for ( j = 0; j < 3; j++ ) {
            if (arr[i][j] == '_') r++;
            if (arr[j][i] == '_') r++;
        }
    }
    if (r <= 2) out = 1;
    if (r > 2) out = 0;
    return out;
}

int main()
{
    int i, j, r, a, yes, pt_x, pt_y; 
    int x, y; //Выбор игрока
    char myArray[3][3]; //Поле
    int xoro = 0; //Кто сейчас ходит. 0 - это Х, 1 - это О
    int hd = 0; //Сколько ходов прошёл бот
    
    for ( i = 0; i < 3; i++ ) { //Заполняем поле
        for ( j = 0; j < 3; j++ ) { 
            myArray[i][j] = '_'; 
        }
    }

    while (1) {
        if (xoro == 0) { //Если сейчас ходит Х
            yes = 0;
            for ( i = 0; i < 3; i++ ) {
                r = 0;
                a = 0;
                for ( j = 0; j < 3; j++ ) {
                    if (myArray[i][j] == 'x') { r++; }
                    if (myArray[i][j] == 'o') { a++; }
                }
                if (r == 2 && a == 0) {
                    for ( j = 0; j < 3; j++ ) {
                        if (myArray[i][j] == '_') {
                            y = i+1;
                            x = j+1;
                            yes = 1;
                            printf("123_");
                        }
                    }
                }
                if (yes == 1) { break; }

                r = 0;
                a = 0;
                for ( j = 0; j < 3; j++ ) {
                    if (myArray[j][i] == 'x') { r++; }
                    if (myArray[j][i] == 'o') { a++; } 
                }
                if (r == 2 && a == 0) {
                    for ( j = 0; j < 3; j++ ) {
                        if (myArray[j][i] == '_') {
                            y = j+1;
                            x = i+1;
                            yes = 1;
                            printf("123_");
                        }
                    }
                }
                if (yes == 1) { break; }
            }
            if (yes == 0) {
                for ( i = 0; i < 3; i++ ) {
                    r = 0;
                    a = 0;
                    for ( j = 0; j < 3; j++ ) {
                        if (myArray[i][j] == 'x') { r++; }
                        if (myArray[i][j] == 'o') { a++; }
                    }
                    if (a == 2 && r == 0) {
                        for ( j = 0; j < 3; j++ ) {
                            if (myArray[i][j] == '_') {
                                y = i+1;
                                x = j+1;
                                yes = 1;
                                printf("123o_");
                            }
                        }
                    }
                    if (yes == 1) { break; }

                    r = 0;
                    a = 0;
                    for ( j = 0; j < 3; j++ ) {
                        if (myArray[j][i] == 'x') { r++; }
                        if (myArray[j][i] == 'o') { a++; }
                        
                    }
                    if (a == 2 && r == 0) {
                        for ( j = 0; j < 3; j++ ) {
                            if (myArray[j][i] == '_') {
                                y = j+1;
                                x = i+1;
                                yes = 1;
                                printf("123o_");
                            }
                        }
                    }
                    if (yes == 1) { break; }
                }
            }
            if (yes == 0) {
                printf("diagonal001122\n");
                r = 0;
                a = 0;
                if (myArray[0][0] == 'x') {
                    r++;
                } else if (myArray[0][0] == 'o') {
                    a++;
                } else {
                    pt_x = 1;
                    pt_y = 1;
                }
                if (myArray[1][1] == 'x') {
                    r++;
                } else if (myArray[1][1] == 'o') {
                    a++;
                } else {
                    pt_x = 2;
                    pt_y = 2;
                }
                if (myArray[2][2] == 'x') {
                    r++;
                } else if (myArray[2][2] == 'o') {
                    a++;
                } else {
                    pt_x = 3;
                    pt_y = 3;
                }
                if (r == 2 && a == 0) {
                    x = pt_x;
                    y = pt_y;
                    yes = 1;
                } else if (r == 0 && a == 2) {
                    x = pt_x;
                    y = pt_y;
                    yes = 1;
                }
            }
            if (yes == 0) {
                printf("diagonal\n");
                r = 0;
                a = 0;
                if (myArray[0][2] == 'x') {
                    r++;
                } else if (myArray[0][2] == 'o') {
                    a++;
                } else {
                    pt_x = 3;
                    pt_y = 1;
                }
                if (myArray[1][1] == 'x') {
                    r++;
                } else if (myArray[1][1] == 'o') {
                    a++;
                } else {
                    pt_x = 2;
                    pt_y = 2;
                }
                if (myArray[2][0] == 'x') {
                    r++;
                } else if (myArray[2][0] == 'o') {
                    a++;
                } else {
                    pt_x = 1;
                    pt_y = 3;
                }
                if (r == 2 && a == 0) {
                    x = pt_x;
                    y = pt_y;
                    yes = 1;
                } else if (r == 0 && a == 2) {
                    x = pt_x;
                    y = pt_y;
                    yes = 1;
                }
            }

            if (yes == 0) {
                printf("сюжет\n");
                if(hd == 0) {
                    y = 3;
                    x = 3;
                    hd++;
                } else if (hd == 1 && myArray[0][2] == '_') {
                    printf("1 1\n");
                    y = 1;
                    x = 3;
                    hd++;
                } else if (hd == 1 && myArray[0][2] != '_') {
                    printf("1 2\n");
                    y = 3;
                    x = 1;
                    hd++;
                } else if (hd == 2 && myArray[0][0] == '_') {
                    printf("2 1\n");
                    y = 1;
                    x = 1;
                    hd++;
                } else if (hd == 2 && myArray[1][1] == '_') {
                    printf("2 2\n");
                    y = 2;
                    x = 2;
                    hd++;
                }
            }
            
            printf("%d\n", yes);
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
        r = 0;
        for ( i=0; i < 3; i++) {
            for ( j=0; j < 3; j++) {
                if (myArray[i][j] == '_') r++;
            }
        }
        if (r == 0) {
            if (xoro == 1) {
                for ( i = 0; i < 3; i++ ) {
                    printf("| %c | %c | %c | \n", myArray[i][0], myArray[i][1], myArray[i][2]); //Вывод
                }
            }
            printf("Ничья!");
            exit(1);
        }
        
    }
    
}