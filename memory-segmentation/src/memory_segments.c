#include <stdio.h>
#include <stdlib.h>

int global_var;
int global_initialized_var = 5;

void function() { // Esta es solo una función de demostración.
    int stack_var; // Nótese que esta variable tiene el mismo nombre que la de main().
    printf("La stack_var de la función está en la dirección %p\n", (void*)&stack_var);
}

int main() {
    int stack_var; // Mismo nombre que la variable en function()
    static int static_initialized_var = 5;
    static int static_var;
    int *heap_var_ptr;

    heap_var_ptr = (int *)malloc(4);
    // Estas variables están en el segmento de datos.
    printf("global_initialized_var está en la dirección %p\n", (void*)&global_initialized_var);
    printf("static_initialized_var está en la dirección %p\n\n", (void*)&static_initialized_var);
    // Estas variables están en el segmento bss.
    printf("static_var está en la dirección %p\n", (void*)&static_var);
    printf("global_var está en la dirección %p\n\n", (void*)&global_var);
    // Esta variable está en el segmento heap.
    printf("heap_var está en la dirección %p\n\n", (void*)heap_var_ptr);
    // Estas variables están en el segmento stack.
    printf("stack_var está en la dirección %p\n", (void*)&stack_var);
    function();

    free(heap_var_ptr); // Liberar memoria asignada
    return 0;
}