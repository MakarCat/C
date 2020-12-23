#include <stdio.h>
#include <unistd.h>

int main() 
{
    int b, i, s;
    scanf("%d", &b);
    for (i=0; i<=b; i++) {
        printf("%d\n", i);
        sleep(1);
    }
}