#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    float r = 0;
    srand(time(NULL));
    for (int i=0; i<10000000; i++) {
        if (rand()%10000 % 2 == 0) {
            r++;
        }
    }
    printf("%f\n", r / 10000000 * 100);
}