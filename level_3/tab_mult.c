/*
Assignment name  : tab_mult
Expected files   : tab_mult.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays a number's multiplication table.

The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.

If there are no parameters, the program displays \n.

Examples:

$>./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171
$>
$>./tab_mult | cat -e
$
$>
*/

#include <unistd.h>

void ft_putstr(char *s)
{
	int i = 0;
	while(s[i])
		write(1, &s[i++], 1);
}

void ft_putnbr(int n)
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
		int n = 0;
		int multi = 1;
		char c ;
		int i = 0;
		char *s = av[1];
		while (s[i])
			n = n * 10 + s[i++] - '0';
		while (multi < 10)
		{
			c = multi + '0';
			write(1, &c, 1);
			write(1, " X ", 3);
			ft_putstr(s);
			write(1, " = ", 3);
			ft_putnbr(n * multi);
			write(1, "\n", 1);
			multi++;
		}

	}
	else
		write(1, "\n", 1);
}