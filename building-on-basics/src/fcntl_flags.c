#include <stdio.h>
#include <fcntl.h>

void display_flags(char *, unsigned int);
void binary_print(unsigned int);

int main(int argc, char *argv[]) {
    display_flags("O_RDONLY\t\t", O_RDONLY);
    display_flags("O_WRONLY\t\t", O_WRONLY);
    display_flags("O_RDWR\t\t\t", O_RDWR);
    printf("\n");
    display_flags("O_APPEND\t\t", O_APPEND);
    display_flags("O_TRUNC\t\t\t", O_TRUNC);
    display_flags("O_CREAT\t\t\t", O_CREAT);
    printf("\n");
    display_flags("O_WRONLY|O_APPEND|O_CREAT", O_WRONLY | O_APPEND | O_CREAT);
}

void display_flags(char *label, unsigned int value) {
    printf("%s\t: %d\t:", label, value);
    binary_print(value);
    printf("\n");
}

void binary_print(unsigned int value) {
    unsigned int mask = 0xff000000; // Comienza con una máscara para el byte más alto.
    unsigned int shift = 256 * 256 * 256; // Comienza con un desplazamiento para el byte más alto.
    unsigned int byte, byte_iterator, bit_iterator;
    
    for (byte_iterator = 0; byte_iterator < 4; byte_iterator++) {
        byte = (value & mask) >> shift; // Aislar cada byte.
        printf(" ");
        for (bit_iterator = 0; bit_iterator < 8; bit_iterator++) { // Imprimir los bits del byte.
            if (byte & 0x80) // Si el bit más alto en el byte no es 0, imprimir un 1.
                printf("1");
            else
                printf("0"); // De lo contrario, imprimir un 0.
            byte = byte << 1; // Mover todos los bits a la izquierda por 1.
        }
        mask = mask >> 8; // Mover los bits en la máscara a la derecha por 8.
        shift = shift >> 8; // Mover los bits en el desplazamiento a la derecha por 8.
    }
}