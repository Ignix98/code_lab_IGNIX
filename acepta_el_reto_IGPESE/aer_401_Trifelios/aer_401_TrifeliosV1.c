/*
 * aer_401_Trifelios.c
 *
 * Descripción: Solución al problema "Trifelios".
 * Autor: Ignacio Pérez Serra
 * Fecha: 25/05/2026
 * Versión: 1.0
 */

// Esquema de la entrada: número de casos
#include <string.h>   // Para usar strlen()
#include <stdio.h>    // Para usar scanf() y printf()
#include <ctype.h>    // Para usar tolower()

// Esta función prepara una letra antes de compararla
// Convierte la letra a minúscula y cambia la 'b' por 'v'
// Así, 'B', 'b' y 'v' se consideran iguales
char normalizar(char c) {
    c = tolower(c);   // Convertimos la letra a minúscula

    if (c == 'b') {   // Si la letra es 'b'
        c = 'v';      // La cambiamos por 'v'
    }

    return c;         // Devolvemos la letra preparada
}

// Esta función comprueba si dos palabras son iguales
// teniendo en cuenta mayúsculas/minúsculas y b/v
int igualesNormalizadas(char A[], char B[], int tam) {
    int i;

    // Recorremos las dos palabras letra por letra
    for (i = 0; i < tam; i++) {

        // Comparamos las letras ya preparadas
        if (normalizar(A[i]) != normalizar(B[i])) {
            return 0; // No son iguales
        }
    }

    return 1; // Son iguales
}

void casoDePrueba() {
    // Estas variables almacenarán las dos palabras a comparar y su tamaño está limitado a 20 caracteres, más el carácter nulo al final
    char A[21], B[21];

    // Leemos las dos palabras
    scanf("%s %s", A, B);

    // Calculamos el tamaño de cada palabra
    int tamA = strlen(A);
    int tamB = strlen(B);

    int i, desplazamiento;

    // Esta variable indica si hemos encontrado que son trifelios
    // 0 = no son trifelios
    // 1 = sí son trifelios
    int trifelios = 0;

    if (tamA != tamB) {
        printf("NO\n");
    } else if (igualesNormalizadas(A, B, tamA)) {
        printf("NO\n");
    } else {

        // Probamos todos los posibles desplazamientos de la palabra A
        // Empezamos en 1 porque el desplazamiento 0 sería la misma palabra
        for (desplazamiento = 1; desplazamiento < tamA && !trifelios; desplazamiento++) {

            // Suponemos que con este desplazamiento coinciden
            int coincide = 1;

            for (i = 0; i < tamA && coincide; i++) {
            // Si llegamos al final de la palabra, volvemos al principio, esto se debe a que obtenemos el resto de la división.
            // Por ejemplo, si el desplazamiento es 2 y el tamaño es 5, entonces:
            // i = 0 -> A[2] (desplazamiento 2)
            // i = 1 -> A[3] (desplazamiento 2)
            // i = 2 -> A[4] (desplazamiento 2)
            // i = 3 -> A[0] (desplazamiento 2, redondeo al principio)
            // i = 4 -> A[1] (desplazamiento 2, redondeo al principio)
            char letraADesplazada = A[(i + desplazamiento) % tamA];

            // Mostramos qué letras se están comparando
            // printf("Comparando A[%d] con B[%d]: '%c' vs '%c'\n", 
            //        (i + desplazamiento) % tamA, i, 
            //        normalizar(letraADesplazada), normalizar(B[i]));

            // Comparamos la letra de A desplazada con la letra de B en la misma posición.
            // Antes de comparar, normalizamos las letras para ignorar mayúsculas y tratar b/v igual.
            if (normalizar(letraADesplazada) != normalizar(B[i])) {
                coincide = 0; 
}
            }

            // Si todas las letras han coincidido,
            // entonces sí son trifelios
            if (coincide) {
                trifelios = 1;
            }
        }

        // Mostramos el resultado final
        if (trifelios) {
            printf("SI\n");
        } else {
            printf("NO\n");
        }
    }
}

int main() {

    unsigned int numCasos, i;

    // Leemos el número de casos de prueba
    scanf("%u", &numCasos);

    // Ejecutamos cada caso de prueba
    for (i = 0; i < numCasos; ++i) {
        casoDePrueba();
    }

    return 0;
}
