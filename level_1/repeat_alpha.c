/*
Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>
*/

#include <unistd.h>

int main(int ac, char **av)
{
	char *s;
	int i = 0;
	int times;

	if (ac == 2)
	{	
		s = av[1];
		while(s[i])
		{
			times = 1;
			if (s[i] >= 'a' && s[i] <= 'z' )
				times += s[i] - 'a';
			if (s[i] >= 'A' && s[i] <= 'Z' )
				times += s[i] - 'A';
			while (times-- > 0)
				write(1, &s[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}