/*
Assignment name  : pgcd
Expected files   : pgcd.c
Allowed functions: printf, atoi, malloc, free
--------------------------------------------------------------------------------

Write a program that takes two strings representing two strictly positive
integers that fit in an int.

Display their highest common denominator followed by a newline (It's always a
strictly positive integer).

If the number of parameters is not 2, display a newline.

Examples:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e
1$
$> ./pgcd | cat -e
$
*/

#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
	if (ac == 3)
	{
		int n1 = atoi(av[1]);
		int n2 = atoi(av[2]);
		int denum = n1;

		while (denum > 0)
		{
			if (n1 % denum == 0 && n2 % denum == 0)
				break;
			denum--;
		}
		printf("%d", denum);
	}
	printf("\n");
}