#ifndef FT_PRINTF
# define FT_PRINTF

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

int     ft_printf(char const *format, ...);

char	*itoa(int n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *d, size_t len);


#endif
