#include <unistd.h>

// int	main(void)
// {
// 	char alpha;

// 	alpha = 97;

// 	while (alpha <= 122)
// 	{
// 		while (alpha % 2 == 0)
// 		{
// 			alpha -= 32;
// 			alpha++;
// 		}
// 		alpha++;
// 		write(1, &alpha, 1);
// 	}
// }

int main(void)
{
	char s ='a';
	char c = 'B';
	int i = 0;
	while(i <= 12)
	{
		write(1, &s, 1);
		write(1, &c, 1);
		s = s + 2;
		c = c + 2;
		i++;
	}
}