#include <unistd.h>

void	print_bits(unsigned char octet)
{
	unsigned char what = 0;
	int i = 8;

	while (i >= 0)
	{
		what = (octet >> i & 1) + '0';
		write(1, &what, 1);
		i--;
	}
}

// #include <stdio.h>
// int	main(void)
// {
// 	unsigned char octet = 2;
// 	print_bits(octet);
// }