# Ventas por vendedor

## Enunciado

Una empresa necesita analizar las ventas mensuales de sus vendedores para premiar a los mejores y detectar las zonas con mayor facturación.

Cada vendedor pertenece a una zona de venta y registra lo vendido en cada una de las 4 semanas del mes. La zona es a su vez una estructura con número y nombre (`1-Norte`, `2-Sur`, `3-Este`, `4-Oeste`). A partir de esa información se calculan totales, máximos por vendedor y por zona, casos sin ventas y un ranking.

## Estructuras a definir

### `Zona`
Representa la zona de venta de un vendedor. Contiene:

- Número de zona (`1` a `4`).
- Nombre de la zona (`Norte`, `Sur`, `Este`, `Oeste`).

### `Vendedor`
Representa a un vendedor de la empresa. Contiene:

- Código del vendedor.
- Nombre del vendedor.
- Zona de venta (struct `Zona` anidada).
- Arreglo con las 4 ventas semanales en `$` (una por cada semana del mes).

## Requerimientos del programa

El programa debe:

1. **Leer la cantidad de vendedores `N`:**
   - `N` se ingresa por teclado.
   - Valor máximo: 50.

2. **Para cada uno de los `N` vendedores, leer:**
   - `codigo`.
   - `nombre`.
   - `zona.numero` (`1` a `4`, el `nombre` se asigna automáticamente: `1-Norte`, `2-Sur`, `3-Este`, `4-Oeste`).
   - Sus 4 ventas semanales.

3. **Mostrar el total mensual de cada vendedor** (`suma de sus 4 semanas`) y el **total general de la empresa** (suma de todos).

4. **Determinar y mostrar al mejor vendedor** (el de mayor total mensual). En caso de empate se muestra el primero encontrado.

5. **Determinar y mostrar la zona con mayor venta total** (suma de los totales de sus vendedores). En caso de empate se muestra la primera encontrada.

6. **Listar los vendedores que no vendieron nada en alguna semana** (alguna de sus 4 ventas igual a `0`).

7. **Listar los vendedores ordenados de mayor a menor por total mensual**, indicando nombre y total.

## Casos de prueba

> Orden de entrada: `N`, y por cada vendedor: `codigo`, `nombre`, `zona`, `venta semana 1`, `venta semana 2`, `venta semana 3`, `venta semana 4`.

### Caso 1: Cuatro vendedores

**Entrada (lista para pegar):**
```
4
101
Ana
1
1000
1500
2000
500
102
Bruno
2
2000
2000
2000
2000
103
Carla
1
500
0
1500
1000
104
Diego
3
3000
2500
1000
500
```

**Salida esperada:**
```
Ana (Zona Norte) -- Total mensual: 5000.00
Bruno (Zona Sur) -- Total mensual: 8000.00
Carla (Zona Norte) -- Total mensual: 3000.00
Diego (Zona Este) -- Total mensual: 7000.00
Total general de la empresa: 23000.00

Mejor vendedor: Bruno - Zona Sur (8000.00)

Zona con mayor venta: 1 - Norte (8000.00)

Vendedores sin ventas en alguna semana:
Carla

Ranking de vendedores (de mayor a menor):
Bruno (Zona Sur) - 8000.00
Diego (Zona Este) - 7000.00
Ana (Zona Norte) - 5000.00
Carla (Zona Norte) - 3000.00
```

> Detalle del cálculo: Ana `1000+1500+2000+500 = 5000`, Bruno `8000`, Carla `500+0+1500+1000 = 3000`, Diego `3000+2500+1000+500 = 7000`. Total general `23000`. Por zona: zona 1 `5000+3000 = 8000`, zona 2 `8000`, zona 3 `7000`, zona 4 `0.00`.

### Caso 2: Dos vendedores sin semanas en cero

**Entrada (lista para pegar):**
```
2
201
Elena
4
100
200
300
400
202
Franco
4
500
500
500
500
```

**Salida esperada:**
```
Elena (Zona Oeste) -- Total mensual: 1000.00
Franco (Zona Oeste) -- Total mensual: 2000.00
Total general de la empresa: 3000.00

Mejor vendedor: Franco - Zona Oeste (2000.00)

Zona con mayor venta: 4 - Oeste (3000.00)

Vendedores sin ventas en alguna semana:
Ninguno

Ranking de vendedores (de mayor a menor):
Franco (Zona Oeste) - 2000.00
Elena (Zona Oeste) - 1000.00
```
