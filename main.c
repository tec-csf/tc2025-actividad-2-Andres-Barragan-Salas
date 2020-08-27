/* Autor: Andres Barragan Salas
          A01026567
   Actividad 2: Programación Avanzada
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 7

// Estructura "Libro" para pruebas
typedef struct {
    char * titulo;
    int paginas;
} Libro;

// Tipos de funciones
typedef void (* print)(void *);
typedef void (* iterationType)(void *, size_t, size_t, print);

// Declaración de las funciones de recorrido
void recorre(iterationType method, void * array, size_t count, size_t size, print print); 
void forwardIterator(void * array, size_t count, size_t size, print print);
void reverseIterator(void * array, size_t count, size_t size, print print);
void bidirectionalIterator(void * array, size_t count, size_t size, print print);

// Funciones del iterador
void * begin(void * array);
void * end(void * array, size_t count, size_t size);
void * next(void * current, void * array, size_t count, size_t size);
void * prev(void * current, void * array, size_t count, size_t size);

// Funciones de impresión
void printInt(void * element);
void printFloat(void * element);
void printLibro(void * element);

// Función para liberar memoria
void freeLibros(void * array);

// Ejecución principal
int main(int argc, const char * argv[]) {
    printf("Recorrido con numeros enteros (int):\n");
    // Crear un vector de enteros
    int * intVector = (int *) malloc(N * sizeof(int));
    int * intAux = intVector;
    int * intLast = intVector + N;
    for (; intAux < intLast; ++intAux) {
        *intAux = rand() % 40;
    }
    // Recorrer el vector de enteros
    recorre(&forwardIterator, intVector, N, sizeof(int), &printInt);
    recorre(&reverseIterator, intVector, N, sizeof(int), &printInt);
    recorre(&bidirectionalIterator, intVector, N, sizeof(int), &printInt);

    printf("  ---------------------------------------------------\n\n");
    printf("Recorrido con numeros con punto decimal (float):\n");
    // Crear un vector de floats
    float * floatVector = (float *) malloc(N * sizeof(float));
    float * floatAux = floatVector;
    float * floatLast = floatVector + N;
    for (; floatAux < floatLast; ++floatAux) {
        *floatAux = (float)(rand() % 100) / (float)(rand() % 80);
    }
    // Recorrer el vector de floats
    recorre(&forwardIterator, floatVector, N, sizeof(float), &printFloat);
    recorre(&reverseIterator, floatVector, N, sizeof(float), &printFloat);
    recorre(&bidirectionalIterator, floatVector, N, sizeof(float), &printFloat);

    printf("  ---------------------------------------------------\n\n");
    printf("Recorrido con libros (Libro):\n");
    // Crear un vector de libros
    Libro * libVector = (Libro *) malloc(N * sizeof(Libro));
    Libro * libAux = libVector;
    Libro * libLast = libVector + N;
    for (; libAux < libLast; ++libAux) {
        libAux->titulo = (char *) malloc(sizeof(char) * 30);
        sprintf(libAux->titulo, "Libro No.%d", rand() % 40);
        libAux->paginas = rand() % 400;
    }
    // Recorrer el vector de libros
    recorre(&forwardIterator, libVector, N, sizeof(Libro), &printLibro);
    recorre(&reverseIterator, libVector, N, sizeof(Libro), &printLibro);
    recorre(&bidirectionalIterator, libVector, N, sizeof(Libro), &printLibro);

    // Liberar la memoria
    free(intVector);
    free(floatVector);
    freeLibros(libVector);
    free(libVector);

    return 0;
}

// Definición de función genérica
void recorre(iterationType method, void * array, size_t count, size_t size, print print) {
    (*method)(array, count, size, print);
}

// Definición de los tipos de iteración
void forwardIterator(void * array, size_t count, size_t size, print print){
    printf("Forward Iteration:\n");
    void * last = end(array, count, size);
    for (void * current = begin(array); current <= last; current = next(current, array, count, size)) {
        (*print)(current); 
    }
    printf("\n");
}
void reverseIterator(void * array, size_t count, size_t size, print print) {
    printf("Reverse Iteration:\n");
    void * first = begin(array);
    for (void * current = end(array, count, size); current >= first; current = prev(current, array, count, size)) {
        (*print)(current); 
    }
    printf("\n");
}
void bidirectionalIterator(void * array, size_t count, size_t size, print print) {
    printf("Bidirectional Iteration (2):\n");
    forwardIterator(array, count, size, print);
    reverseIterator(array, count, size, print);
}

// Definición de los iteradores
void * begin(void * array) {
    return array; 
}
void * end(void * array, size_t count, size_t size) {
    return array + ((count - 1) * size);
}
void * next(void * current, void * array, size_t count, size_t size) {
    void * last = end(array, count, size);
    if (current <= last) {
        return current + size;
    }
    return NULL; 
}
void * prev(void * current, void * array, size_t count, size_t size) {
    void * first = begin(array);
    if (current >= first) {
        return current - size;
    }
    return NULL;
}

// Funciones de impresión
void printInt(void * element) {
    printf("%d\n", *(int *)element);
}
void printFloat(void * element) {
    printf("%.4f\n", *(float *)element);
}
void printLibro(void * element) {
    printf("%s (%d pgs)\n", ((Libro *)element)->titulo, ((Libro *)element)->paginas);
}

// Liberar arreglo de libros
void freeLibros(void * array) {
    void * last = end(array, N, sizeof(Libro));
    for (void * current = begin(array); current <= last; current = next(current, array, N, sizeof(Libro))) {
        free(((Libro *)current)->titulo);
    }
}