# Hola mundo en ensamblador

Este programa escribe `Hola mundo` por pantalla usando ensamblador x86_64 en Linux.

---

## Código

```asm
section .data
    mensaje db "Hola mundo", 10
    longitud equ $ - mensaje

section .text
    global _start

_start:
    ; Escribir mensaje por pantalla
    mov rax, 1
    mov rdi, 1
    mov rsi, mensaje
    mov rdx, longitud
    syscall

    ; Terminar el programa
    mov rax, 60
    mov rdi, 0
    syscall
```

---

## Explicación sencilla

El programa tiene dos partes principales:

```asm
section .data
```

Aquí se guardan los datos del programa.

En este caso guardamos el texto:

```asm
mensaje db "Hola mundo", 10
```

`db` significa que estamos guardando bytes en memoria.

El `10` es un salto de línea.

---

```asm
longitud equ $ - mensaje
```

Esta línea calcula automáticamente cuánto ocupa el mensaje.

El programa necesita saber la longitud para poder imprimirlo.

---

```asm
section .text
```

Aquí está el código que se ejecuta.

---

```asm
global _start
_start:
```

`_start` indica dónde empieza el programa.

---

## Escribir por pantalla

```asm
mov rax, 1
mov rdi, 1
mov rsi, mensaje
mov rdx, longitud
syscall
```

Esto llama al sistema operativo para escribir en pantalla.

Los registros significan:

```txt
rax = 1          usar syscall write
rdi = 1          escribir en pantalla
rsi = mensaje    texto que queremos mostrar
rdx = longitud   tamaño del texto
```

La instrucción:

```asm
syscall
```

ejecuta la llamada al sistema.

---

## Terminar el programa

```asm
mov rax, 60
mov rdi, 0
syscall
```

Esto termina el programa.

```txt
rax = 60   usar syscall exit
rdi = 0    terminar correctamente
```

---

## Resumen

El programa hace esto:

```txt
1. Guarda el texto "Hola mundo".
2. Calcula su longitud.
3. Llama a write para mostrarlo en pantalla.
4. Llama a exit para terminar.
```

---

## Compilar y ejecutar

```bash
nasm -f elf64 hola.asm -o hola.o
ld hola.o -o hola
./hola
```