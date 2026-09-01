# Empleados de una empresa

## Enunciado

Crear una estructura `Empleado` que contenga la siguiente información:

- **Nombre**.
- **Dirección**: calle, número y barrio. Algunos barrios posibles son `María Selva`, `Candioti` y `Sur`.
- **Fecha de nacimiento**: día, mes y año.
- **Sexo**: `M` para masculino o `F` para femenino.
- **Sueldo**.
- **Categoría**: `Operario`, `Jefe de área` o `Gerente`.
- **Fecha de ingreso**: día, mes y año.

Utilizando esta estructura, declarar un vector de 100 elementos para administrar los empleados de una empresa.

Para la carga utilizando `cin >>`, considerar que la primera línea indica la cantidad de empleados y que cada línea siguiente contiene los campos separados por espacios, en este orden. Cada campo debe ser una sola palabra, ya que `cin >>` finaliza la lectura al encontrar un espacio.

Para los valores que normalmente contienen espacios, utilizar una única palabra: `MariaSelva` para el barrio María Selva y `JefeDeArea` para la categoría Jefe de área. Los nombres y las calles también deben ingresarse sin espacios, por ejemplo `AnaPerez` y `SanMartin`.

```text
nombre calle número barrio día mes año sexo sueldo categoría día mes año
```

Luego:

1. Imprimir el nombre, dirección, sueldo y categoría del cuarto empleado.
2. Imprimir los nombres de todos los empleados que tienen un sueldo mayor a `$57.500`.
3. Aumentar un 15 % el sueldo de los empleados con una antigüedad mayor a 5 años.
4. Listar los empleados menores de 25 años.
5. Listar los empleados que viven en el barrio `Sur`.
6. Listar los operarios que viven en el barrio `Candioti`.
7. Listar el vector ordenado por nombre.

Para calcular la edad y la antigüedad, utilizar como fecha de referencia el `01/01/2025`.

## Ejemplo

### Entrada

```text
6
AnaPerez San Martin 123 Sur 10 5 2000 F 60000 Operario 15 2 2018
BrunoDiaz Urquiza 456 Candioti 20 11 1995 M 70000 JefeDeArea 1 6 2021
CarlaGomez Belgrano 789 Sur 3 8 2002 F 55000 Gerente 10 1 2019
DiegoLopez Rivadavia 101 Candioti 12 12 1990 M 80000 Operario 5 3 2015
ElenaRuiz Colon 202 MariaSelva 22 7 2001 F 58000 Operario 20 8 2020
FacundoSilva Alberdi 303 Sur 1 1 1999 M 50000 Gerente 11 11 2017
```

### Salida

```text
Cuarto empleado: DiegoLopez
Dirección: Rivadavia 101
Sueldo: 80000
Categoría: Operario

Empleados con sueldo mayor a $57.500:
AnaPerez
BrunoDiaz
DiegoLopez
ElenaRuiz

Sueldos actualizados por antigüedad mayor a 5 años:
AnaPerez: $69.000
CarlaGomez: $63.250
DiegoLopez: $92.000
FacundoSilva: $57.500

Empleados menores de 25 años:
AnaPerez
CarlaGomez
ElenaRuiz

Empleados del barrio Sur:
AnaPerez
CarlaGomez
FacundoSilva

Operarios del barrio Candioti:
DiegoLopez

Empleados ordenados por nombre:
AnaPerez
BrunoDiaz
CarlaGomez
DiegoLopez
ElenaRuiz
FacundoSilva
```
