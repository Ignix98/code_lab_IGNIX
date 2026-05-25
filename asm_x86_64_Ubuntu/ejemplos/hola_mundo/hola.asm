section .data
    mensaje db "Hola mundo", 10
    longitud equ $ - mensaje

section .text
    global _start

_start:
    ; syscall write
    ; write(1, mensaje, longitud)
    mov rax, 1          ; número de syscall: write
    mov rdi, 1          ; 1 = salida estándar, pantalla
    mov rsi, mensaje    ; dirección del mensaje
    mov rdx, longitud   ; longitud del mensaje
    syscall

    ; syscall exit
    ; exit(0)
    mov rax, 60         ; número de syscall: exit
    mov rdi, 0          ; código de salida 0
    syscall