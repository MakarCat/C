#include <stdio.h>
#include <math.h>

int main() 
{
    int i, g, c=0;
    scanf("%d", &i);
    i /= pow(i, 0.5);
    for (int d = 0; d < i; d++) {
        for (int a = 1; a <= i; a++) {
            if (c%10 != 5 && c%10 != 8) {
                printf("%d ", c);
            } 
            c++;
        }
        printf("\n");
    }
}