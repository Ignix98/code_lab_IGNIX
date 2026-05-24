/*
 * aer_244_ReinasAtacadas.c
 *
 * Descripción: Solución al problema "Reinas Atacadas" del AER (Acepta el Reto).
 * Autor: Ignacio Pérez Serra
 * Fecha: 18/05/2026
 * Versión: 1.0
 * El programa compara las posiciones de las reinas para determinar si alguna de ellas se ataca entre sí, considerando filas, columnas y diagonales.
 * Se asume que el input es correcto y no se realizan validaciones adicionales, ya que es un problema de concurso. La eficiencia se mejora al comparar solo pares de reinas y usar una
 * flag para indicar si se han encontrado reinas atacadas, evitando iteraciones innecesarias.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Reina;

int casoDePrueba() {
    int tamanyo;
    int numReinas;
    Reina reinas[100];
    int i, j;
    int atacadas;
    
    // Leer el tamaño del tablero y el número de reinas
    scanf("%d %d", &tamanyo, &numReinas);

    // Caso que marca el final
    if (tamanyo == 0 && numReinas == 0) {
        return 0;
    }

    // Leer coordenadas de las reinas
    for (i = 0; i < numReinas; i++) {
        scanf("%d %d", &reinas[i].x, &reinas[i].y);
    }

    // Aquí va la lógica principal del problema
    // Consideraciones a tener en cuenta:
    // 1. No se tiene en cuenta que siempre será cuadrado de como mucho 2.000×2.000, debido a que al ser un problema de concurso 
    //    se asume que el input es correcto y no se necesitan validaciones adicionales.
    //
    // Mejoras encontradas:
    // 1. J siempre es mayor que i, lo que evita comparaciones redundantes y mejora la eficiencia.
    // 2. Al usar atacadas como una flag, se evita la necesidad de iterar innnecesariamente.
    // 3. Al principio se ha planteado recorrer todas las filas, columnas y diagonales, pero esto es ineficiente.
    //    En su lugar, se compara cada par de reinas directamente, lo que es más eficiente.
    // ----------------------------------------
    atacadas = 0;
    for (i = 0; i < numReinas && !atacadas; i++) {
        for (j = i + 1; j < numReinas && !atacadas; j++) {

            int mismaFila = reinas[i].y == reinas[j].y;
            int mismaColumna = reinas[i].x == reinas[j].x;
            int mismaDiagonal = abs(reinas[i].x - reinas[j].x) == abs(reinas[i].y - reinas[j].y);

            if (mismaFila || mismaColumna || mismaDiagonal) {
                atacadas = 1;
            }
        }
    }

    if (atacadas) {
        printf("SI\n");
    } else {
        printf("NO\n");
    }

    // Mostrar datos leídos del tamaño del tablero, reinas y coordenadas (esto se puede eliminar o comentar en la versión final)
    /*
    printf("Tamanyo del tablero: %d x %d\n", tamanyo, tamanyo);
    printf("Numero de reinas: %d\n", numReinas);

    for (int i = 0; i < numReinas; i++) {
        printf("Reina %d: x = %d, y = %d\n",
               i + 1,
               reinas[i].x,
               reinas[i].y);
    }

    printf("\n");
    */
    return 1;
}

int main() {
    while (casoDePrueba());

    return 0;
}