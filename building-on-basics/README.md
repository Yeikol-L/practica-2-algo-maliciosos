# Building on basics

Este proyecto contiene una colección de programas en C que demuestran diversas funcionalidades y conceptos de programación, incluyendo operaciones de archivos, manipulación de bits, gestión de permisos de usuario y generación de números pseudorandom.

## Estructura del Proyecto

```
mi-proyecto-c
├── src
│   ├── simplenote.c
│   ├── bitwise.c
│   ├── fcntl_flags.c
│   ├── uid_demo.c
│   ├── notetaker.c
│   ├── notesearch.c
│   ├── rand_example.c
│   └── hacking.h
├── Makefile
└── README.md
```

## Descripción de Archivos

- **src/simplenote.c**: Programa simple para tomar notas que acepta una nota como argumento de línea de comandos y la agrega a un archivo llamado "tmpnotes". Demuestra operaciones de archivos utilizando descriptores de archivos.

- **src/bitwise.c**: Ilustra el uso de operaciones bit a bit, específicamente los operadores OR y AND, para manipular y mostrar representaciones binarias de enteros.

- **src/fcntl_flags.c**: Explora los valores de bandera definidos en `fcntl.h` para operaciones de archivos. Muestra la representación binaria de varias banderas de acceso a archivos utilizadas con la función `open()`.

- **src/uid_demo.c**: Demuestra el concepto de identificadores de usuario reales y efectivos en Unix. Imprime los identificadores de usuario real y efectivo del usuario que ejecuta el programa.

- **src/notetaker.c**: Versión modificada del programa simplenote que registra el ID de usuario de cada autor de nota. Utiliza el permiso setuid para permitir que múltiples usuarios accedan a las notas.

- **src/notesearch.c**: Permite a los usuarios buscar notas escritas por su ID de usuario. También puede filtrar notas basadas en una cadena de búsqueda opcional proporcionada como argumento de línea de comandos.

- **src/rand_example.c**: Demuestra la generación de números pseudorandom utilizando la función `rand()`. Muestra cómo sembrar el generador de números aleatorios y producir valores aleatorios dentro de un rango especificado.

- **src/hacking.h**: Archivo de encabezado que contiene funciones utilitarias para el manejo de errores y la asignación de memoria, específicamente la función `fatal()` para mensajes de error y la función `ec_malloc()` para la asignación de memoria con verificación de errores.

- **Makefile**: Contiene las instrucciones de construcción para compilar los archivos fuente en C en programas ejecutables. Define objetivos para cada programa y especifica los comandos de compilación.

## Instrucciones de Uso

Para compilar el proyecto, simplemente ejecute el siguiente comando en la raíz del proyecto:

```
make
```

Esto generará los ejecutables correspondientes en el directorio `src`. Para ejecutar cada programa, use el siguiente formato:

```
./nombre_del_programa [argumentos]
```

Asegúrese de tener los permisos adecuados para ejecutar los programas que requieren acceso a archivos o permisos de usuario específicos.

## Contribuciones

Las contribuciones son bienvenidas. Si desea mejorar este proyecto, siéntase libre de enviar un pull request o abrir un issue para discutir cambios propuestos.