/*
Assignment name  : rot_13
Expected files   : rot_13.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the letter 13 spaces ahead in alphabetical order.

'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

The output will be followed by a newline.

If the number of arguments is not 1, the program displays a newline.

Example:

$>./rot_13 "abc"
nop
$>./rot_13 "My horse is Amazing." | cat -e
Zl ubefr vf Nznmvat.$
$>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
NxwuM mYXVWm , 23l $
$>./rot_13 | cat -e
$
$>
$>./rot_13 "" | cat -e
$
$>
*/

#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int i = 0;
	int c;
	if (ac == 2)
	{
		char *s = av[1];
		while (s[i])
		{
			if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
			{
				//printf("1 c: %c %d\n", s[i], s[i]);
				c = s[i] + 13;
				//printf("2 c: %c %d\n", c, c);
				if (c > 'Z' && c < 'a')
					c = 'A' + c - 'Z' - 1;
				if (c > 'z')
					c = 'a' + c - 'z' - 1;
				//printf("3 c: %c %d\n", c, c);
			}
			else
				c = s[i];
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
}