#include <stdio.h>
#include <stdlib.h>

int main()
{
    int key; //В этой переменной хранится последнее число введённое пользователем
    int gameStart = 0; //Статус игры
    int gloy = 0; //Количество угля
    int errors = 0; //Ошибки при настройке тепловоза
    int claim = 0; //Правильные ответы при настройке тепловоза
    int resolved = 0; //Решил человек пример или нет
    int ThirstSlog = 0; //Первое слагаемое
    int SecondSlog = 0; //Второе слагаемое
    int Out = 0; //Сумма

    printf("Для того что бы начать игру - введите 1.\nЧто бы выйти - введите 2.\n");

    while (1) {
        if (resolved != 1){
            scanf("%d", &key);
        }
        if (gameStart == 0) {
            if (key == 1) {
                printf("Начинаем игру...\n");
                printf("Для того что бы положить в тепловоз 1 мешок угля - введите 4.\nЧто бы запустить тепловоз - введите 5 (для запуска нужно 10 мешков угля).\n");
                gameStart = 1;
            } else if (key == 3) {
                printf("Цель игры - запустить тепловоз. Для этого нужно положить в тепловоз 10 мешков угля.\n");
            } else {
                printf("Для справки - введите 3.\n");
            }
        } else if (gameStart == 1) {
            if (key == 5){
                if (gloy >= 10 & gloy < 20) {
                    printf("Вы положили достаточное количество мешков угля!\n");
                    printf("Для того, что бы запустить тепловоз надо правильно его настроить! Решайте примеры и вводите ответ.\n");
                    resolved = 1;
                    gameStart = 2;
                } else if (gloy >= 20) {
                   printf("Вы положили слишком много мешков угля! Тепловоз взорвался!\n");
                   break;
                } else {
                    printf("Недостаточно угля для запуска тепловоза! Для запуска ещё нужно положить %d мешков угля.\n", 10-gloy);
                }
            } else if (key == 4) {
                gloy += 1;
                printf("Вы положили ещё 1 мешок угля в тепловоз (всего сейчас в тепловозе - %d мешков угля)!\n", gloy);
            }
        } else {
            if (resolved == 1) {
                ThirstSlog = rand()%50;
                SecondSlog = rand()%50;
                Out = ThirstSlog + SecondSlog;
                printf("Вот твой пример - %d + %d.\n", ThirstSlog, SecondSlog);
                resolved = 0;
            } else if (resolved == 0){
                if (key == Out){
                    claim += 1;
                    printf("Всё правильно! Осталось решить %d примеров.\n", 5-claim);
                    resolved = 1;
                } else {
                    errors += 1;
                    printf("Ты ошибся! Ещё %d ошибок и тепловоз взорвётся!\n", 3-errors);
                    resolved = 1;
                }
            }
            if (claim == 5) {
                printf("Вы запустили тепловоз! Вы выйграли!\n");
                break;
            } else if (errors == 3){
                printf("Тепловоз взорвался! Вы проиграли!\n");
                break;
            }
        }

        if (key == 2) {
            printf("Вы вышли из игры!\n");
            break;
        }
    }
}