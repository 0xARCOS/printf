
// #include "ft_printf.h"

// int ft_printf(char const* format, ...)
// {
//   va_list args;
//   int caracteres_impresos;
//   const char* p;
//   //---------------------------------------------//
//   char c_val;			// Para format '%c'
//   //---------------------------------------------//
//   char* s_val;			// Para formato '%s'
//   char* tmp_s; 
//   //---------------------------------------------//
//   long int i_val;		// Para formato %d / %i
//   int sign;
//   char buffer[20];
//   int i;
//   int j;
//   //---------------------------------------------//
//   unsigned long int u_val;	// para format '%u'
//   //---------------------------------------------//
//   unsigned long int Xx_val; // para format '%Xx'
//   char *HEX_MIN = "0123456789abcdef";
//   char *HEX_MAYUS = "0123456789ABCDEF";
//   //---------------------------------------------//
//   void *ptr;				// Para format '%p'
//   unsigned long p_val;
//   //---------------------------------------------//


//   caracteres_impresos = 0;
//   p = format;
//   va_start(args,
//            format); // <- Inicializa la lista, apuntando al argumento 'format';

//   while (*p)
//   {
//     if (*p == '%')
//     {
//       p++; // Apunta al especificador (c, s, %, etc).
//       if (*p == 'c')
//       {
//         c_val = (char)va_arg(args, int);
//         write(1, &c_val, 1);
//         caracteres_impresos++;
//         p++;
//       }
//       else if (*p == 's') // <-- string
//       {
//         // Casos tocapelotas: si el puntero es NULL, hay que imprimir "(null)".
//         s_val = va_arg(args, char*);
//         if (s_val == NULL)
//         {
//           write(1, '(null)', 6);
//           caracteres_impresos += 6;
//         }
//         else
//         {
//           tmp_s = s_val;
//           while (*tmp_s != '\0')
//           {
//             write(1, tmp_s, 1);
//             caracteres_impresos++;
//             tmp_s++;
//           }
//         }
//         p++;
//       }
//       else if (*p == 'd' || *p == 'i')
//       {
//         long i_val; // <- evita problemas con INT_MIN
//         int i = 0;
//         int j;

//         i_val = va_arg(args, int);

//         // Signo
//         if (i_val < 0)
//         {
//           write(1, "-", 1);
//           caracteres_impresos++;
//           i_val = -i_val;
//         }

//         // Caso especial: i_val == 0
//         if (i_val == 0)
//         {
//           write(1, "0", 1);
//           caracteres_impresos++;
//           p++;
//           // continue;
//         }

//         // Construcción del número en buffer (al revés)
//         while (i_val > 0)
//         {
//           buffer[i++] = (i_val % 10) + '0';
//           i_val /= 10;
//         }
//         buffer[i] = '\0';

//         // Inversión del buffer usando i y j
//         j = 0;
//         i = i - 1;
//         while (j < i)
//         {
//           char temp = buffer[j];
//           buffer[j] = buffer[i];
//           buffer[i] = temp;
//           j++;
//           i--;
//         }

//         // Impresión final
//         j = 0;
//         while (buffer[j])
//         {
//           write(1, &buffer[j], 1);
//           caracteres_impresos++;
//           j++;
//         }

//         p++; // <-- CAMBIAR TODA ESTA HUEVADA POR UN PUTNBR...
//       }
//       else if (*p == 'u') // <-- entero decimal sin signo.
//       {
//         i = 0;
//         u_val = va_arg(args, unsigned int);

//         // Caso especial: i_val == 0
//         if (u_val == 0)
//         {
//           write(1, "0", 1);
//           caracteres_impresos++;
//           p++;
//           // continue;
//         }

//         // Construcción del número en buffer (al revés)
//         while (u_val > 0)
//         {
//           buffer[i++] = (u_val % 10) + '0';
//           u_val /= 10;
//         }
//         buffer[i] = '\0';

//         // Inversión del buffer usando i y j
//         j = 0;
//         i = i - 1;
//         while (j < i)
//         {
//           char temp = buffer[j];
//           buffer[j] = buffer[i];
//           buffer[i] = temp;
//           j++;
//           i--;
//         }

