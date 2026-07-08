/*
Assignment name  : expand_str
Expected files   : expand_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it with exactly three spaces
between each word, with no spaces or tabs either at the beginning or the end,
followed by a newline.

A word is a section of string delimited either by spaces/tabs, or by the
start/end of the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:

$> ./expand_str "See? It's easy to print the same thing" | cat -e
See?   It's   easy   to   print   the   same   thing$
$> ./expand_str " this        time it      will     be    more complex  " | cat -e
this   time   it   will   be   more   complex$
$> ./expand_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./expand_str "" | cat -e
$
$>
*/

#include <unistd.h>

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = 0;
		int j = 0;
		char *s = av[1];
		while (s[i] && (s[i] == ' ' || s[i] == '\t'))
			i++;
		while (s[i])
		{
			j = i;
			while (s[j] && (s[j] == ' ' || s[j] == '\t'))
				j++;
			if (!s[j])
				break;
			write(1, &s[i], 1);
			if (s[i] == ' ' || s[i] == '\t')
			{
				write(1, "  ", 2);
				while (s[i] && (s[i] == ' ' || s[i] == '\t'))
					i++;
			}
			else
				i++;
		}
	}
	write(1, "\n", 1);
}