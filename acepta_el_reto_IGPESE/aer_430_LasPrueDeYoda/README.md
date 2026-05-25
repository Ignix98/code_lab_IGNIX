# Las pruebas del maestro Yoda

## Tiempo máximo
1,000-2,000 s

## Memoria máxima
4096 KiB

## Enunciado

Para el entrenamiento de Luke Skywalker, Yoda ha planificado una serie de pruebas que deben realizarse por orden. Cada una requiere un día completo de dedicación por parte de su joven aprendiz.

Por desgracia, las pruebas no pueden realizarse en cualquier momento, porque dependen de las condiciones del entorno y, en ocasiones, de alineaciones planetarias. Para cada una, Yoda sabe cuantos días D faltan para que se pueda realizar por primera vez, y, a partir de ahí, cada cuantos días N puede volver a hacerse. Por ejemplo, uno de los entrenamientos para la Prueba de la Percepción tiene D=5 y N=2, por lo que podrá hacerse dentro de 5 días, o dentro de 7, o dentro de 9…

Sabiendo las pruebas a las que enfrentará a Luke, Yoda quiere saber cuantos días faltan para que haga su última prueba.

## Entrada

Cada caso de prueba comienza con una primera línea indicando el número P de pruebas que Luke tendrá que superar durante su entrenamiento.

A continuación aparecen P líneas, cada una describiendo una prueba en el orden en el que Luke debe realizarlas. Cada prueba se define con los dos números, 1 ≤ D,N ≤ 10^6, indicando cuantos días hay que esperar para poder realizarla por primera vez, y cada cuantos días se puede hacer a partir de ese momento.

La entrada acaba con un 0.

## Salida

Por cada caso de prueba, el programa escribirá cuantos días faltan para que Luke haga su última prueba. Se garantiza que tardará como mucho 10^6 días en terminar.

## Entrada de ejemplo

2
1 1
1 1
2
4 1
1 1
3
4 8
7 2
5 10
0

## Salida de ejemplo

2
5
15