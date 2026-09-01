# Ciudadanos – Intención de voto

Definir la estructura `Ciudadano`, almacenando en la propiedad `voto` la intención de voto para las elecciones estudiantiles 2020. Los valores posibles son:

- `'R'`: ROJO
- `'A'`: AZUL

En base a un censo de 1000 ciudadanos, determinar cuál es el porcentaje de intención de voto para cada uno de los partidos, de acuerdo al rango:

- Entre 18 y 40 años
- Entre 41 y 60 años
- Más de 60 años

## Caso de prueba

Entrada:

```
20
Ana 25 R
Beto 35 A
Carla 30 R
Diego 22 A
Elena 40 R
Fabio 50 R
Gloria 45 A
Hector 60 R
Isabel 41 A
Javier 55 A
Lucia 65 R
Marcos 70 A
Nora 61 A
Oscar 80 R
Paula 66 A
Quintin 28 A
Rosa 33 R
Sofia 52 A
Tomas 47 R
Ulises 75 R
```

Salida esperada:

```
Entre 18 y 40 años:
Porcentaje rojos: 57.1429%
Porcentaje azules: 42.8571%

Entre 41 y 60 años:
Porcentaje rojos: 42.8571%
Porcentaje azules: 57.1429%

Más de 60 años:
Porcentaje rojos: 50%
Porcentaje azules: 50%
```

| Rango        | Rojos | Azules | % Rojos | % Azules |
|--------------|-------|--------|---------|----------|
| 18 a 40      | 4     | 3      | 57.14%  | 42.86%   |
| 41 a 60      | 3     | 4      | 42.86%  | 57.14%   |
| Más de 60    | 3     | 3      | 50%     | 50%      |
