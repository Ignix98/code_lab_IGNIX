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
#include <stdbool.h>

#define AREA_MINIMA 4050LL // Área mínima de un campo de fútbol en metros cuadrados 90 * 45
#define AREA_MAXIMA 10800LL // Área máxima de un campo de fútbol en metros cuadrados 120 * 90

bool esEstimacionValida(long long superficie, long long estimacion) {
    // Se compara el área obtenida con el área mínima y máxima de un campo de fútbol.
    return AREA_MINIMA * estimacion <= superficie &&
           superficie <= AREA_MAXIMA * estimacion;
}

void casoDePrueba() {
    long long superficie, estimacion;
    scanf("%lld %lld", &superficie, &estimacion);

    puts(esEstimacionValida(superficie, estimacion) ? "SI" : "NO");
    /*
    if (esEstimacionValida(superficie, estimacion)) {
        printf("SI\n");
    } else {
        printf("NO\n");
    }
    */
} // casoDePrueba

int main() {

  unsigned int numCasos, i;

  scanf("%u", &numCasos);
  for (i = 0; i < numCasos; ++i)
    casoDePrueba();

  return 0;

} // main