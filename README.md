<div align="center">
    <img src="https://github.com/15Galan/42_project-readmes/blob/master/banners/cursus/projects/ft_printf-light.png#gh-light-mode-only" alt="Banner claro" />
    <img src="https://github.com/15Galan/42_project-readmes/blob/master/banners/cursus/projects/ft_printf-dark.png#gh-dark-mode-only" alt="Banner oscuro" />
    <a href='https://profile.intra.42.fr/users/aarcos' target="_blank">
        <img alt='42 Madrid' src='https://img.shields.io/badge/Madrid-black?style=flat&logo=42&logoColor=white'/>
    </a>
    <img src="https://img.shields.io/badge/puntuación-💯%2F100-success?color=%2312bab9&style=flat" />
    <img src="https://api.visitorbadge.io/api/visitors?user=0xARCOS&repo=ft_printf&label=visitas&countColor=%2385e3ff&style=flat&labelStyle=none"/>
</div>

---

# ft_printf

> Reimplementación personalizada de `printf`, una de las funciones más utilizadas del lenguaje C. Este proyecto del currículo de la 42 School pone a prueba tu conocimiento sobre parsing, tipos de datos, memoria y recursividad.

---

## 📦 Descripción

Este proyecto recrea la función estándar `printf` de C, permitiendo imprimir texto con formato desde cero, utilizando únicamente funciones permitidas (`write`, etc.). Se analizan los especificadores de formato y se procesan los argumentos con punteros y listas variables (`va_list`).

---

## 📁 Estructura del Proyecto

```
ft_printf/
├── ft_printf.h       # Header con prototipos y macros
├── ft_printf.c       # Lógica principal de parsing
├── ft_utils.c        # Funciones auxiliares (itoa, strlen, etc.)
├── ft_print_types.c  # Impresión según tipo (char, str, int, hex, ptr)
```

---

## ⚙️ Compilación

```bash
make
```

También puedes compilar directamente con:

```bash
cc -Wall -Wextra -Werror *.c -o ft_printf
```

---

## 🧠 Uso Básico

```c
ft_printf("Hola %s! Tu nota es %d/100.\n", "Ariel", 100);
```

🔸 Salida esperada:
```
Hola Ariel! Tu nota es 100/100.
```

---

## 📑 Especificadores Soportados

| Formato | Descripción           |
|---------|------------------------|
| `%c`    | Carácter               |
| `%s`    | String (cadena)        |
| `%d`    | Entero decimal (signed)|
| `%i`    | Entero decimal (signed)|
| `%u`    | Unsigned decimal       |
| `%x`    | Hexadecimal (minúsculas) |
| `%X`    | Hexadecimal (MAYÚSCULAS) |
| `%p`    | Puntero (dirección)    |
| `%%`    | Imprime el carácter %  |

---

## 💡 Detalles Técnicos

- Usa `va_list` para manejar argumentos variables
- Cada especificador es analizado y resuelto por funciones independientes
- Conversión numérica sin usar funciones estándar (ej. `itoa`)
- Sin uso de `malloc` salvo en representaciones string

---

## 🧑‍💻 Autor

**Ariel (0xARCOS)**  
📍 Campus 42 Madrid  
🔗 [GitHub](https://github.com/0xARCOS)

---

## 📜 Licencia

Este proyecto es parte del aprendizaje en 42 y puede reutilizarse con fines académicos o personales.  
¡Estás invitado a clonar, estudiar o contribuir! ⭐

---
