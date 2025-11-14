#include <stdio.h>
#include "ft_printf.h"

int ft_printf(char const *format, ...);

int main()
{
    int count_ft;
    int count_std;

    printf("--- PRUEBA DE ESTRUCTURA FT_PRINTF --- ");

    // Hacemos una llamada simple con un argumento variable (int) y una cadena fija
    count_ft = ft_printf("Este es un texto fijo. Probando ft_printf: %d\n", 42);
    // Usamos la printf original para mostrar el resultado esperado y el conteo de tu función
    count_std = printf("La ft_printf devolvio: %d (Deberia ser el total de caracteres impresos).\n", count_ft);

    return 0;
}