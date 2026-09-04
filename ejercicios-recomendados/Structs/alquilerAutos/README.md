# Alquiler de autos

## Enunciado

Una empresa de alquiler de autos cuenta con dos lotes de información. Se pide procesarlos para obtener estadísticas de facturación, autos sin alquilar, clientes frecuentes y categorías.

## Lote 1: autos (300 registros)

Un registro por cada uno de los 300 autos. Cada registro contiene:

- **Código de auto**: número de 4 dígitos, no correlativos.
- **Categoría del auto**: `1` a `7`.
- **Importe del alquiler por km**: en `$`.

Este lote se encuentra **ordenado por código de auto**.

## Lote 2: alquileres del mes pasado

Un registro por cada alquiler realizado durante el mes pasado. Cada registro contiene:

- **Código de auto**: número de 4 dígitos, no correlativos.
- **Número de cliente**: `1` a `200`.
- **Total de días del alquiler**.
- **Kilómetros recorridos**.

Este lote finaliza con un registro con **número de cliente igual a cero** (centinela, no procesar).

Puede haber **más de un registro para el mismo auto y para el mismo cliente**.

## Se pide determinar e informar

1. Un listado con el total abonado por cliente, con el siguiente formato:

   ```text
   Nro. Cliente
   Total de $ abonados en alquiler
   999
   9999,99
   ```

   Este listado debe salir **ordenado de mayor a menor por total de `$`** y solamente se informarán aquellos clientes que hayan abonado en total **más de `$1500`**.

2. Cada uno de los códigos de los autos que **no fueron alquilados**.

3. Los números de los clientes que alquilaron autos **más de 2 veces** (sin importar cuántos kilómetros recorrieron).

4. La **categoría de auto más veces alquilada** por los clientes.

5. El **auto por el que se recaudó más dinero** en alquiler.

## Nota

Para calcular el importe del alquiler de un auto se debe multiplicar el importe en `$` por km por la cantidad de kilómetros recorridos:

```text
importe = precioPorKm * kilometrosRecorridos
```

La cantidad de días del alquiler es solo dato del registro, no interviene en el importe.

## Ejemplo ilustrativo (versión reducida)

Lote 1 (5 autos, ordenado por código):

```text
codigo  categoria  precioPorKm
1010    2          10.00
2020    5          20.00
3030    2          15.00
4040    1          30.00
5050    5          12.00
```

Lote 2 (alquileres):

```text
codigo  cliente  dias  km
1010    1        3     100   -> $1000
2020    1        2     50    -> $1000
1010    2        1     200   -> $2000
3030    3        1     10    -> $150
4040    3        2     20    -> $600
1010    3        1     5     -> $50
4040    4        5     100   -> $3000
0 (fin)
```

Salida esperada:

```text
1) Clientes con total mayor a $1500 (de mayor a menor):
Nro. Cliente  Total
4             3000.00
1             2000.00
2             2000.00
(El cliente 3 totaliza $800, no se informa.)

2) Autos no alquilados:
5050

3) Clientes con mas de 2 alquileres:
3

4) Categoria mas alquilada:
2 (4 alquileres: 3 del auto 1010 y 1 del auto 3030)

5) Auto con mayor recaudacion:
4040 ($3600: $600 + $3000)
```
