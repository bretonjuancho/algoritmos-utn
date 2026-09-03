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

Utilizando esta estructura, declarar un vector de 0 < N <= 100 elementos para administrar los empleados de una empresa.

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

## Ejemplos

### Entrada

```text
6
AnaPerez SanMartin 123 Sur 10 5 2000 F 60000 Operario 15 2 2018
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

### Entrada

```text
15
OlgaQuintero Mendoza 333 Sur 9 2 1990 F 75000 Gerente 3 3 2010
JuanParedes Rioja 707 Candioti 5 3 1998 M 59000 Operario 1 1 2019
AnaPerez SanMartin 123 Sur 10 5 2000 F 60000 Operario 15 2 2018
MartaSosa Tucuman 111 Candioti 7 7 2005 F 66000 JefeDeArea 12 12 2024
LuisRamirez Salta 909 Sur 25 4 1992 M 48000 Operario 10 10 2023
CarlaGomez Belgrano 789 Sur 3 8 2002 F 55000 Gerente 10 1 2019
DiegoLopez Rivadavia 101 Candioti 12 12 1990 M 80000 Operario 5 3 2015
KarinaMendez Jujuy 808 MariaSelva 18 9 2001 F 61000 Gerente 20 4 2016
BrunoDiaz Urquiza 456 Candioti 20 11 1995 M 70000 JefeDeArea 1 6 2021
IreneCastro Guemes 606 Sur 30 12 2004 F 54000 Operario 15 5 2022
NicolasFunes Cordoba 222 MariaSelva 1 1 2000 M 53000 Operario 2 1 2018
ElenaRuiz Colon 202 MariaSelva 22 7 2001 F 58000 Operario 20 8 2020
HugoVargas Sarmiento 505 MariaSelva 15 6 2003 M 62000 JefeDeArea 31 12 2019
GabrielaTorres Mitre 404 Candioti 2 1 2000 F 57500 Operario 1 1 2020
FacundoSilva Alberdi 303 Sur 1 1 1999 M 50000 Gerente 11 11 2017
```

### Salida

```text
Cuarto empleado: MartaSosa
Dirección: Tucuman 111
Sueldo: 66000
Categoría: JefeDeArea

Empleados con sueldo mayor a $57.500:
OlgaQuintero
JuanParedes
AnaPerez
MartaSosa
DiegoLopez
KarinaMendez
BrunoDiaz
ElenaRuiz
HugoVargas

Sueldos actualizados por antigüedad mayor a 5 años:
OlgaQuintero: $86250
JuanParedes: $67850
AnaPerez: $69000
CarlaGomez: $63250
DiegoLopez: $92000
KarinaMendez: $70150
NicolasFunes: $60950
ElenaRuiz: $66700
HugoVargas: $71300
GabrielaTorres: $66125
FacundoSilva: $57500

Empleados menores de 25 años:
MartaSosa 
CarlaGomez 
IreneCastro 
HugoVargas

Empleados del barrio Sur:
OlgaQuintero
AnaPerez
LuisRamirez
CarlaGomez
IreneCastro
FacundoSilva

Operarios del barrio Candioti:
JuanParedes 
MartaSosa 
DiegoLopez 
BrunoDiaz 
GabrielaTorres

Empleados ordenados por nombre:
AnaPerez
BrunoDiaz
CarlaGomez
DiegoLopez
ElenaRuiz
FacundoSilva
GabrielaTorres
HugoVargas
IreneCastro
JuanParedes
KarinaMendez
LuisRamirez
MartaSosa
NicolasFunes
OlgaQuintero
```
