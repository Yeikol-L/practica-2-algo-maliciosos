#include <stdio.h>

int main() {
    int i, bit_a, bit_b;
    printf("bitwise OR operator |\n");
    for(i = 0; i < 4; i++) {
        bit_a = (i & 2); // Obtener el segundo bit.
        bit_b = (i & 1); // Obtener el primer bit.
        printf("%d | %d = %d\n", bit_a, bit_b, bit_a | bit_b);
    }
    
    printf("\nbitwise AND operator &\n");
    for(i = 0; i < 4; i++) {
        bit_a = (i & 2); // Obtener el segundo bit.
        bit_b = (i & 1); // Obtener el primer bit.
        printf("%d & %d = %d\n", bit_a, bit_b, bit_a & bit_b);
    }
    
    return 0;
}