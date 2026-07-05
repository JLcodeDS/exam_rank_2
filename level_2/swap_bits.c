/*
Assignment name  : swap_bits
Expected files   : swap_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, swaps its halves (like the example) and
returns the result.

Your function must be declared as follows:

unsigned char	swap_bits(unsigned char octet);

Example:

  1 byte
_____________
 0100 | 0001
     \ /
     / \
 0001 | 0100
 7654   3210
*/

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int n = 7;
	while(n >= 0)
	{
		if ((octet >> n & 1) == 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		n--;
	}
	write(1, "\n", 1);
}

unsigned char	swap_bits(unsigned char octet)
{
	int high = 7;
	int low = 3;
	unsigned char swapped = 0;
	while (high > 3)
	{
		swapped += (1 << low) * (octet >> high & 1) + (1 << high) * (octet >> low & 1);
		low--;
		high--;
	}
	return (swapped);
}

int main()
{
	unsigned char octet = 132;
	print_bits(octet);
	unsigned char rev = swap_bits(octet);
	print_bits(rev);
}