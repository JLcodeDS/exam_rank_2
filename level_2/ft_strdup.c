/*
Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);
*/

#include <stdlib.h>

char    *ft_strdup(char *src)
{
	int i = 0;
	char *src_d;
	while (src[i])
		i++;
	src_d = malloc((i + 1) * sizeof(char));
	i = 0;
	while(src[i++])
		src_d[i] = src[i];
	src_d[i] = '\0';
	return (src_d);
}