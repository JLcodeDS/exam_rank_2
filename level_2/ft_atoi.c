/*
Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int ft_atoi(const char *s)
{
	int i = 0;
	int sign = 1;
	long long n = 0;
	while (s[i] && s[i] == ' ')
		i++;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		n = n * 10 + s[i] - '0';
		i++;
	}
	return (n * sign);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{	
		printf("%d\n", ft_atoi(av[1]));
		printf("%d\n", atoi(av[1]));
		//printf("%d %d\n", INT_MIN, INT_MAX);
	}
}