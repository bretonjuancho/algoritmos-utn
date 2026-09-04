# Registro de Estudiantes y Materias

## Enunciado

La facultad necesita registrar la información de sus estudiantes y de las materias que cursan.

Cada estudiante posee datos personales y, además, debe guardar las calificaciones obtenidas en un conjunto fijo de materias.

## Estructuras a definir

### 1. `Materia`
Representa una materia cursada por un estudiante. Contiene:

- Nombre de la materia.
- Nota final obtenida en la materia.

### 2. `Estudiante`
Representa a un estudiante de la facultad. Contiene:

- Número de legajo del alumno.
- Nombre y apellido del estudiante.
- Arreglo unidimensional con las 3 materias que cursa.

## Requerimientos del programa

El programa debe:

1. **Leer la cantidad de estudiantes `N`:**
   - `N` se ingresa por teclado.
   - Valor máximo: 50.

2. **Para cada uno de los `N` estudiantes, leer:**
   - `legajo`.
   - `nombre` y `apellido`.
   - Sus 3 materias (para cada una: `nombre` y `nota`).

3. **Calcular y mostrar el promedio general de cada estudiante** a partir de las notas de sus 3 materias.

4. **Determinar y mostrar cuál es el estudiante con el mejor promedio**, indicando sus datos personales y su promedio.

## Casos de prueba

> Orden de entrada: `N`, y por cada estudiante: `legajo`, `nombre`, `nombre materia 1`, `nota 1`, `nombre materia 2`, `nota 2`, `nombre materia 3`, `nota 3`.

### Caso 1: Dos estudiantes

**Entrada (lista para pegar):**
```
2
1001
Ana Perez
Algoritmos
8
Matematica
7
Fisica
9
1002
Juan Gomez
Algoritmos
6
Matematica
6
Fisica
7
```

**Salida esperada:**
```
Ana Perez (legajo 1001) - Promedio: 8.00
Juan Gomez (legajo 1002) - Promedio: 6.33
Mejor promedio: Ana Perez (legajo 1001) con 8.00
```

### Caso 2: Un solo estudiante (caso mínimo)

**Entrada (lista para pegar):**
```
1
2001
Lucia Diaz
Algoritmos
10
Matematica
10
Fisica
9
```

**Salida esperada:**
```
Lucia Diaz (legajo 2001) - Promedio: 9.67
Mejor promedio: Lucia Diaz (legajo 2001) con 9.67
```

### Caso 3: Empate en el mejor promedio

**Entrada (lista para pegar):**
```
3
3001
Pedro Ruiz
Algoritmos
7
Matematica
7
Fisica
7
3002
Maria Lopez
Algoritmos
9
Matematica
8
Fisica
7
3003
Carlos Sosa
Algoritmos
8
Matematica
8
Fisica
8
```

**Salida esperada:**
```
Pedro Ruiz (legajo 3001) - Promedio: 7.00
Maria Lopez (legajo 3002) - Promedio: 8.00
Carlos Sosa (legajo 3003) - Promedio: 8.00
Mejor promedio: Maria Lopez (legajo 3002) con 8.00 (en caso de empate se muestra el primero encontrado)
```