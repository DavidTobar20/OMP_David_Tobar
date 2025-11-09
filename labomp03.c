/*#######################################################################################
# Universidad:    Pontificia Universidad Javeriana
# Facultad:       Facultad de Ingeniería
# Carrera:        Ingeniería de Sistemas
# Archivo:        untitled:Untitled-1
# Autor:          David Tobar Artunduaga
# Fecha:          2025-11-04
#
# Descripción:
#   Programa  que usa OpenMP para paralelizar un bucle for.
#   Demuestra el uso de la cláusula private en variables dentro de un pragma omp parallel for.
######################################################################################*/

#include <omp.h>      // Cabecera necesaria para usar la API OpenMP (pragmas, funciones runtime)
#include <stdio.h>    // I/O estándar (printf)
#include <stdlib.h>   // utilidades generales 

int main() {
    int i;                   // índice del bucle (declarado fuera para demostrar private(i) en pragma)
    const int N = 1000;      // número de iteraciones del bucle
    int a = 50;              // variable 'a' inicializada a 50 en el hilo principal
    int b = 0;               // variable 'b' que se actualizará dentro del bucle paralelo

/* 
 * Paraleliza el bucle for con OpenMP.
 * - private(i): cada hilo tiene su propia copia de 'i' (correcto para índices).
 * - private(a): cada hilo obtiene una copia no inicializada de 'a'.
 * - lastprivate(b): al final del bucle, la copia privada de 'b' usada en 
 *                   la última iteración (i = N-1) se asigna a la variable 'b' global.
 */

    #pragma omp parallel for private(i) private(a) lastprivate(b)
    for (i = 0; i < N; i++) {
        b = a + i;            // asigna b usando la copia privada de 'a'.
    }

    /* 
     * Imprime el valor final de 'a' y 'b'.
     */
    printf("a = %d b = %d (Se espera a = 50 b = 1049)\n", a, b);
    return 0;

}
