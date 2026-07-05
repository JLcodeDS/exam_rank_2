/*
Assignment name  : ft_strcmp
Expected files   : ft_strcmp.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcmp (man strcmp).

Your function must be declared as follows:

int    ft_strcmp(char *s1, char *s2);
*/

#include <stdio.h>

int ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int main(int ac, char **av)
{
	if (ac == 0)
		return 0;
	char *s1 = av[1];
	char *s2 = av[2];
	printf("%s %s: %d\n", s1, s2, ft_strcmp(s1, s2));
}