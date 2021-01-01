#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    int key = 0;
    int key2 = 0;
    double o = 0;
    srand(time(NULL));

    key = 3+rand()%1000000;

    for (int i=1; i<=key; i++) {
        key2 = 1+rand()%1000;
        o += key2;
    }
    printf("%g\n", o);
}