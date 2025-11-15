
#include "ft_printf.h"

void	ft_bzero(void *d, size_t len)
{
	unsigned char	*ptr;

	ptr = d;
	while (len--)
		*ptr++ = 0;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	ptr = (void *)malloc(nmemb + size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

static int nb_size(int j)
{
	int		i;

	if (j == 0)
		return (1);
	i = 0;
	if (j < 0)
	{
		i = 1;
		j = -j;
	}
	while (j < 0)
	{
		i++;
		j = j / 10;
	}
	return (i);
}

char	*itoa(int n)
{
	int		i;
	int		j;
	char	*str;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	i = nb_size;
	str = ft_calloc (sizeof(char), i + 1);
	if (!str)
		return NULL;
	j = 0;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		j = 1;
	}
	i--;
	while (i >= j)
	{
		str[i] = (n % 10) + '0';
		i--;
		n = n / 10;
	}
	return (str);
}
