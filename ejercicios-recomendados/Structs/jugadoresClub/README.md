# Jugadores del club

## Enunciado

Un club de fútbol amateur necesita registrar la información de sus jugadores para analizar el rendimiento en la temporada.

Cada jugador posee datos personales y estadísticas de juego, y en base a eso se calculan promedios y se detectan los más destacados.

## Estructura a definir

### `Jugador`
Representa a un jugador del club. Contiene:

- Nombre del jugador.
- Edad.
- Cantidad de goles en la temporada.
- Cantidad de partidos jugados en la temporada.

## Requerimientos del programa

El programa debe:

1. **Leer la cantidad de jugadores `N`:**
   - `N` se ingresa por teclado.
   - Valor máximo: 50.

2. **Para cada uno de los `N` jugadores, leer:**
   - `nombre`.
   - `edad`.
   - `goles`.
   - `partidos`.

3. **Calcular y mostrar el promedio de gol de cada jugador** (`goles / partidos`). Si un jugador no jugó ningún partido (`partidos = 0`), su promedio es `0`.

4. **Determinar y mostrar al goleador** (el que hizo más goles) **y al jugador con mejor promedio** (con al menos 1 partido jugado). En caso de empate se muestra el primero encontrado.

5. **Listar los jugadores menores de 20 años**, indicando nombre y edad.

6. **Informar cuántos jugadores hicieron más de 10 goles y qué porcentaje representan** sobre el total.

## Casos de prueba

> Orden de entrada: `N`, y por cada jugador: `nombre`, `edad`, `goles`, `partidos`.

### Caso 1: Cinco jugadores

**Entrada (lista para pegar):**
```
5
Messi
36
30
25
Dibu
31
0
20
Julian
24
18
22
Garnacho
19
8
15
Paz
18
12
10
```

**Salida esperada:**
```
Messi -- Promedio de gol: 1.20
Dibu -- Promedio de gol: 0.00
Julian -- Promedio de gol: 0.82
Garnacho -- Promedio de gol: 0.53
Paz -- Promedio de gol: 1.20

Goleador: Messi (30 goles)
Mejor promedio: Messi (1.20)

Jugadores menores de 20 años:
Garnacho (19 años)
Paz (18 años)

Jugadores con mas de 10 goles: 3 (60.00% del plantel)
```

### Caso 2: Jugador sin partidos jugados

**Entrada (lista para pegar):**
```
3
Luna
21
5
5
Suplente
25
0
0
Pibe
17
2
4
```

**Salida esperada:**
```
Luna -- Promedio de gol: 1.00
Suplente -- Promedio de gol: 0.00
Pibe -- Promedio de gol: 0.50

Goleador: Luna (5 goles)
Mejor promedio: Luna (1.00)

Jugadores menores de 20 años:
Pibe (17 años)

Jugadores con mas de 10 goles: 0 (0.00% del plantel)
```
