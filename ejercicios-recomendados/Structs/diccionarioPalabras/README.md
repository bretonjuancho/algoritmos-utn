# Diccionario de palabras

## Enunciado

Un diccionario puede ser visto como una colección ordenada de palabras. Cada palabra consiste en un término (string de hasta 25 caracteres), una categoría gramatical (`0 = sustantivo`, `1 = adjetivo`, `2 = artículo`, `3 = pronombre` y `4 = verbo`), y una o más definiciones (lista de —como máximo— 5 strings).

En base a estas definiciones, se solicita:

1. Definir todas las estructuras de datos necesarias para representar un diccionario.
2. Definir e implementar la función `cantidadDeArticulos()` que recibe un diccionario y devuelve la cantidad de palabras que corresponden a artículos.
3. Definir e implementar la función `encontrarPalabra()` que recibe un diccionario y un término e imprime por pantalla todas las definiciones asociadas a dicho término. Además, si el término fue encontrado devuelve `true`. En caso contrario, se devuelve `false`.

## Estructura a definir

### `Palabra`
Representa una palabra del diccionario. Contiene:

- Término (`string`, máximo 25 caracteres, sin espacios).
- Categoría gramatical (`int`: 0 sustantivo, 1 adjetivo, 2 artículo, 3 pronombre, 4 verbo).
- Definiciones (vector de `string`, máximo 5).
- Cantidad de definiciones (`cantDefiniciones`, entre 1 y 5).

### `Diccionario`
Representa la colección ordenada de palabras. Contiene:

- Vector de `Palabra` (máximo 100, ordenado alfabéticamente por `termino`).
- Cantidad de palabras (`cant`).

## Requerimientos del programa

El programa debe:

1. **Leer la cantidad de palabras `N`:**
   - `N` se ingresa por teclado.
   - Valor máximo: 100.

2. **Para cada una de las `N` palabras, leer:**
   - `termino`.
   - `categoria` (0 a 4).
   - `cantDefiniciones` (1 a 5).
   - Las `cantDefiniciones` definiciones (una por línea, sin espacios: usar `_` en lugar de espacios).

3. **Mostrar la cantidad de artículos** llamando a `cantidadDeArticulos(diccionario)`.

4. **Leer un término a buscar, llamar a `encontrarPalabra(diccionario, termino)`**, mostrar por pantalla todas sus definiciones (una por línea) e informar si devolvió `true` (encontrado) o `false` (no encontrado).

> Nota: para que el pegado directo en terminal funcione, escribir términos y definiciones sin espacios.

## Casos de prueba

> Orden de entrada: `N`, y por cada palabra: `termino`, `categoria`, `cantDefiniciones`, `definicion1` ... `definicionN`. Al final: `terminoABuscar`.

### Caso 1: Diccionario mixto, búsqueda exitosa

Prueba `cantidadDeArticulos()` con 2 artículos y `encontrarPalabra()` con una palabra de 2 definiciones.

**Entrada (lista para pegar):**
```
5
casa
0
2
Edificio_para_habitar
Hogar_familia
correr
4
2
Moverse_rapidamente
Participar_en_carrera
el
2
1
Articulo_determinado_masculino
la
2
1
Articulo_determinado_femenino
rapido
1
1
Que_se_mueve_a_gran_velocidad
casa
```

**Salida esperada:**
```
Cantidad de articulos: 2

Definiciones de 'casa':
1. Edificio_para_habitar
2. Hogar_familia
Resultado: true (palabra encontrada)
```

### Caso 2: Sin artículos, búsqueda fallida

Prueba `cantidadDeArticulos() = 0` y `encontrarPalabra()` con término inexistente (devuelve `false`).

**Entrada (lista para pegar):**
```
3
correr
4
1
Moverse_rapidamente
perro
0
1
Animal_domestico
veloz
1
1
Que_es_rapido
gato
```

**Salida esperada:**
```
Cantidad de articulos: 0

Palabra 'gato' no encontrada.
Resultado: false (palabra no encontrada)
```

### Caso 3: Caso borde — una sola palabra con 5 definiciones (máximo)

Prueba límite de 5 definiciones y categoría artículo.

**Entrada (lista para pegar):**
```
1
el
2
5
Articulo_masculino
Determinante_singular
Define_sustantivo
Del_latin_ille
Uso_frecuente
el
```

**Salida esperada:**
```
Cantidad de articulos: 1

Definiciones de 'el':
1. Articulo_masculino
2. Determinante_singular
3. Define_sustantivo
4. Del_latin_ille
5. Uso_frecuente
Resultado: true (palabra encontrada)
```

### Caso 4: Búsqueda de pronombre y verbo

Prueba que la búsqueda funciona en cualquier posición del diccionario.

**Entrada (lista para pegar):**
```
4
el
2
1
Articulo_determinado
ellos
3
1
Pronombre_personal_tercera_persona
hablar
4
2
Comunicarse_con_palabras
Expresar_ideas
mesa
0
1
Mueble_con_tablero
hablar
```

**Salida esperada:**
```
Cantidad de articulos: 1

Definiciones de 'hablar':
1. Comunicarse_con_palabras
2. Expresar_ideas
Resultado: true (palabra encontrada)
```
