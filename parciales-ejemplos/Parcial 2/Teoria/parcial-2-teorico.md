# 🧪 Parcial 2 · Parte teórica

**Algoritmos y Estructuras de Datos**

Comisión F · Cursado anual 2026

| ⏱️ Tiempo máximo | 🎯 Puntaje total | 🧩 Ítems |
| :--------------: | :-------------: | :-----: |
| **30 min** | **30 puntos** | **16** |

**Temas** · `Funciones` · `Recursividad` · `Arreglos` · `Búsqueda y ordenamiento`

> 💡 **Simulacro generado con IA.** Usalo para practicar; no es parámetro de lo que pueden tomar.

### Recorrido rápido

| [✅ 1 · Verdadero o falso](#1-verdadero-o-falso) | [🔘 2 · Selección múltiple](#2-selección-múltiple) | [✍️ 3 · Desarrollo](#3-desarrollo-breve) | [💻 4 · Análisis de código](#4-análisis-de-código) |
| :---: | :---: | :---: | :---: |

---

## 🗺️ Estructura del parcial

|  Parte  | Contenido          | Ítems | Puntos |  Tiempo  |
| :-----: | ------------------ | :---: | :----: | :------: |
| **1** | Verdadero o falso  | 6 | 6 | 5 min |
| **2** | Selección múltiple | 5 | 10 | 8 min |
| **3** | Desarrollo breve   | 3 | 6 | 6 min |
| **4** | Análisis de código | 2 | 8 | 8 min |
| — | **Total** | **16** | **30** | **≈ 27 min** |

### Mapa de contenidos

| Tema                               | Dónde se evalúa           |
| ---------------------------------- | ------------------------- |
| Funciones, prototipos y parámetros | V/F 1-2 · SM 1 · D 1      |
| Funciones recursivas               | V/F 3 · SM 2 · Análisis B |
| Arreglos unidimensionales          | V/F 4-6 · SM 3 · D 2      |
| Búsqueda secuencial y binaria      | SM 4 · D 3                |
| Mezcla y ordenamiento (BMO)        | SM 5 · Análisis A         |

---

## 🧭 Cómo resolver este simulacro

1. Cronometrá **30 minutos** y resolvé todo sin ayuda.
2. En **V/F** y **selección múltiple** justificá **siempre**: sin justificación no se otorga el puntaje.
3. Usá lápiz y papel para las trazas: **no hace falta compilador**.
4. Recién al terminar, desplegá el **solucionario** del final y corregí.

---

## ✅ 1. Verdadero o falso

> 🎯 **6 puntos** · ⏱️ aprox. 5 min

*Indicá **V** o **F** y justificá en una línea.*

**1.1** El prototipo de una función informa el tipo de retorno, el nombre y los tipos de sus parámetros, y termina con punto y coma.

**1.2** Cuando un parámetro se pasa por valor, la función recibe una copia: si lo modifica adentro, la variable usada en la llamada no cambia.

**1.3** Una función recursiva puede no tener caso base, siempre que en cada llamada reduzca el tamaño del problema.

**1.4** Al pasar un arreglo como argumento, la función recibe una copia de todos sus elementos; para modificarlo hay que pasarlo por referencia.

**1.5** Los índices de un arreglo en C++ van de `0` a `tamaño − 1`, y el compilador controla automáticamente que no se acceda fuera de ese rango.

**1.6** En `char palabra[20];` cada elemento ocupa 1 byte en memoria y el nombre del arreglo es la dirección de su primer elemento.

---

## 🔘 2. Selección múltiple

> 🎯 **10 puntos** · ⏱️ aprox. 8 min

*Marcá la única opción correcta y justificá en una línea.*

### 2.1 · Parámetros

¿Cuál de las siguientes afirmaciones es correcta?

- **a)** Los parámetros de entrada se pasan por referencia y los de salida por valor.
- **b)** Un parámetro de salida se declara con `&`, y el argumento correspondiente debe ser una variable.
- **c)** Un parámetro pasado por valor exige que el argumento sea una variable.
- **d)** Al declarar un parámetro por referencia como `const`, la función puede modificar su valor.

### 2.2 · Recursividad

Respecto de las funciones recursivas, ¿cuál afirmación es correcta?

- **a)** Siempre son más eficientes en tiempo y memoria que un ciclo equivalente.
- **b)** Se repiten mediante llamadas a sí mismas y terminan cuando alcanzan un caso base.
- **c)** No necesitan caso base si el parámetro disminuye en cada llamada.
- **d)** Sólo sirven para cálculos matemáticos; no se pueden usar con arreglos.

### 2.3 · Arreglos y memoria

Dado `double v[8];` que comienza en la dirección `2000` y sabiendo que cada `double` ocupa 8 bytes, ¿cuál es la dirección de `v[3]`?

