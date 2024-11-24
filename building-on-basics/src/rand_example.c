#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i;
    printf("RAND_MAX es %u\n", RAND_MAX);
    srand(time(0));
    printf("valores aleatorios de 0 a RAND_MAX\n");
    for(i = 0; i < 8; i++)
        printf("%d\n", rand());
    printf("valores aleatorios de 1 a 20\n");
    for(i = 0; i < 8; i++)
        printf("%d\n", (rand() % 20) + 1);
}