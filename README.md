<div align="center">
    <img src="https://github.com/15Galan/42_project-readmes/blob/master/banners/cursus/projects/ft_printf-light.png#gh-light-mode-only" alt="Banner (claro)" />
    <img src="https://github.com/15Galan/42_project-readmes/blob/master/banners/cursus/projects/ft_printf-dark.png#gh-dark-mode-only" alt="Banner (oscuro)" />
    <a href='https://profile.intra.42.fr/users/aarcos' target="_blank">
        <img alt='42 (oscuro)' src='https://img.shields.io/badge/Madrid-black?style=flat&logo=42&logoColor=white'/>
    </a>
    <img src="https://img.shields.io/badge/puntuación---%20%2F%20100-success?color=%2312bab9&style=flat" />
    <img src="https://api.visitorbadge.io/api/visitors?user=V1nt3r4&repo=42_cursus_printf&label=visitas&countColor=%2385e3ff&style=flat&labelStyle=none"/>
</div>

---

Este es un proyecto de la escuela 42 que consiste en recrear la función `printf` de la biblioteca estándar de C.

## Descripción

El objetivo de este proyecto es implementar una versión propia de `printf`, manejando diferentes tipos de formatos y argumentos de manera eficiente y siguiendo las normas de codificación de 42School.

## ¿Cómo funciona?

El proyecto `ft_printf` procesa una cadena de formato y reemplaza los marcadores de posición con los valores correspondientes. Internamente, divide la cadena en fragmentos, analiza los especificadores de formato y maneja la conversión y salida de los datos utilizando `write`. 

Cada especificador es detectado y tratado de manera específica, asegurando la correcta impresión del valor pasado como argumento. Se utilizan buffers para mejorar la eficiencia en la escritura y minimizar las llamadas al sistema.

## Funcionalidades

- Soporte para los siguientes especificadores de formato:
  - `%c` → Caracter
  - `%s` → Cadena de caracteres
  - `%p` → Puntero en hexadecimal
  - `%d` / `%i` → Entero decimal con signo
  - `%u` → Entero decimal sin signo
  - `%x` / `%X` → Número hexadecimal en minúsculas/mayúsculas
  - `%%` → Imprime el símbolo `%`

## Instalación y Uso

Para compilar y probar el proyecto, usa el siguiente comando en tu terminal:

```sh
make
```

Luego, puedes incluir la librería en tu código de la siguiente manera:

```c
#include "ft_printf.h"

int main() {
    ft_printf("Hola, %s!\n", "mundo");
    return 0;
}
```

Compila el código con:

```sh
gcc main.c libftprintf.a -o test
./test
```

## Normas de Codificación

- Código desarrollado siguiendo la norma de 42School.
- No se permite el uso de funciones externas salvo `write`.
- Se deben manejar errores adecuadamente.
