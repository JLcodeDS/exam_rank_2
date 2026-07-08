/*
Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$
*/

#include <unistd.h>


void put_hex(int n)
{
	char c;

	if (n >= 16)
	{
		put_hex(n / 16);
		n = n % 16;
	}
	if (n < 16)
	{
		if (n < 10)
			c = n + '0';
		else
			c = 'a' + n - 10;
		write(1, &c, 1);
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		char *s = av[1];
		int n = 0;
		int i = 0;
		while (s[i])
			n = n * 10 + s[i++] - '0';
		put_hex(n);
	}
	write(1, "\n", 1);
}