- **a)** 2003
- **b)** 2016
- **c)** 2024
- **d)** 2032

### 2.4 · Búsqueda

Sobre la búsqueda binaria, ¿cuál afirmación es **verdadera**?

- **a)** Se puede aplicar sobre arreglos desordenados si no hay elementos repetidos.
- **b)** Requiere que el arreglo esté ordenado y en el peor caso realiza `log₂ N` comparaciones.
- **c)** Su peor caso es `N` comparaciones, igual que la búsqueda secuencial.
- **d)** Compara siempre todos los elementos, por eso es más segura.

### 2.5 · Ordenamiento

¿Cuál de las siguientes afirmaciones sobre los métodos de ordenamiento es correcta?

- **a)** La selección directa realiza la misma cantidad de pasadas aunque el arreglo ya esté ordenado.
- **b)** La burbuja con centinela siempre completa todas las pasadas posibles.
- **c)** La inserción directa empeora mucho cuando el arreglo está casi ordenado.
- **d)** Merge-Sort ordena sobre el mismo arreglo, sin usar memoria extra.

---

## ✍️ 3. Desarrollo breve

> 🎯 **6 puntos** · ⏱️ aprox. 6 min

*Respondé en no más de tres o cuatro renglones por pregunta.*

**3.1** Explicá la diferencia entre **función** y **procedimiento** en C++. Indicá qué tipo de retorno usa cada uno.

**3.2** Explicá la diferencia entre **tamaño físico** y **tamaño lógico** de un arreglo. ¿Qué valor debe usarse como límite en los recorridos?

**3.3** ¿Por qué la **búsqueda binaria** es más eficiente que la **secuencial**? ¿Qué condición exige el arreglo en cada caso?

---

## 💻 4. Análisis de código

### 🔎 A. Traza de ordenamiento

> 🎯 **4 puntos** · ⏱️ aprox. 4 min

**Código:**

```cpp
int v[5] = {4, 2, 6, 1, 3};

for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4 - i; j++) {
        if (v[j] > v[j + 1]) {
            int aux = v[j];
            v[j] = v[j + 1];
            v[j + 1] = aux;
        }
    }
}
```

- **a) (2 pts)** Mostrá el estado del arreglo al terminar la **primera pasada** del ciclo externo (`i = 0`).
- **b) (2 pts)** ¿Cómo se llama el método aplicado? ¿En qué se diferencia de su versión con **centinela**?

### 🔁 B. Función recursiva

> 🎯 **4 puntos** · ⏱️ aprox. 4 min

**Código:**

```cpp
int calcular(int n) {
    if (n < 10) {
        return n;
    }
    return (n % 10) + calcular(n / 10);
}
```

- **a) (1 pt)** ¿Cuál es el **caso base**?
- **b) (2 pts)** ¿Qué retorna `calcular(472)`? Mostrá el razonamiento.
- **c) (1 pt)** ¿Qué hace la función en términos generales?

---

## 📝 Hoja de respuestas

*Escribí `V`/`F` o la letra elegida en cada casilla.*

|           |  1.1  |  1.2  |  1.3  |  1.4  |  1.5  |  1.6  |
| :-------: | :---: | :---: | :---: | :---: | :---: | :---: |
| **V / F** |  ⬜   |  ⬜   |  ⬜   |  ⬜   |  ⬜   |  ⬜   |

|        |  2.1  |  2.2  |  2.3  |  2.4  |  2.5  |
| :----: | :---: | :---: | :---: | :---: | :---: |
| **SM** |  ⬜   |  ⬜   |  ⬜   |  ⬜   |  ⬜   |

---

<details>
<summary><strong>🔐 Solucionario · Abrilo recién cuando termines</strong></summary>

<br>

### ✅ 1. Verdadero o falso

|  #  | Resp. | Justificación |
| :-: | :---: | ------------- |
| 1.1 | **V** | El prototipo valida la función: nombre, tipo de retorno y tipos de los parámetros, y cierra con `;`. Sólo es obligatorio si la definición aparece después de la llamada. |
| 1.2 | **V** | El paso por valor envía una copia; lo que ocurre dentro de la función no afecta a la variable original. |
| 1.3 | **F** | Necesita al menos un **caso base** (solución directa) para que termine el camino de retorno. Sin él, la recursión es infinita y el programa falla al quedarse sin recursos. |
| 1.4 | **F** | Los arreglos se pasan **por dirección**: la función recibe la referencia al primer elemento y puede modificar el arreglo original sin copiarlo. |
| 1.5 | **F** | La primera parte es cierta (`0` a `tamaño − 1`), pero **C++ no comprueba los límites**: controlar los índices es responsabilidad del programador. |
| 1.6 | **V** | `char` ocupa 1 byte y el nombre del arreglo es la dirección de su primer elemento; los elementos quedan en posiciones contiguas de memoria. |

