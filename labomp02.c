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
#include <stdio.h> // Biblioteca estándar de entrada y salida
#include <stdlib.h> // Biblioteca estándar de utilidades

int main(int argc, char *argv[]) { //se agrega argumento para numero de hilos
	if (argc != 2){ //verifica que se pase un argumento ya que va el ejecutable y el numero de hilos
	printf("Error: \n\t$./ejecutable numHilos\n"); // mensaje de error en caso de que no se pase el argumento
	exit(0); // termina el programa
	}

	int numHilos = (int) atoi(argv[1]); //convierte el argumento de cadena a entero
	int maxCores = omp_get_max_threads(); // obtiene el numero maximo de hilos disponibles en la maquina
    printf("OpenMP ejecutando con %d hilos\n", maxCores); // Muestra número de hilos disponibles en la maquina
	//se fija el numero de hilos deseado: num: numHilos
	omp_set_num_threads(numHilos);
	printf("Numero hilos fijados: %d \n", numHilos); // muestra el numero de hilos fijados

    #pragma omp parallel //Directiva para paralelizar el siguiente bloque de código
    {
        // Cada hilo ejecuta esta sección
        printf("Hilo ID en Región Paralela: %d\n", omp_get_thread_num()); // Muestra el ID del hilo actual
    }

    return 0; // Termina el programa
}

