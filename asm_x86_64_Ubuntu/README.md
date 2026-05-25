# Ensamblador en Ubuntu

Este README explica cómo instalar NASM, compilar un archivo escrito en ensamblador y ejecutarlo en Ubuntu.

El ejemplo está pensado para Ubuntu de 64 bits usando ensamblador x86_64.

---

## 1. Instalar NASM

Primero actualiza la lista de paquetes:

```bash
sudo apt update
```

Después instala NASM:

```bash
sudo apt install nasm
```

Puedes comprobar que se ha instalado correctamente con:

```bash
nasm -v
```

Si aparece una versión de NASM, la instalación ha funcionado correctamente.

---

## 2. Crear un archivo en ensamblador

Crea un archivo con extensión `.asm`.

Por ejemplo:

```bash
nano programa.asm
```

Dentro de ese archivo puedes escribir tu código en ensamblador.

Un programa básico para Linux de 64 bits suele tener esta estructura:

```asm
section .data
    ; Aquí se declaran datos, textos o variables

section .text
    global _start

_start:
    ; Aquí empieza el programa

    ; Código del programa

    ; Salir del programa
    mov rax, 60
    mov rdi, 0
    syscall
```

Guarda el archivo.

En `nano`, puedes guardar con:

```txt
Ctrl + O
Enter
Ctrl + X
```

---

## 3. Compilar el archivo ensamblador

Para convertir el archivo `.asm` en un archivo objeto `.o`, usa:

```bash
nasm -f elf64 programa.asm -o programa.o
```

Explicación:

```txt
nasm             ejecuta el ensamblador
-f elf64         indica que queremos formato Linux de 64 bits
programa.asm     archivo fuente
-o programa.o    archivo objeto de salida
```

---

## 4. Enlazar el programa

Después hay que enlazar el archivo objeto para crear el ejecutable:

```bash
ld programa.o -o programa
```

Explicación:

```txt
ld             enlazador
programa.o     archivo objeto
-o programa    ejecutable de salida
```

---

## 5. Ejecutar el programa

Para ejecutar el programa:

```bash
./programa
```

---

## Resumen de comandos

```bash
sudo apt update
sudo apt install nasm
nano programa.asm
nasm -f elf64 programa.asm -o programa.o
ld programa.o -o programa
./programa
```

---

## Notas

- Los archivos de ensamblador suelen tener extensión `.asm`.
- NASM se encarga de compilar el código ensamblador.
- `ld` se encarga de enlazar el archivo objeto y crear el ejecutable.
- En Linux de 64 bits se usa normalmente el formato `elf64`.
- Para ejecutar un programa desde la terminal se escribe `./` delante del nombre del ejecutable.