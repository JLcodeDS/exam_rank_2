/*
Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:

int	    is_power_of_2(unsigned int n);
*/

#include <stdio.h>

int	    is_power_of_2(unsigned int n)
{
	unsigned int pow = 2;

	if (n == 1)
		return (1);
	while (pow <= n)
	{
		if (pow == n)
			return (1);
		pow *= 2;
	}
	return (0);
}

//int is_power_of_2(unsigned int n) {
//  if (n == 0)
//    return (0);
//  while (n % 2 == 0)
//    n /= 2;
//  return (n == 1);
//}

int main()
{
	int n = 1;
	while (n < 100)
	{
		printf("%d: %d\n", n, is_power_of_2(n));
		n++;
	}
}