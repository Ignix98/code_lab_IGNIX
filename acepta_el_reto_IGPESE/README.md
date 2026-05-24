# ACEPTA EL RETO
Acepta el Reto es una plataforma de programación competitiva donde resuelves problemas de lógica y algoritmos enviando código que se corrige automáticamente. Se usa mucho para practicar, aprender y prepararse para concursos o entrevistas técnicas.

# GUÍA RÁPIDA: COMPILAR, EJECUTAR Y MEDIR PROGRAMAS

## 1. Compilar

### C

```bash
gcc -O2 programa.c -o programa
```

### C++

```bash
g++ -O2 programa.cpp -o programa
```

### Java

```bash
javac Programa.java
```

## 2. Ejecutar con archivo de entrada

### C / C++

```bash
./programa < entrada.txt
```

### Java

```bash
java Programa < entrada.txt
```

## 3. Medir tiempo estilo "real"

### C / C++

```bash
time ./programa < entrada.txt
```

### Java

```bash
time java Programa < entrada.txt
```

## 4. Medir memoria máxima

### C / C++

```bash
/usr/bin/time -v ./programa < entrada.txt
```

### Java

```bash
/usr/bin/time -v java Programa < entrada.txt
```

## 5. Ver solo tiempo y memoria

### C / C++

```bash
/usr/bin/time -f "Tiempo: %E\nMemoria: %M KB" ./programa < entrada.txt
```

### Java

```bash
/usr/bin/time -f "Tiempo: %E\nMemoria: %M KB" java Programa < entrada.txt
```