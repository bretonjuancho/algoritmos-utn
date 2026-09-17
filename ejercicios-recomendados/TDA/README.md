# 📚 TDA — Ejercicios recomendados

<div align="center">

Ejercicios prácticos para entrenar **TDA** (Tipo de Dato Abstracto: `struct` + operaciones).

</div>

---

## 📖 El tema en breve

Un TDA agrupa los datos en un `struct` y solo los modifica a través de sus operaciones (funciones y procedimientos con pasaje por referencia).

Los patrones que se entrenan en estos ejercicios son:

- Definición del `struct` y sus operaciones (`esValida`, `mostrar`, `buscar`, `depositar`, `extraer`).
- Validación de datos dentro del TDA (hora válida, monto mayor a 0, saldo suficiente).
- Modificación del estado por referencia (`Hora &`, `Cuenta &`).
- Conversiones internas (hora a segundos y viceversa) y búsqueda en vectores de TDA.

---

## 📋 Ejercicios propuestos

| # | Ejercicio | Descripción | Dificultad |
|---|-----------|-------------|------------|
| 1 | [Reloj (TDA Hora)](./reloj/) | Struct `Hora` (h, m, s). Validar, mostrar en `HH:MM:SS`, adelantar N segundos y detectar cruce de medianoche. | ⭐ Baja |
| 2 | [Cuenta bancaria (TDA Cuenta)](./cuentaBancaria/) | Struct `Cuenta` (nro, titular, saldo). Depósitos, extracciones con validación, movimientos rechazados y mayor saldo. | ⭐⭐ Media |

---

## Recomendaciones

- Intentá resolver cada ejercicio y comparar tu salida con los casos de prueba.
- Respetá el TDA: el `main` no debe tocar los campos directamente para modificarlos, solo a través de las operaciones.
- Probá tu solución con casos borde (hora `23:59:59` + 1 segundo, extracción exacta del saldo, cuenta inexistente, monto cero o negativo).
- Orden sugerido por dificultad: reloj → cuenta bancaria.