### 🔘 2. Selección múltiple

|  #  | Resp. | Justificación |
| :-: | :---: | ------------- |
| 2.1 | **b** | Los parámetros de **salida** se pasan por referencia (`&`) y exigen que el argumento sea una **variable**. La entrada se pasa por valor y admite variables, constantes o expresiones; `const` justamente impide modificar el parámetro. |
| 2.2 | **b** | La recursión se repite por llamadas a sí misma y termina al alcanzar el **caso base**. Consume memoria extra (no siempre es más eficiente) y también se usa con arreglos (promedios, conteos, picos). |
| 2.3 | **c** | `&v[i] = D + i * tamaño` → `2000 + 3 * 8 = 2024`. |
| 2.4 | **b** | La búsqueda binaria **requiere arreglo ordenado** y en el peor caso hace `log₂ N` comparaciones; la secuencial, `N`. |
| 2.5 | **a** | La selección directa hace el mismo número de pasadas esté o no ordenado. La burbuja con centinela corta si no hubo intercambios; la inserción mejora con datos casi ordenados (mejor caso `O(n)`); Merge-Sort **necesita espacio extra**. |

### ✍️ 3. Desarrollo breve

**3.1** Una **función** devuelve un valor mediante `return` y tiene un tipo de retorno (por ejemplo `int`). Un **procedimiento** es una función con retorno `void`: no devuelve valor, aunque puede producir efectos laterales (modificar parámetros por referencia o mostrar resultados por pantalla). En C++ ambos se definen igual y se distinguen por su tipo de retorno.

**3.2** El **tamaño físico** es la capacidad máxima declarada del arreglo (constante, por ejemplo 100). El **tamaño lógico** (real o actual) es la cantidad de datos realmente cargados y varía en tiempo de ejecución; nunca puede superar al físico. Los recorridos deben usar el **tamaño lógico**, porque las posiciones restantes no contienen datos válidos.

**3.3** La búsqueda binaria descarta la mitad del espacio de búsqueda en cada paso: peor caso `log₂ N` comparaciones, contra `N` de la secuencial. La binaria **exige que el arreglo esté ordenado**; la secuencial funciona sobre cualquier arreglo (ordenado o no).

### 💻 4. Análisis de código

#### 🔎 A. Traza de ordenamiento

**a)** Primera pasada (`i = 0`), comparando pares adyacentes:

|  j  | Comparación         | Arreglo           |
| :-: | ------------------- | ----------------- |
|  0  | 4 > 2 → intercambia | `{2, 4, 6, 1, 3}` |
|  1  | 4 > 6 → no          | `{2, 4, 6, 1, 3}` |
|  2  | 6 > 1 → intercambia | `{2, 4, 1, 6, 3}` |
|  3  | 6 > 3 → intercambia | `{2, 4, 1, 3, 6}` |

**Estado final de la pasada:** `{2, 4, 1, 3, 6}` (el mayor, 6, quedó "burbujeado" al final).

**b)** Es el **método de la burbuja**. La versión **con centinela** usa una marca para saber si hubo intercambios en la pasada y termina antes si el arreglo ya quedó ordenado (mejor caso `O(n)`); esta versión siempre realiza las `n − 1` pasadas.

#### 🔁 B. Función recursiva

**a)** El caso base es `n < 10`, donde retorna `n` directamente.

**b)** `calcular(472)` = 2 + `calcular(47)` = 2 + 7 + `calcular(4)` = 2 + 7 + 4 = **13**.

**c)** Suma los dígitos del número de forma recursiva.

</details>

---

## 🌱 Autoevaluación

|  Puntaje   | Nivel                                                       |
| :--------: | ----------------------------------------------------------- |
| **27 – 30** | 💎 Excelente, llegás muy bien al parcial                    |
| **20 – 26** | 👍 Buen trabajo, repasá los ítems fallados                  |
| **10 – 19** | 📖 A reforzar: volvé a las diapositivas de funciones, recursividad, arreglos y BMO |
|  **0 – 9**  | 🔁 Conviene rehacer el repaso completo antes del parcial    |

---

> 🧾 **Criterios de corrección:** se evalúa el uso correcto de los conceptos, la justificación de cada respuesta, la precisión en las trazas y la prolijidad.

## 📌 Registro del intento

Anotá el resultado y elegí qué repasar antes de volver a intentarlo.

| Fecha | Tiempo usado | Puntaje | Tema para repasar |
| :---: | :----------: | :-----: | ----------------- |
|       |              |   / 30  |                   |

**¡Muchos éxitos! 🍀**
