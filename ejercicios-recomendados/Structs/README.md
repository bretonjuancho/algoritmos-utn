# 📚 Structs — Ejercicios recomendados

<div align="center">

Ejercicios prácticos para entrenar **Structs** (estructuras, anidadas y vectores de structs).

</div>

---

## 📖 El tema en breve

Un `struct` agrupa datos relacionados bajo un mismo tipo, accediendo a cada campo con `variable.campo` (y `variable.substruct.campo` si hay anidamiento).

Los patrones que se entrenan en estos ejercicios son:

- Definición de structs simples y anidadas (`Fecha`, `Direccion`, `Materia`, `Zona`).
- Vectores de structs con carga por teclado y recorridos con acumuladores.
- Cálculos derivados (promedios, totales, porcentajes) y funciones auxiliares.
- Máximos/mínimos, filtros por condición y agrupado por categoría/zona.
- Ordenamiento de structs (burbujeo) por campo numérico o alfabético.

---

## 📋 Ejercicios resueltos

| # | Ejercicio | Descripción | Dificultad |
|---|-----------|-------------|------------|
| 1 | [Inventario de kiosco](./inventarioKiosco/) | Struct `Producto` (código, nombre, precio, stock). Valor en stock por producto y total, más caro/barato, stock menor a 5 y orden por precio. | ⭐ Baja |
| 2 | [Jugadores del club](./jugadoresClub/) | Struct `Jugador` (nombre, edad, goles, partidos). Promedio de gol, goleador y mejor promedio, menores de 20 y porcentaje con más de 10 goles. | ⭐ Baja |
| 3 | [Registro de estudiantes](./estudiantes/) | Structs anidadas `Materia` / `Estudiante` (legajo, nombre, 3 materias). Promedio por estudiante y mejor promedio. | ⭐ Baja |
| 4 | [Ciudadanos – Intención de voto](./ciudadanosVoto/) | Struct `Ciudadano` (nombre, edad, voto `R`/`A`). Porcentaje de voto por rango etario (18-40, 41-60, más de 60). | ⭐ Baja |
| 5 | [Empleados de una empresa](./empleados/) | Structs anidadas `Fecha` / `Direccion` / `Empleado`. Filtros por sueldo, edad y barrio, aumento por antigüedad y orden por nombre. | ⭐⭐ Media |
| 6 | [Ventas por vendedor](./ventasVendedores/) | Structs anidadas `Zona` / `Vendedor` con arreglo de 4 ventas semanales. Total por vendedor y general, mejor vendedor, zona top, semanas en cero y ranking. | ⭐⭐ Media |
| 7 | [Alquiler de autos](./alquilerAutos/) | Dos lotes: autos (código, categoría, precio por km) y alquileres del mes. Facturación por cliente con ranking, autos sin alquilar, clientes frecuentes, categoría top y mayor recaudación. | ⭐⭐ Media |

---

## Recomendaciones

- Intentá resolver primero cada ejercicio sin mirar las soluciones.
- Probá tu solución con casos borde (un solo elemento, empates en el máximo, valores en cero, struct sin ventas/préstamos).
- Orden sugerido por dificultad: kiosco → jugadores → estudiantes → ciudadanos → empleados → ventas → alquiler.
