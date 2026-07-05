/*
Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);

*/

#include <stdio.h>

char    *ft_strrev(char *str)
{
	char c;
	int i = 0;
	int j = 0;
	while (str[j])
		j++;
	j--;
	while (i < j)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		i++;
		j--;
	}
	return (str);
}

int main(int ac, char **av)
{
	if (ac == 0)
		return (0);
	char *s = av[1];
	printf("%s\n", av[1]);
	printf("%s\n", ft_strrev(s));
}