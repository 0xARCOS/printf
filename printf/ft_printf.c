
#include "ft_printf.h"

int ft_printf(char const *format, ...)
{
	va_list		args;
	int			caracteres_impresos;
	const char	*p;
	//--------------------------------//
	char		c_val;					// <-- Para format '%c'
	//--------------------------------//
	char 		*s_val; char	*tmp_s; // <-- Para format '%s'
	//--------------------------------//
	long int	i_val; int		sign; char		buffer[20]; int		i; int		j; // <--- Para format '%d/%i'
	//--------------------------------//

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
				write(1, &c_val, 1);
				caracteres_impresos++;
				p++;
			}
			else if (*p == 's') // <-- string 
			{
				// Casos tocapelotas: si el puntero es NULL, hay que imprimir "(null)".
				s_val = va_arg(args, char *);
				if (s_val == NULL)
				{
					write(1, '(null)', 6);
					caracteres_impresos += 6;
				}
				else
				{
					tmp_s = s_val;
					while (*tmp_s != '\0')
					{
						write(1, tmp_s, 1);
						caracteres_impresos++;
						tmp_s++;
					}

				}
				p++;
			}
			else if (*p == 'p') // <-- puntero (hex con prefijo 0x)
			{
				// Caso tocapelotiñas: (nil) si el puntero es NULL
				write(1, &..., 1);
				caracteres_impresos++;
				p++;
				
			}
			else if (*p == 'd' || *p == 'i')
			{
				long n; // <- evita problemas con INT_MIN
				int i = 0;
				int j;

				n = va_arg(args, int);

				// Signo
				if (n < 0)
				{
					write(1, "-", 1);
					caracteres_impresos++;
					n = -n;
				}

				// Caso especial: n == 0
				if (n == 0)
				{
					write(1, "0", 1);
					caracteres_impresos++;
					p++;
					//continue;
				}

					// Construcción del número en buffer (al revés)
				while (n > 0)
				{
					buffer[i++] = (n % 10) + '0';
					n /= 10;
				}
				buffer[i] = '\0';

				// Inversión del buffer usando i y j
				j = 0;
				i = i - 1;
				while (j < i)
				{
					char temp = buffer[j];
					buffer[j] = buffer[i];
					buffer[i] = temp;
					j++;
					i--;
				}

					// Impresión final
				j = 0;
				while (buffer[j])
				{
					write(1, &buffer[j], 1);
					caracteres_impresos++;
					j++;
				}

				p++; // <-- CAMBIAR TODA ESTA HUEVADA POR UN PUTNBR...
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
				c_val = '%';
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

