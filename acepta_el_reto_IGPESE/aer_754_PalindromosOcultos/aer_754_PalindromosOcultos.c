/*
 * aer_754_PalindromosOcultos.c
 *
 * Descripción: Solución al problema "Palindromos Ocultos".
 * Autor: Ignacio Pérez Serra
 * Fecha: 25/05/2026
 * Versión: 1.0
 */

 // Esquema de la entrada: fin de la entrada
#include <stdio.h>
#include <string.h>

void contarLetras(char palabra[], int contador[]) {
    int i;

    // Inicializamos todos los contadores a 0
    for (i = 0; i < 26; i++) {
        contador[i] = 0;
    }

    // Recorremos la palabra y contamos sus letras
    for (i = 0; palabra[i] != '\0'; i++) {
        contador[palabra[i] - 'a']++;
    }
}

int hayPalindromoOculto(int contador[]) {
    int i;
    int letrasImpares = 0;

    // Contamos cuántas letras tienen un número impar de apariciones
    for (i = 0; i < 26 && letrasImpares <= 1; i++) {
        if (contador[i] % 2 != 0) {
            letrasImpares++;
        }
    }

    // Para que haya un palíndromo oculto, solo puede haber una letra con un número impar de apariciones
    if (letrasImpares > 1) {
        return 0; // false
    } else {
        return 1; // true
    }
}

void crearPalindromoOculto(int contador[], char palindromo[]) {
    int i, j;
    int indice = 0;

    // Construimos la primera mitad del palíndromo
    for (i = 0; i < 26; i++) {
        for (j = 0; j < contador[i] / 2; j++) {
            palindromo[indice++] = 'a' + i;
        }
    }

    // Si hay una letra con un número impar de apariciones, la colocamos en el centro
    for (i = 0; i < 26; i++) {
        if (contador[i] % 2 != 0) {
            palindromo[indice++] = 'a' + i;
            break;
        }
    }

    // Construimos la segunda mitad del palíndromo
    for (i = 25; i >= 0; i--) {
        for (j = 0; j < contador[i] / 2; j++) {
            palindromo[indice++] = 'a' + i;
        }
    }

    palindromo[indice] = '\0'; // Terminamos la cadena con un carácter nulo
}

int casoDePrueba() {

    char palabra[21];
    if (scanf("%s", palabra) == EOF) {
        return 0; // No se ha podido leer nada
    }else {
        // CÓDIGO PRINCIPAL AQUÍ (incluyendo el resto de la lectura)
        // Procesa un único caso
        // printf("Palabra leída: %s\n", palabra);
        int contador[26];

        contarLetras(palabra, contador);

        int hayPalindromo = hayPalindromoOculto(contador);
        // printf("¿Hay palíndromo oculto? %s\n", hayPalindromo ? "Sí" : "No");

        if (hayPalindromo) {
            char palindromo[21];
            crearPalindromoOculto(contador, palindromo);
            printf("%s\n", palindromo);
        } else {
            printf("NO HAY\n");
        }

        return 1; // true
    }

} // casoDePrueba

int main() {

  while(casoDePrueba())
    ;

  return 0;

} // main