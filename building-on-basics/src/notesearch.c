#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

// Declaraciones de funciones
int print_notes(int fd, int uid, char *searchstring);
int find_user_note(int fd, int user_uid);
int search_note(char *note, char *keyword);

void fatal(char *message) {
    printf("Error: %s\n", message);
    exit(1);
}

int main(int argc, char *argv[]) {
    int userid, printing = 1, fd;
    char searchstring[100];

    if (argc > 1) {
        strcpy(searchstring, argv[1]);
    } else {
        searchstring[0] = 0; // la cadena de búsqueda está vacía
    }

    userid = getuid();
    fd = open("varnotes", O_RDONLY); // Abrir el archivo para acceso de solo lectura
    if (fd == -1) fatal("en main() al abrir el archivo para lectura");

    while (printing) {
        printing = print_notes(fd, userid, searchstring);
    }
    printf("-------[ fin de los datos de la nota ]-------\n");
    close(fd);
}

// Una función para imprimir las notas para un uid dado que coincidan con una cadena de búsqueda opcional
// devuelve 0 al final del archivo, 1 si todavía hay más notas.
int print_notes(int fd, int uid, char *searchstring) {
    int note_length;
    char byte = 0, note_buffer[100];

    note_length = find_user_note(fd, uid);
    if (note_length == -1) return 0; // Si se alcanza el final del archivo, devolver 0

    read(fd, note_buffer, note_length); // Leer los datos de la nota
    note_buffer[note_length] = 0; // Terminar la cadena

    if (search_note(note_buffer, searchstring)) {
        printf("%s\n", note_buffer); // Imprimir la nota si se encuentra la cadena de búsqueda
    }
    return 1;
}

// Una función para encontrar la siguiente nota para un userID dado
// devuelve -1 si se alcanza el final del archivo; de lo contrario, devuelve la longitud de la nota encontrada.
int find_user_note(int fd, int user_uid) {
    int note_uid = -1;
    unsigned char byte;
    int length;

    while (note_uid != user_uid) { // Bucle hasta que se encuentre una nota para user_uid
        if (read(fd, &note_uid, 4) != 4) return -1; // Leer los datos del uid
        if (read(fd, &byte, 1) != 1) return -1; // Leer el separador de nueva línea

        byte = length = 0;
        while (byte != '\n') { // Calcular cuántos bytes hasta el final de la línea
            if (read(fd, &byte, 1) != 1) return -1; // Si no se lee el byte, devolver el código de fin de archivo
            length++;
        }
    }
    lseek(fd, length * -1, SEEK_CUR); // Rebobinar la lectura del archivo en length bytes
    printf("[DEBUG] se encontró una nota de %d bytes para el id de usuario %d\n", length, note_uid);
    return length;
}

// Una función para buscar una nota por una palabra clave dada
// devuelve 1 si se encuentra una coincidencia, 0 si no hay coincidencia.
int search_note(char *note, char *keyword) {
    int i, keyword_length, match = 0;
    keyword_length = strlen(keyword);

    if (keyword_length == 0) return 1; // Si no hay cadena de búsqueda, devolver 1 (siempre "coincide")

    for (i = 0; i < strlen(note); i++) { // Iterar sobre los bytes en la nota
        if (note[i] == keyword[match]) {
            match++; // Prepararse para verificar el siguiente byte
        } else {
            if (note[i] == keyword[0]) {
                match = 1; // Comenzar el conteo de coincidencias en 1
            } else {
                match = 0; // De lo contrario, es cero
            }
        }
        if (match == keyword_length) return 1; // Si hay una coincidencia completa, devolver 1
    }
    return 0; // Devolver no coincidió
}