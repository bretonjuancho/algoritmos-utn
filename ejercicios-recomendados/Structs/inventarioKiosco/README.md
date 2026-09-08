# Inventario de kiosco

## Enunciado

Un kiosco necesita administrar los productos que tiene a la venta.

Cada producto posee datos básicos y, además, se necesita controlar el stock para saber cuánto dinero hay invertido y qué productos hay que reponer.

## Estructura a definir

### `Producto`
Representa un producto del kiosco. Contiene:

- Código del producto.
- Nombre del producto.
- Precio unitario en `$`.
- Cantidad en stock.

## Requerimientos del programa

El programa debe:

1. **Leer la cantidad de productos `N`:**
   - `N` se ingresa por teclado.
   - Valor máximo: 100.

2. **Para cada uno de los `N` productos, leer:**
   - `codigo`.
   - `nombre`.
   - `precio`.
   - `stock`.

3. **Mostrar el valor en stock de cada producto** (`precio * stock`) y el **valor total del inventario** (suma de todos).

4. **Determinar y mostrar el producto más caro y el más barato**, indicando nombre y precio.

5. **Listar los productos con stock menor a 5 unidades** (hay que reponer).

6. **Listar los productos ordenados por precio de menor a mayor**, indicando nombre y precio.

## Casos de prueba

> Orden de entrada: `N`, y por cada producto: `codigo`, `nombre`, `precio`, `stock`.

### Caso 1: Cinco productos

**Entrada (lista para pegar):**
```
5
101
Alfajor
150
20
102
Chicle
50
3
103
Gaseosa
300
10
104
Chocolate
250
2
105
Agua
200
15
```

**Salida esperada:**
```
Alfajor -- Valor en stock: 3000.00
Chicle -- Valor en stock: 150.00
Gaseosa -- Valor en stock: 3000.00
Chocolate -- Valor en stock: 500.00
Agua -- Valor en stock: 3000.00
Valor total del inventario: 9650.00

Producto mas caro: Gaseosa (300.00)
Producto mas barato: Chicle (50.00)

Productos con stock menor a 5 (a reponer):
Chicle (3 unidades)
Chocolate (2 unidades)

Productos ordenados por precio (de menor a mayor):
Chicle - 50.00
Alfajor - 150.00
Agua - 200.00
Chocolate - 250.00
Gaseosa - 300.00
```

### Caso 2: Un solo producto (caso mínimo)

**Entrada (lista para pegar):**
```
1
201
Caramelo
80
10
```

**Salida esperada:**
```
Caramelo -- Valor en stock: 800.00
Valor total del inventario: 800.00

Producto mas caro: Caramelo (80.00)
Producto mas barato: Caramelo (80.00)

Productos con stock menor a 5 (a reponer):
Ninguno

Productos ordenados por precio (de menor a mayor):
Caramelo - 80.00
```
