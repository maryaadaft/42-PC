#include <stdio.h>
#include <stdlib.h>

int     *ft_rrange(int start, int end)
{
	int *arr;
	int i = 0;
	int count;

	//normal cases, end is greater than start
	if (end > start)
	{
		count = end - start + 1;
		arr = malloc(sizeof(int) * count);
		if (!arr)
			return (NULL);

		while (end >= start)
		{
			arr[i] = end;
			i++;
			end--;
		}
	}
	else if (start > end)
	{
		i = 0;
		count = start + (-end) + 1;
		arr = malloc(sizeof(int) * count);
		if (!arr)
			return (NULL);
		
		while (end <= start)
		{
			arr[i] = end;
			end++;
			i++;
		}
	}
	else if (end == start)
	{
		i = 0;
		arr = malloc(sizeof(int) * 1);
		arr[i] = end;
	}
	return (arr);
}

// int	main(void)
// {
// 	int start = -3;
// 	int end = -3;
// 	int i = 0;
// 	int count = start - end + 1;
// 	int *testarr = ft_rrange(start, end);
// 	printf("%d\n", testarr[0]);
// 	printf("%d\n", testarr[1]);
// 	printf("%d\n", testarr[2]);
// 	printf("%d\n", testarr[3]);


// 	// while (count > 0)
// 	// {
// 	// 	printf("%d\n", testarr[i]);
// 	// 	i++;
// 	// 	count--;
// 	// }
// }