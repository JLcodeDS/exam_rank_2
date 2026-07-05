/*
Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0010  0110
	 ||
	 \/
 0110  0100
*/

#include <unistd.h>

unsigned char reverse_bits(unsigned char octet)
{
	int max = 7;
	unsigned char reversed = 0;
	int n = 0;
	while (n < 8)
	{
		if (octet >> max & 1)
			reversed += 1 << n;
		n++;
		max--;
	}
	return (reversed);
}

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

int main()
{
	unsigned char octet = 132;
	print_bits(octet);
	unsigned char rev = reverse_bits(octet);
	print_bits(rev);
}