// Header

void  ft_puthex(unsigned long long n, char format, int i)
{
  char  *base;
  
  if(format == 'x')
    base = "0123456789abcdef";
  else
    base = "0123456789ABCDEF";
  if (n >= 16)
    ft_puthex(n / 16, format, i);
  ft_putchar(base[n % 16], i);
}
