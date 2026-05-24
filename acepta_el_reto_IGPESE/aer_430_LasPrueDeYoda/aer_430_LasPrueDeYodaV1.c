/*
 * aer_430_LasPrueDeYoda.c
 *
 * Descripción: Solución al problema "Las Pruebas de Yoda" del AER (Acepta el Reto).
 * Autor: Ignacio Pérez Serra
 * Fecha: 21/05/2026
 * Versión: 1.0
 */

// Esquema de la entrada: caso de prueba que marca el final
#include <stdio.h>

int casoDePrueba() {

    int P, i;
    scanf("%d", &P);

    if (P == 0)
        return 0;

    int dia = 0;  // Día en el que Luke hizo la última prueba

    for (i = 0; i < P; i++) {

        int D, N;
        scanf("%d %d", &D, &N);

        // La siguiente prueba como mínimo debe hacerse al día siguiente
        int minimo = dia + 1;

        if (minimo <= D) {
            // Si todavía no ha llegado el primer día posible, esperamos hasta D
            dia = D;
        } else {
            // Buscamos el primer día válido D + k*N que sea >= minimo
            int diferencia = minimo - D;

            int k = (diferencia + N - 1) / N;  // División redondeando hacia arriba

            dia = D + k * N;
        }
    }

    printf("%d\n", dia);

    return 1;
}

int main() {

    while (casoDePrueba())
        ;

    return 0;
}