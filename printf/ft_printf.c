
#include <stdarg.h>
#include <unistd.h>

int ft_printf(char const *format, ...)
{
	va_list args;
	int caracteres_impresos;
	
	caracteres_impresos = 0;
	va_start(args, format); // <- Inicializa la lista, apuntando al argumento 'format';
	const char *p;
	p = format;

	while (*p)
	{
		if (*p == '%')
		{
			// Caso 1: Es el inicio de una conversión!
			// incrementa 'p' para pasar al siguiente caracter (la especificación).
			p++;
			if (*p == 'c')
			{
				char caracter_a_imprimir = (char)va_arg(args, int);
				write(1, &caracter_a_imprimir, 1);
				caracteres_impresos++;
				p++;
			}
			else if (*p == 's') // <-- string 
			{
				// Casos tocapelotas: si el puntero es NULL, hay que imprimir "(null)".
				char caracter_a_imprimir = (char *)va_arg(args, char *);
				write(1, &caracter_a_imprimir, 1);
				caracteres_impresos++;
				p++;
			}
			else if (*p == 'p') // <-- puntero (hex con prefijo 0x)
			{
				// Caso tocapelotiñas: (nil) si el puntero es NULL
				write(1, &..., 1);
				caracteres_impresos++;
				p++;
				
			}
			else if ((*p == 'd') || (*p == 'i')) // <- Entero decimal con signo
			{
				// Cuidadín con INT_MIN (-214783648), úsalo como long antes de operar
				write(1, &..., 1);
				caracteres_impresos++;
				p++;
			}
			else if (*p == 'u') // <-- entero decimal sin signo.
			{
				// La conversión es igual que d pero sin signo.
				write(1, &..., 1);
				caracteres_impresos++;
				p++;
			}
			else if (*p == 'x') // <- Hexadecimal minus
			{
				// Aquí la clave está en la tabla "0123456789abcdef".
				write(1, &..., 1);
				caracteres_impresos++;
				p++;
			}
			else if (*p == 'X') // <-- Hexadecimal mayus
			{
				// tabla "0123456789ABCDEF".
				write(1, &..., 1);
				caracteres_impresos++;
				p++;
			}
		}
		else
		{
			// Caso 2: Es un carácter normal, imprímelo.
			write(1, p, 1);
			caracteres_impresos++;
			p++;
		}
		// No nos olvidemos de mover el puntero p al siguiente carácter al final del ciclo (si no se movió en el caso 1).
	}

	va_end(args);
	return (caracteres_impresos);
}

