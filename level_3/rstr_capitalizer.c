/*
Assignment name  : rstr_capitalizer
Expected files   : rstr_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or more strings and, for each argument, puts
the last character that is a letter of each word in uppercase and the rest
in lowercase, then displays the result followed by a \n.

A word is a section of string delimited by spaces/tabs or the start/end of the
string. If a word has a single letter, it must be capitalized.

A letter is a character in the set [a-zA-Z]

If there are no parameters, display \n.

Examples:

$> ./rstr_capitalizer | cat -e
$
$> ./rstr_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A firsT littlE tesT$
$> ./rstr_capitalizer "SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
seconD tesT A littlE biT   moaR compleX$
   but... thiS iS noT thaT compleX$
     okay, thiS iS thE lasT 1239809147801 buT noT    thE leasT    T$
$>
*/

#include <unistd.h>
#include <stdio.h>

int is_letter(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int is_space(int c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int to_upper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	return (c);
}

int to_lower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 'a' - 'A');
	return (c);
}

int main(int ac, char **av)
{
	int i = 1;
	int j = 0;
	char *s;

	if (ac == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (i < ac)
	{
		s = av[i++];
		while (s[j])
			j++;
		j--;
		while (j >= 0)
		{
			while (is_space(s[j]) && j >= 0)
				j--;
			if (is_letter(s[j]) && j >= 0)
			{
				s[j] = to_upper(s[j]);
				j--;
			}
			while (!is_space(s[j]) && j >= 0)
			{
				if (is_letter(s[j]))
					s[j] = to_lower(s[j]);
				j--;
			}
		}
		j = 0;
		while (s[j])
			write(1, &s[j++], 1);
		write(1, "\n", 1);
	}
		//printf("%d %s\n", j, s);
}
