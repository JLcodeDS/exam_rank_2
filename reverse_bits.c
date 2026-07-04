#include "print_bits.c"

unsigned char reverse_bits(unsigned char octet)
{
	unsigned char rev_octet = 0;
	int n_bit = 7;
	int rev_bit = 1;
	print_bits(octet);
	while (n_bit >= 0)
	{
		rev_octet += rev_bit * ((octet >> n_bit-- & 1) == 1);
	}
	print_bits(rev_octet);
	return (octet);
}

int main()
{
	reverse_bits(200);
}