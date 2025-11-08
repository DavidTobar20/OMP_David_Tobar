/* Pontificia Universidad Javeriana
 * Autor: David Tobar Artunduaga
 * Fecha: 06/11/2025
 * Tema: Programación Paralela - Introducción OpenMP
 * ----------------------------------------------------------
 * Resumen
 * Programa crea hilos de ejecución para cada core
 * imprime cadena de caracteres por cada llamada.
 */

#include <omp.h>      // <--------------- Header necesario para invocar API OpenMP
#include <stdio.h> // incluye funciones de E/S (printf)
#include <stdlib.h>  // incluye funciones de utilidades generales

int main(int argc, char *argv[]) {
    printf("OpenMP ejecutando con %d hilos\n", omp_get_max_threads()); // Muestra número de hilos disponibles en la maquina
    #pragma omp parallel //Directiva para paralelizar el siguiente bloque de código
    {
        // Cada hilo ejecuta esta sección
        printf("Hello World desde el thread %d\n", omp_get_thread_num()); // Muestra el ID del hilo actual
    }

    return 0; // Termina el programa
}

