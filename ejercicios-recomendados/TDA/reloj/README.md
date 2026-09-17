# Reloj (TDA Hora)

## Enunciado

Se necesita un reloj que guarde una hora del día y permita adelantarla una cantidad de segundos.

La hora siempre debe mantenerse válida (de `00:00:00` a `23:59:59`). Si al adelantar se pasa de las `23:59:59`, vuelve a empezar desde `00:00:00`.

## TDA a definir

### `Hora`
Representa una hora del día. Contiene:

- `h`: hora (0 a 23).
- `m`: minutos (0 a 59).
- `s`: segundos (0 a 59).

### Operaciones del TDA

- `bool esValida(Hora t)`: indica si la hora es válida.
- `void mostrarHora(Hora t)`: muestra la hora en formato `HH:MM:SS`.
- `int aSegundos(Hora t)`: convierte la hora a segundos desde las `00:00:00`.
- `Hora desdeSegundos(int total)`: convierte segundos a `Hora` (con vuelta cada 24 h).
- `void sumarSegundos(Hora &t, int seg)`: adelanta la hora `seg` segundos.

## Requerimientos del programa

El programa debe:

1. **Leer la hora inicial:** `h`, `m`, `s` (cada valor en una línea).
2. **Validarla:** si es inválida, mostrar `Hora invalida` y terminar.
3. **Leer `seg`:** cantidad de segundos a adelantar (`seg >= 0`). Si es negativa, mostrar `Segundos invalidos` y terminar.
4. **Mostrar la hora inicial** en formato `HH:MM:SS`.
5. **Adelantar la hora** con `sumarSegundos` y **mostrar la hora final**.
6. **Informar si cruzó la medianoche** (`Si` / `No`).

## Casos de prueba

> Orden de entrada: `h`, `m`, `s`, `seg` (cada valor en una línea).

### Caso 1: Adelanto normal

**Entrada (lista para pegar):**
```
10
30
0
3600
```

**Salida esperada:**
```
Hora inicial: 10:30:00
Hora final: 11:30:00
Cruzo la medianoche: No
```

### Caso 2: Cruza la medianoche

**Entrada (lista para pegar):**
```
23
50
0
1200
```

**Salida esperada:**
```
Hora inicial: 23:50:00
Hora final: 00:10:00
Cruzo la medianoche: Si
```

### Caso 3: Hora inválida

**Entrada (lista para pegar):**
```
25
10
0
```

**Salida esperada:**
```
Hora invalida
```
