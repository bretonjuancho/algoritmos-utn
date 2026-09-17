# Cuenta Bancaria (TDA Cuenta)

## Enunciado

Un banco necesita manejar las cuentas de sus clientes y procesar los movimientos del día.

Cada cuenta tiene un saldo que solo se puede modificar con operaciones del TDA: depositar suma dinero y extraer resta dinero solo si hay saldo suficiente. Los movimientos sobre cuentas inexistentes o con datos inválidos se rechazan.

## TDA a definir

### `Cuenta`
Representa una cuenta bancaria. Contiene:

- `nro`: número de cuenta.
- `titular`: nombre del titular (sin espacios).
- `saldo`: saldo actual en `$`.

### Operaciones del TDA

- `int buscarCuenta(Cuenta v[], int n, int nro)`: devuelve la posición de la cuenta o `-1` si no existe.
- `bool depositar(Cuenta &c, float monto)`: suma `monto` si es mayor a 0.
- `bool extraer(Cuenta &c, float monto)`: resta `monto` solo si es mayor a 0 y hay saldo suficiente.
- `void mostrarCuenta(Cuenta c)`: muestra número, titular y saldo final.

## Requerimientos del programa

El programa debe:

1. **Leer `N`** (cantidad de cuentas, máximo 50) y luego, por cada cuenta: `nro`, `titular`, `saldo`.
2. **Leer `M`** (cantidad de movimientos) y luego, por cada movimiento: `nro`, `tipo` (`D` = depósito, `E` = extracción), `monto`.
3. **Procesar cada movimiento en orden:**
   - Si la cuenta no existe: mostrar `Movimiento rechazado: cuenta XXX no existe`.
   - Si el monto no es mayor a 0: mostrar `Movimiento rechazado: monto invalido`.
   - Si el tipo no es `D` ni `E`: mostrar `Movimiento rechazado: tipo invalido`.
   - Si es extracción sin saldo suficiente: mostrar `Movimiento rechazado: saldo insuficiente en cuenta XXX`.
   - En caso contrario, aplicar `depositar` o `extraer`.
4. **Mostrar el saldo final** de cada cuenta.
5. **Mostrar la cuenta con mayor saldo** y la **cantidad de movimientos rechazados**.

## Casos de prueba

> Orden de entrada: `N`, y por cada cuenta: `nro`, `titular`, `saldo`. Luego `M`, y por cada movimiento: `nro`, `tipo`, `monto`.

### Caso 1: Todo válido

**Entrada (lista para pegar):**
```
2
101
Ana
1000
102
Luis
500
3
101
D
200
102
E
100
101
E
50
```

**Salida esperada:**
```
Cuenta 101 (Ana) - Saldo: 1150.00
Cuenta 102 (Luis) - Saldo: 400.00
Mayor saldo: Ana (cuenta 101) con 1150.00
Movimientos rechazados: 0
```

### Caso 2: Rechazos (saldo insuficiente y cuenta inexistente)

**Entrada (lista para pegar):**
```
2
201
Marta
300
202
Pedro
1000
4
201
E
500
202
D
100
999
D
50
202
E
200
```

**Salida esperada:**
```
Movimiento rechazado: saldo insuficiente en cuenta 201
Movimiento rechazado: cuenta 999 no existe
Cuenta 201 (Marta) - Saldo: 300.00
Cuenta 202 (Pedro) - Saldo: 900.00
Mayor saldo: Pedro (cuenta 202) con 900.00
Movimientos rechazados: 2
```

### Caso 3: Una sola cuenta (caso mínimo)

**Entrada (lista para pegar):**
```
1
301
Sofia
100
2
301
D
50
301
E
30
```

**Salida esperada:**
```
Cuenta 301 (Sofia) - Saldo: 120.00
Mayor saldo: Sofia (cuenta 301) con 120.00
Movimientos rechazados: 0
```
