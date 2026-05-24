/*
 * aer_427_YoSoyTu.c
 *
 * Descripción: Solución al problema "Y Soy Tu" del AER (Acepta el Reto).
 * Autor: Ignacio Pérez Serra
 * Fecha: 19/05/2026
 * Versión: 1.0
 */

#include <stdio.h>
#include <string.h>

int main() {
    int casos, i;
    char A[101], B[101];

    scanf("%d", &casos);

    for (i = 0; i < casos; i++) {
        scanf("%s %s", A, B);

        if (strcmp(A, "Luke") == 0 && strcmp(B, "padre") == 0) {
            printf("TOP SECRET\n");
        } else {
            printf("%s, yo soy tu %s\n", A, B);
        }
    }

    return 0;
}