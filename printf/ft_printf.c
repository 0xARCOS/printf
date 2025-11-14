
#include <stdarg.h>
#include <unistd.h>

int ft_printf(char const *format, ...)
{
	va_list		args;
	int			caracteres_impresos;
	const char	*p;
	char		c_val;

	caracteres_impresos = 0;
	p = format;
	va_start(args, format); // <- Inicializa la lista, apuntando al argumento 'format';

	while (*p)
	{
		if (*p == '%')
		{
			p++; // Apunta al especificador (c, s, %, etc).
			if (*p == 'c')
			{
				c_val = (char)va_arg(args, int);
				write(1, &caracter_a_imprimir, 1);
				caracteres_impresos++;
				p++;
			}
			else if (*p == 's') // <-- string 
			{
				// Casos tocapelotas: si el puntero es NULL, hay que imprimir "(null)".
				caracter_a_imprimir = (char *)va_arg(args, char *);
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
			else if (*p == '%')
			{
				c_val = '%'
				write(1, &c_val, 1);
				caracteres_impresos++;
				p++;
			}
			else
				p++; // <-- Si no es ninguna de las anteriores lo ignoramos pero movemos el puntero.
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

