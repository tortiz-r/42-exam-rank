//This file is given at the exam as it is (incomplete and/or incorrect)

#include "get_next_line.h"

// pdte-> transcribir esta función del subject del examen
char	*get_next_line(int fd);

// resto de funciones
	// (con código, pdte transcribirlo del subject del examen)

char	*ft_strchr(const char *s, char c);

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	while (n-- > 0)
		((char *)dst)[n - 1] = ((char *)src)[n - 1];
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	ret = 0;

	while (*s)
	{
		s++;
		ret++;
	}
	return (ret);
}



int	str_append_mem(char **s1, char *s2, size_t n);

int str_append_str(char **s1, char *s2)
{
	return (str_append_mem(s1, s2, ft_strlen(s2)));
}

void	*ft_memmove(void *dst, const void *src, size_t n);
// {
// 	if (dst > src)
// 		return (ft_memcpy(dst, src, n));
// 	// falta completar esto
// }