//         // Impresión final
//         j = 0;
//         while (buffer[j])
//         {
//           write(1, &buffer[j], 1);
//           caracteres_impresos++;
//           j++;
//         }

//         p++;
// 	   }
// 	   else if (*p == 'X') // <-- Hexadecimal mayus
// 	   {
// 	     i = 0;
// 	     Xx_val = va_arg(args, unsigned int);
	  
// 	    if (Xx_val == 0)
// 	    {
// 		  write(1, "0", 1);
// 		  caracteres_impresos++;
// 		  p++;
// 		// continue;
// 	    }
// 	  // Construcción del número en buffer (al revés)
// 	  while (Xx_val > 0)
// 	  {
// 		buffer[i++] = HEX_MAYUS[Xx_val % 16];
// 		Xx_val /= 16;
// 	  }
// 	  buffer[i] = '\0';
// 	  // Inversión del buffer usando i y j
// 	  j = 0;
// 	  i = i - 1;
// 	  while (j < i)
// 	  {
// 		char temp = buffer[j];
// 		buffer[j] = buffer[i];
// 		buffer[i] = temp;
// 		j++;
// 		i--;
// 	  }
// 	  // Impresión final
// 	  j = 0;
// 	  while (buffer[j])
// 	  {
// 		write(1, &buffer[j], 1);
// 		caracteres_impresos++;
// 		j++;
// 	  }
// 	  p++;
// 	  }
//       else if (*p == 'x') // <- Hexadecimal minus
//       {
// 		i = 0;
// 		Xx_val = va_arg(args, unsigned int);
		
//         if (Xx_val == 0)
//         {
//           write(1, "0", 1);
//           caracteres_impresos++;
//           p++;
//           // continue;
//         }
// 		// Construcción del número en buffer (al revés)
//         while (Xx_val > 0)
//         {
//           buffer[i++] = HEX_MIN[Xx_val % 16];
//           Xx_val /= 16;
//         }
//         buffer[i] = '\0';
// 		// Inversión del buffer usando i y j
//         j = 0;
//         i = i - 1;
//         while (j < i)
//         {
//           char temp = buffer[j];
//           buffer[j] = buffer[i];
//           buffer[i] = temp;
//           j++;
//           i--;
//         }
//         // Impresión final
//         j = 0;
//         while (buffer[j])
//         {
//           write(1, &buffer[j], 1);
//           caracteres_impresos++;
//           j++;
//         }
//         p++;
//       }
// 	  else if (*p == 'p') // <-- puntero (hex con prefijo 0x)
// 	  {
// 		ptr = va_arg(args, void *);
// 		p_val = (unsigned long)ptr;

// 		write(1, "0x", 2);
// 		caracteres_impresos += 2;

// 		if (p_val == 0)
// 		{
// 			write(1, "0", 1);
// 			caracteres_impresos++;
// 			p++;
// 			// continue;
// 		}

// 		while (p_val > 0)
// 		{
// 			buffer[i++] = "0123456789abcdef"[p_val % 16];
//         	p_val /= 16;
// 		}
// 		buffer[i] = '\0';

// 		j = 0;
//     	i = i - 1;
//     	while (j < i)
//     	{
//         	char temp = buffer[j];
//         	buffer[j] = buffer[i];
//         	buffer[i] = temp;
//        		j++;
//         	i--;
//     	}

//     	// 6. Impresión final del buffer
//     	j = 0;
//     	while (buffer[j])
//     	{
//         	write(1, &buffer[j], 1);
//         	caracteres_impresos++;
//         	j++;
//     	}

//     	p++;
// 		}
// 		else if (*p == '%')
// 		{
// 			c_val = '%';
// 			write(1, &c_val, 1);
// 			caracteres_impresos++;
// 			p++;
// 		}
//       	else
//         	p++; // <-- Si no es ninguna de las anteriores lo ignoramos pero movemos
//             	 // el puntero.
//     }
// 	else 
// 	{
//       // Caso 2: Es un carácter normal, imprímelo.
//       write(1, p, 1);
//       caracteres_impresos++;
//       p++;
//     }
//     // No nos olvidemos de mover el puntero p al siguiente carácter al final del
//     // ciclo (si no se movió en el caso 1).
//   }

