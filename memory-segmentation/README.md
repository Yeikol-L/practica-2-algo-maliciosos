# Segmentación de Memoria en C

Este proyecto demuestra varios conceptos relacionados con la segmentación de memoria en la programación en C. Incluye ejemplos de uso de memoria en la pila, el montón y memoria global/estática, así como la asignación de memoria con verificación de errores.

## Estructura del Proyecto

```
memory-segmentation
├── src
│   ├── stack_example.c       # Demuestra el uso de memoria en la pila
│   ├── memory_segments.c      # Ilustra diferentes segmentos de memoria
│   ├── heap_example.c         # Muestra la asignación de memoria dinámica usando el heap
│   └── errorchecked_heap.c    # Ejemplo de asignación de memoria con verificación de errores
├── README.md                  # Documentación del proyecto
```
## Ejecución de los Ejemplos

Después de la compilación, puedes ejecutar los ejemplos de la siguiente manera:

1. **Ejemplo de Pila**:
   ```
   ./build/stack_example
   ```

2. **Segmentos de Memoria**:
   ```
   ./build/memory_segments
   ```

3. **Ejemplo de heap**:
   ```
   ./build/heap_example [size]
   ```
   Reemplaza `[size]` con el tamaño deseado de memoria a asignar (opcional).

4. **Ejemplo de heap con Verificación de Errores**:
   ```
   ./build/errorchecked_heap [size]
   ```
   Reemplaza `[size]` con el tamaño deseado de memoria a asignar (opcional).