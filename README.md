[![Work in Repl.it](https://classroom.github.com/assets/work-in-replit-14baed9a392b3a25080506f3b7b6d57f295ec2978f6f33ec97e36a161684cbe9.svg)](https://classroom.github.com/online_ide?assignment_repo_id=3014420&assignment_repo_type=AssignmentRepo)
# Actividad Individual *2*: *Apuntadores a Funciones*  

##### Estudiante:  
*Andrés Barragán Salas* - *A01026567* - *CSF*  

## Instrucciones
Escriba un programa en C que permita recorrer un arreglo de cualquier tipo de datos utilizando diferentes tipos de iteradores (Forward Iterator, Reverse Iterator, Bidirectional Iterator).

Demuestre el funcionamiento del programa de la siguiente manera:

1. Recorriendo un arreglo de números enteros utilizando un Forward Iterator.
2. Recorriendo un arreglo de estructuras del tipo Libro, utilizando un Bidirectional Iterator.

        struct  Libro {  
          char * titulo;  
          int paginas;  
        }  

El iterador debe contener, al menos, las siguientes funcionalidades: 

* begin :  Regresa un apuntador al primer elemento 
* end : Regresa un apuntador al último elemento
* next : Regresa un apuntador al siguiente elemento. Si se llegó al final debe regresar NULL.
* prev : Regresa un apuntador al elemento anterior. Si llegó al inicio debe regresar NULL.

Tenga en cuenta que debe existir una función genérica denominada Recorre que debe recibir como parámetros un arreglo de cualquier tipo y un iterador de cualquier tipo y debe recorrer el arreglo utilizando el iterador especificado y mostrar el contenido del arreglo.

 
