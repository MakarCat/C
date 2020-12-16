#include <stdio.h>

int main() 
{
    int key; 

    printf("Во что сегодня поиграем?\n");
    printf("1. Red Dead Redemption 2\n");
    printf("2. Монополия\n");
    printf("3. Поле чудес\n");
    printf("4. GTA San Andreas\n");
    printf("5. Half Life 2\n");
    scanf("%d", &key);
    switch(key) {
        case 1:
            printf("YOU DIED\n");
            break;
        case 2:
            printf("Чур я банкир!\n");
            break;
        case 3:
            printf("Вы выйграли миллион!\n");
            break;
        case 4:
            printf("Следуй за поездом CJ!\n");
            break;
        case 5:
            printf("Проснитесь и пойте мистер фримен, проснитесь и пойте...\nНет я не хочу сказать что вы спите на работе.\nНикто не заслуживает отдыха больше вашего и все усилия мира пропали бы даром пока м... скажем просто что ваш час снова пробил.\nНужный человек не в том месте может перевернуть мир.\nТак проснитесь же мистер Фримен, вас снова ждут великие дела.\n");
            break;
        default:
            printf("ПЕРЕЗАПУСТИ ПРОГРАММУ!\n");
    }
}