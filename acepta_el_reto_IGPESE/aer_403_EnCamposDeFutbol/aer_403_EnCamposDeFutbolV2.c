/*
 * aer_403_EnCamposDeFutbol.c
 *
 * Descripción: Solución al problema "En Campos de Fútbol" del AER (Acepta el Reto).
 * Autor: Ignacio Pérez Serra
 * Fecha: 01/06/2026
 * Versión: 1.0
 * 
 */

 /*
 *
 * Formula
 * S = E * A (superficie = estimación * área)
 * Se quiere obtener saber si existe im campo de furbol de dimensiones legales a partir de la
 * estimación y superficies dadas.
 * Para ello la formula va a ser A = S / E (área = superficie / estimación)
 * Se va a comparar entre el area obtenida y el área mínima y máxima de un campo de fútbol,
 * 
 */
// Esquema de la entrada: número de casos
#include <stdio.h>

#define AREA_MINIMA 4050LL
#define AREA_MAXIMA 10800LL

int main() {
    unsigned int numCasos;
    scanf("%u", &numCasos);

    while (numCasos--) {
        long long superficie, estimacion;
        scanf("%lld %lld", &superficie, &estimacion);

        puts(
            AREA_MINIMA * estimacion <= superficie &&
            superficie <= AREA_MAXIMA * estimacion
            ? "SI"
            : "NO"
        );
    }

    return 0;
}