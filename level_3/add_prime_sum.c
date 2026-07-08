/*
Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>
*/

#include <unistd.h>
#include <stdio.h>

int is_pos_int(char *s)
{
	int i = 0;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int is_prime(int n)
{
	int i = 2;
	while (i < n)
	{
		if (!(n % i++))
			return (0);
	}
	return (1);
}

void ft_putnbr(unsigned int n)
{
	char c;
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		n = n % 10;
	}
	if (n < 10)
	{
		c = n + '0';
		write(1, &c, 1);
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		char *s = av[1];
		unsigned int i = 0;
		unsigned int n = 0;
		unsigned int total = 0;
		if (is_pos_int(s))
		{
			while (s[i])
				n = n * 10 + s[i++] - '0';
			i = 2;
			while (i <= n)
			{
				if (is_prime((unsigned int)i))
					total += i;
				i++;
			}
			ft_putnbr(total);
		}
		else
			write(1, "0", 1);
	}
	write(1, "\n", 1);
}