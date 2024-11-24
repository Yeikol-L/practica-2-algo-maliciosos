#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "hacking.h"

void usage(char *prog_name, char *filename) {
    printf("Uso: %s <datos a agregar a %s>\n", prog_name, filename);
    exit(0);
}

int main(int argc, char *argv[]) {
    int fd; // descriptor de archivo
    char *buffer, *datafile;

    buffer = (char *) ec_malloc(100);
    datafile = (char *) ec_malloc(20);
    strcpy(datafile, "tmpnotes");

    if (argc < 2) // Si no hay argumentos en la línea de comandos, mostrar uso y salir.
        usage(argv[0], datafile);

    strcpy(buffer, argv[1]); // Copiar el argumento en el buffer.
    strncat(buffer, "\n", 1); // Agregar un salto de línea al final.

    // Abrir el archivo
    fd = open(datafile, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (fd == -1) fatal("en main() al abrir el archivo");

    // Escribir datos
    if (write(fd, buffer, strlen(buffer)) == -1) 
        fatal("en main() al escribir el buffer en el archivo");

    // Cerrar el archivo
    if (close(fd) == -1) fatal("en main() al cerrar el archivo");

    printf("La nota ha sido guardada.\n");

    free(buffer);
    free(datafile);
    return 0;
}