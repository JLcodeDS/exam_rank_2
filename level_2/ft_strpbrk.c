/*
DESCRIPTION
     The strpbrk() function locates in the null-terminated string s the first occurrence of any character in the string
     charset and returns a pointer to this character.  If no characters from charset occur anywhere in s strpbrk() returns
     NULL.
Assignment name	: ft_strpbrk
Expected files	: ft_strpbrk.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strpbrk
(man strpbrk).

The function should be prototyped as follows:

char	*ft_strpbrk(const char *s1, const char *s2);
*/

#include <stdio.h>
#include <libc.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int i = 0;
	int j;

	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j++])
				return ((char *)&s1[i]);
		}
		i++;
	}
	return (NULL);
}

int main(int ac, char **av)
{
	if (ac == 0)
		return 0;
	printf("ft: %s\n", ft_strpbrk(av[1], av[2]));
	printf("true: %s\n", strpbrk(av[1], av[2]));
}