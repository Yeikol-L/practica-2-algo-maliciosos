#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *errorchecked_malloc(unsigned int size); // Prototipo de función para errorchecked_malloc()

int main(int argc, char *argv[]) {
    char *char_ptr; // Un puntero char
    int *int_ptr;   // Un puntero entero
    int mem_size;

    if (argc < 2) // Si no hay argumentos en la línea de comandos,
        mem_size = 50; // usar 50 como valor predeterminado.
    else
        mem_size = atoi(argv[1]);

    printf("\t[+] asignando %d bytes de memoria en el heap para char_ptr\n", mem_size);
    char_ptr = (char *)errorchecked_malloc(mem_size); // Asignando memoria en el heap
    strcpy(char_ptr, "Esta memoria está ubicada en el heap.");
    printf("char_ptr (%p) --> '%s'\n", char_ptr, char_ptr);

    printf("\t[+] asignando 12 bytes de memoria en el heap para int_ptr\n");
    int_ptr = (int *)errorchecked_malloc(12); // Asignando memoria en el heap nuevamente
    *int_ptr = 31337; // Poner el valor de 31337 donde apunta int_ptr.
    printf("int_ptr (%p) --> %d\n", int_ptr, *int_ptr);

    printf("\t[-] liberando la memoria del heap de char_ptr...\n");
    free(char_ptr); // Liberando memoria del heap

    printf("\t[+] asignando otros 15 bytes para char_ptr\n");
    char_ptr = (char *)errorchecked_malloc(15); // Asignando más memoria en el heap
    strcpy(char_ptr, "nueva memoria");
    printf("char_ptr (%p) --> '%s'\n", char_ptr, char_ptr);

    printf("\t[-] liberando la memoria del heap de int_ptr...\n");
    free(int_ptr); // Liberando memoria del heap

    printf("\t[-] liberando la memoria del heap de char_ptr...\n");
    free(char_ptr); // Liberando el otro bloque de memoria del heap
}

void *errorchecked_malloc(unsigned int size) { // Una función malloc() con verificación de errores
    void *ptr;
    ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Error: no se pudo asignar memoria en el heap.\n");
        exit(-1);
    }
    return ptr;    
}