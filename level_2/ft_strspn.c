/*
Assignment name	: ft_strspn
Expected files	: ft_strspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the strspn function 
(man strspn).

The function should be prototyped as follows:

size_t	ft_strspn(const char *s, const char *accept);
*/

#include <stdio.h>
#include <string.h>

int is_accept(char c, const char *accept)
{
	int i = 0;
	while (accept[i])
	{
		if (accept[i++] == c)
			return (1);
	}
	return (0);
}

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t i = 0;
	while (s[i] && is_accept(s[i], accept))
		i++;
	return (i);
}

int main(int ac, char **av)
{
	if (ac == 0)
		return (0);
	printf("%zu - %lu\n", ft_strspn(av[1], av[2]), strspn(av[1], av[2]));
}