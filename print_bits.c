#include <unistd.h>
#include <stdio.h>

void print_bits(unsigned char octet)
{
	int bits_n = 7;
	// char bit;
	
	while (bits_n >= 0)
	{
		if ((octet >> bits_n & 1) == 1)
			printf("1");
		else
			printf("0");
			
		// write(1, &bit, 1);
		bits_n--;
	}
	printf("\n");
	// write(1, "\n", 1);

}

// int main()
// {
// 	print_bits(21);
// }