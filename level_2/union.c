/*
Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
*/

#include <unistd.h>

int main(int ac, char **av)
{
	if (ac == 3)
	{
		int i = 0, k = 0;
		int j;
		char *s1 = av[1];
		char *s2 = av[2];

		while (s1[i])
		{
			j = i - 1;
			while (j >= 0)
			{
				if (s1[j] == s1[i])
					break;
				j--;
			}
			if (j == -1)
				write(1, &s1[i], 1);
			i++;
		}
		while (s2[k])
		{
			j = 0;
			while (s1[j])
			{
				if (s1[j] == s2[k])
					break;
				j++;
			}
			if (j != i)
			{
				k++;
				continue;
			}
			j = k - 1;
			while (j >= 0)
			{
				if (s2[k] == s2[j])
					break;
				j--;
			}
			if (j == -1)
				write(1, &s2[k], 1);
			k++;
		}
	}
	write(1, "\n", 1);
}