# Tráfico de correo entre servidores

Una empresa posee **N servidores** (max. 100) y desea analizar el tráfico de correo electrónico entre ellos. Para esto, almacenará los datos en una matriz `correo` de `N x N` elementos.

El elemento `correo[i][j]` indicará el número de kb de correo enviados desde el servidor `i` hasta el servidor `j`.

## Información a obtener

1. Total de correo, en kb, enviado por cada uno de los servidores.
2. Número del servidor que ha enviado la mayor cantidad de kb en correos.
3. Servidores que recibieron correo por encima de una cota `M` establecida, recibida como dato.

## Entrada

1. El número `N` (cantidad de servidores).
2. La cota `M`.
3. `N` filas con `N` datos cada una, correspondientes a los kb enviados desde el servidor `i` al servidor `j`.

## Ejemplo

### Entrada

```text
3 // cantidad de servidores
15 // cota M
0 4 7 // kb enviados desde el servidor 1 al 1, 2 y 3, respectivamente
2 0 2
7 12 0
```

### Salida

```text
Correo (en kb) enviado por el servidor 1: 11
Correo (en kb) enviado por el servidor 2: 4
Correo (en kb) enviado por el servidor 3: 19

El servidor con más kb enviados es el 3

El servidor 2 recibió más de 15 kb de correo (16 kb).
```
