#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "hacking.h"

#define FILENAME "varnotes"

int main(int argc, char *argv[]) {
    int userid, fd; // Descriptor de archivo
    char buffer[100]; // Buffer para almacenar la nota

    // Verificar si se proporcionaron argumentos de línea de comandos
    if (argc < 2) {
        printf("Uso: %s <datos para agregar a %s>\n", argv[0], FILENAME);
        exit(0);
    }

    // Copiar la nota del argumento de línea de comandos al buffer
    strcpy(buffer, argv[1]);
    printf("[DEBUG] buffer @ %p: '%s'\n", (void *)buffer, buffer);

    // Abrir el archivo para escritura
    fd = open(FILENAME, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (fd == -1) fatal("en main() al abrir el archivo");

    userid = getuid(); // Obtener el ID de usuario real

    // Escribir el ID de usuario antes de la nota
    if (write(fd, &userid, sizeof(userid)) == -1) 
        fatal("en main() al escribir el ID de usuario en el archivo");
    
    write(fd, "\n", 1); // Terminar línea
    if (write(fd, buffer, strlen(buffer)) == -1) 
        fatal("en main() al escribir el buffer en el archivo");
    
    write(fd, "\n", 1); // Terminar línea

    // Cerrar el archivo
    if (close(fd) == -1) fatal("en main() al cerrar el archivo");

    printf("Nota guardada.\n");
    return 0;
}