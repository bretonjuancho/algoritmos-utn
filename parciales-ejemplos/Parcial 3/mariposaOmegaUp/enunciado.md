# Mariposa

## Descripción

Una imagen digital puede representarse mediante una **matriz de píxeles**, donde cada píxel
almacena un color en el modelo **RGB**. Cada color se define con tres valores enteros entre
`0` y `255`: **R** *(Red – Rojo)*, **G** *(Green – Verde)* y **B** *(Blue – Azul)*.

Se dice que una imagen de dimensión `N x N` es una **Mariposa** cuando:

- Todos los píxeles a la **izquierda** de la `X` formada por las dos diagonales principales
  comparten un mismo color.
- Todos los píxeles a la **derecha** de dicha `X` comparten otro color.

Es decir, la imagen es **simétrica respecto de ambas diagonales** y cada **ala** de la mariposa
queda pintada de un color en particular.

Se solicita implementar un programa que, dada una dimensión `N`, construya una matriz mariposa
de `N x N` con las siguientes características:

| Región | Ubicación | Color | RGB |
| :--- | :--- | :--- | :--- |
| Ala izquierda | A la izquierda de ambas diagonales | **Cian** | `(0, 255, 255)` |
| Ala derecha | A la derecha de ambas diagonales | **Magenta** | `(255, 0, 255)` |
| Resto | Incluidas las diagonales primaria y secundaria | **Gris** | `(100, 100, 100)` |

## Entrada

El número `N` (`10 <= N <= 30`), que indica la cantidad de filas y columnas de la mariposa.

## Salida

El gráfico de la matriz mariposa, siguiendo esta codificación por píxel:

| Color | Carácter |
| :--- | :---: |
| Cian | `*` (asterisco) |
| Magenta | `-` (guion medio) |
| Gris | ` ` (espacio en blanco) |

> **Importante:** luego de imprimir el carácter de cada píxel (asterisco, guion o espacio),
> se imprime un **espacio en blanco**.

## Ejemplo

Para `N = 10`, la salida es:

```text
                    
*                 - 
* *             - - 
* * *         - - - 
* * * *     - - - - 
* * * *     - - - - 
* * *         - - - 
* *             - - 
*                 - 
                    
```

> Cada fila termina con un espacio en blanco después de su último carácter.

## Casos de prueba

Casos listos para pegar en la terminal (entrada y salida esperada).

### Caso 1

**Entrada:**

```text
10
```

**Salida esperada:**

```text
                    
*                 - 
* *             - - 
* * *         - - - 
* * * *     - - - - 
* * * *     - - - - 
* * *         - - - 
* *             - - 
*                 - 
                    
```

### Caso 2

**Entrada:**

```text
12
```

**Salida esperada:**

```text
                        
*                     - 
* *                 - - 
* * *             - - - 
* * * *         - - - - 
* * * * *     - - - - - 
* * * * *     - - - - - 
* * * *         - - - - 
* * *             - - - 
* *                 - - 
*                     - 
                        
```

### Caso 3

**Entrada:**

```text
15
```

**Salida esperada:**

```text
                              
*                           - 
* *                       - - 
* * *                   - - - 
* * * *               - - - - 
* * * * *           - - - - - 
* * * * * *       - - - - - - 
* * * * * * *   - - - - - - - 
* * * * * *       - - - - - - 
* * * * *           - - - - - 
* * * *               - - - - 
* * *                   - - - 
* *                       - - 
*                           - 
                              
```
