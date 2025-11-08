/* Pontificia Universidad Javeriana
 * Autor: David Tobar Artunduaga
 * Fecha: 06/11/2025
 * Tema: Programación Paralela - Introducción OpenMP
 * ----------------------------------------------------------
 * Resumen
 * Uso de la directiva y función para hacer uso de OpenMP 
 * Paralelismo para el cálculo de la función SENO
 */

#include <omp.h>      // <--------------- Header necesario para invocar API OpenMP
#include <stdio.h> // Biblioteca estándar de entrada y salida
#include <stdlib.h> // Biblioteca estándar de utilidades
#include <math.h> // Biblioteca matemática para la función SENO
#define MIN(x,y) (((x) < (y))? (x) :(y) ) // Macro para obtener el mínimo entre dos valores

// Se implementa la funcón sumatoria
double fsum(int i){ // calcula la sumatoria de senos desde j=inicio hasta j=fin-1
	int inicio = i *(i + 1)/2; // fórmula para el inicio de la sumatoria
	int fin = inicio + i; // fórmula para el fin de la sumatoria
	double valorSum = 0; // variable para almacenar el resultado de la sumatoria
	for(int j = inicio; j < fin ; j++){ // bucle para calcular la sumatoria
		valorSum += sin(j); // suma el valor del seno de j a la variable valorSum
	}
	return valorSum; // retorna el resultado de la sumatoria
}
int main(int argc, char *argv[]) { //se agrega argumento para numero de hilos
	double resSumatoria = 0; // variable para almacenar el resultado final de la sumatoria
	int rep = 30000; // número de repeticiones para la sumatoria
	if (argc != 2){ //verifica que se pase un argumento ya que va el ejecutable y el numero de hilos
	printf("Error: \n\t$./ejecutable numHilos\n"); // mensaje de error en caso de que no se pase el argumento
	exit(0); // termina el programa
	}

	int numHilos = (int) atoi(argv[1]); //convierte el argumento de cadena a entero
	int maxCores = omp_get_max_threads(); // obtiene el numero maximo de hilos disponibles en la maquina
    printf("Numero maximo de HILOS del SO: %d \n", maxCores); // Muestra número de hilos disponibles en la maquina
	//se fija el numero de hilos deseado: num: numHilos
	omp_set_num_threads(numHilos);  // fija el número de hilos para la región paralela
    #pragma omp parallel //Directiva para paralelizar el siguiente bloque de código
    {
	#pragma omp master // Solo el hilo maestro ejecuta esta sección
	printf("Numero hilos fijados: %d \n", numHilos); // muestra el numero de hilos fijados
	}
	#pragma omp parallel //Directiva para paralelizar el siguiente bloque de código
	{

	#pragma omp for reduction(+: resSumatoria) // Directiva para paralelizar el bucle for con reducción en resSumatoria que sirve para sumar los resultados parciales de cada hilo
	for(int i = 0; i < rep ; i++){ // bucle para calcular la sumatoria
		resSumatoria += fsum(i); // suma el resultado de fsum(i) a resSumatoria
	}
    }
	printf("Resultado sumatoria Funcion SENO: %0.2f \n", resSumatoria); // muestra el resultado final de la sumatoria
    return 0; // Termina el programa
}

