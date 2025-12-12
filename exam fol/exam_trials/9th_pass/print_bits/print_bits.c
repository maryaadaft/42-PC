#include <unistd.h>

void	print_bits(unsigned char octet)
{
	unsigned char what = 0;
	int i = 8;

	while (i--)
	{
		what = (octet >> i & 1) + 48;
		write(1, &what, 1);
	}
}

// #include <stdio.h>
// int	main(void)
// {
// 	unsigned char octet = 2;
// 	print_bits(octet);
// }
