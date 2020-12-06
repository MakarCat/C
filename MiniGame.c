#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char field[10][20]; //Поле
    int pl_x, pl_y, Epl_x, Epl_y; //Текущяя и предыдущая позиция игрока
    char key; //Ввод
    int i, j, r, w;
    srand(time(NULL));

    for ( i = 0; i < 10; i++ ) { //Заполняем поле
        for ( j = 0; j < 20; j++ )
        field[i][j] = ' ';
    }

    for ( i = 1; i < 9; i+=2 ) { //Заполняем поле пепятствиями
        r = rand()%15;
        for ( j = 0; j < r; j++ )
        field[i][j] = '#';
        for ( w = j+4; w < 20; w++ )
        field[i][w] = '#';
    }

    for ( i = 0; i < 10; i++ ) { //Вывод
        printf("| ");
        for ( j = 0; j < 20; j++ )
        printf("%c", field[i][j]);
        printf(" |\n");
    }

    while (1)
    {
        scanf("%c", &key);
        
        if(key == 'r') { pl_x++; }
        else if(key == 'l') {pl_x--;}
        if(key == 'u') { pl_y--; }
        else if(key == 'd') {pl_y++;}
        if(key == 'e') { exit(1); }

        while (field[pl_y][pl_x] != ' ') { //Если там препятствие
            scanf("%c", &key);
            pl_x = Epl_x;
            pl_y = Epl_y;
            if(key == 'r') { pl_x++; }
            else if(key == 'l') {pl_x--;}
            if(key == 'u') { pl_y--; }
            else if(key == 'd') {pl_y++;}
            if(key == 'e') { exit(1); }
        }

        field[Epl_y][Epl_x] = ' ';
        field[pl_y][pl_x] = '!';

        for ( i = 0; i < 10; i++ ) { //Вывод
            printf("| ");
            for ( j = 0; j < 20; j++ )
            printf("%c", field[i][j]);
            printf(" |\n");
        }
        Epl_x = pl_x;
        Epl_y = pl_y;
        if (pl_y == 9) { //Победа
            printf("Ты победил!\n");
            exit(1);
        }
    }
}