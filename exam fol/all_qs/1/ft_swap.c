void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
#include <stdio.h>

/* int	main(void)
{
	int one = 1;
	int two = 22;

	ft_swap(&one, &two);

	printf("one is: %d\n two is: %d\n", one, two);
} */