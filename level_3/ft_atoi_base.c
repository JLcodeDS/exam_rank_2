/*
Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);
*/

#include <stdlib.h>
#include <stdio.h>

char *to_lower(char *s)
{
	int i = 0;
	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] + 'a' - 'A';
		i++;
	}
	return (s);
}

int is_in_base(char c, int base, char *s_base)
{
	int i = 0;
	while (i < base)
	{
		if (s_base[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int find_base_int(char c, char *s_base)
{
	int i = 0;
	while (s_base[i])
	{
		if (s_base[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int ft_atoi_base(const char *str, int str_base)
{
	char *bases = "0123456789abcdef";
	int i = 0;
	int sign = 1;
	long long n = 0;
	char *lower_str = to_lower((char *)str);

	if (lower_str[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (lower_str[i] && is_in_base(lower_str[i], str_base, bases))
		n = n * str_base + find_base_int(lower_str[i++], bases);
	return (n * sign);
}

int main(int ac, char **av)
{
	if (ac == 3)
		printf("%d\n", ft_atoi_base(av[1], atoi(av[2])));
}