/*
Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject);
*/

#include <string.h>
#include <stdio.h>

int isin_reject(char c, const char *reject)
{
	int i = 0;
	while (reject[i])
	{
		if (reject[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t i = 0;
	while (s[i] && !isin_reject(s[i], reject))
		i++;
	return (i);
}

int main(int ac, char **av)
{
	if (ac == 0)
		return (0);
	char *s1 = av[1];
	char *charset = av[2];
	printf("ft: %zu\n", ft_strcspn(s1, charset));
	printf("true: %lu\n", strcspn(s1, charset));
}