//   va_end(args);
//   return (caracteres_impresos);
// }


#include "ft_printf.h"

int ft_printf(char const* format, ...)
{
  va_list args;
  int caracteres_impresos;
  const char* p;
  //---------------------------------------------//
  char c_val;			// Para format '%c'
  //---------------------------------------------//
  char* s_val;			// Para formato '%s'
  char* tmp_s; 
  //---------------------------------------------//
  char buffer[20];
  int i;
  int j;
  //---------------------------------------------//
  unsigned long int u_val;	// para format '%u'
  //---------------------------------------------//
  unsigned long int Xx_val; // para format '%Xx'
  char *HEX_MIN = "0123456789abcdef";
  char *HEX_MAYUS = "0123456789ABCDEF";
  //---------------------------------------------//
  void *ptr;				// Para format '%p'
  unsigned long p_val;
  //---------------------------------------------//


  caracteres_impresos = 0;
  p = format;
  va_start(args, format);

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
        s_val = va_arg(args, char*);
        if (s_val == NULL)
        {
          write(1, "(null)", 6);  // <- Comillas dobles, no simples
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
      else if (*p == 'd' || *p == 'i')
      {
        long i_val; // <- Variable local, no global
        i = 0;

        i_val = va_arg(args, int);

        // Signo
        if (i_val < 0)
        {
          write(1, "-", 1);
          caracteres_impresos++;
          i_val = -i_val;
        }

        // Caso especial: i_val == 0
        if (i_val == 0)
        {
          write(1, "0", 1);
          caracteres_impresos++;
          p++;
          continue;  // <- Usar continue para evitar el código siguiente
        }

        // Construcción del número en buffer (al revés)
        while (i_val > 0)
        {
          buffer[i++] = (i_val % 10) + '0';
          i_val /= 10;
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

        p++;
      }
      else if (*p == 'u') // <-- entero decimal sin signo.
      {
        i = 0;
        u_val = va_arg(args, unsigned int);

        // Caso especial: u_val == 0
        if (u_val == 0)
        {
          write(1, "0", 1);
          caracteres_impresos++;
          p++;
          continue;
        }

        // Construcción del número en buffer (al revés)
        while (u_val > 0)
        {
          buffer[i++] = (u_val % 10) + '0';
          u_val /= 10;
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

        p++;
      }
      else if (*p == 'X') // <-- Hexadecimal mayus
      {
        i = 0;
        Xx_val = va_arg(args, unsigned int);
     
        if (Xx_val == 0)
        {
          write(1, "0", 1);
          caracteres_impresos++;
          p++;
          continue;
        }
        // Construcción del número en buffer (al revés)
        while (Xx_val > 0)
        {
          buffer[i++] = HEX_MAYUS[Xx_val % 16];
          Xx_val /= 16;
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
        p++;
      }
      else if (*p == 'x') // <- Hexadecimal minus
      {
        i = 0;
        Xx_val = va_arg(args, unsigned int);
        
        if (Xx_val == 0)
        {
          write(1, "0", 1);
          caracteres_impresos++;
          p++;
          continue;
        }
        // Construcción del número en buffer (al revés)
        while (Xx_val > 0)
        {
          buffer[i++] = HEX_MIN[Xx_val % 16];
          Xx_val /= 16;
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
        p++;
      }
      else if (*p == 'p') // <-- puntero (hex con prefijo 0x)
      {
        ptr = va_arg(args, void *);
        p_val = (unsigned long)ptr;

        write(1, "0x", 2);
        caracteres_impresos += 2;

        i = 0;  // <- Inicializar i antes de usar

        if (p_val == 0)
        {
          write(1, "0", 1);
          caracteres_impresos++;
          p++;
          continue;
        }

        while (p_val > 0)
        {
          buffer[i++] = "0123456789abcdef"[p_val % 16];
          p_val /= 16;
        }
        buffer[i] = '\0';

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

        // Impresión final del buffer
        j = 0;
        while (buffer[j])
        {
          write(1, &buffer[j], 1);
          caracteres_impresos++;
          j++;
        }

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
  }

  va_end(args);
  return (caracteres_impresos);
}