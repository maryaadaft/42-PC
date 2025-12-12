#include <stdlib.h>
#include <stdio.h>

int     *ft_range(int start, int end)
{
	int i;
	int count;
	int *wiss;
	
	//start is negative, negatives are included
	if (start < 0)
	{
		count = ((start * -1) + end) + 1;
		// 1 + 2 + 1 (-1, 2)
		// 4 + 2 + 1 (-4, 2)
		// 5 + 3 + 1 (-5, 3)
	}
	//end is negative, negatives are included
	else if (end < 0)
	{
		count = ((end * -1) + start) + 1;
		// printf("%i", count);
	}
	//normal cases, both positive
	else
	{
		count = (end - start) + 1;
	}	
	if (count < 0)
	{
		return (0);
	}
	wiss = malloc(sizeof(int) * count);
	if (wiss == NULL)
	{
		return (NULL);
	}
	while (i < count)
	{
		wiss[i] = start;
		printf("%d\n", wiss[i]);
		i++;
		start++;
	}
	return (wiss);
}

int	main(void)
{
	int *mar;

	int start, end;
	start = -1;
	end = 2;
	//normal cases, both positive
		// int count = (end - start) + 1;
	//start is negative
		// int count = ((start * -1) + end) + 1;
	//end is negative
		// int count = ((end * -1) + start) + 1;
	mar = ft_range(start, end);
	printf("%d", mar[0]);
	printf("%d", mar[1]);
	printf("%d", mar[2]);
	printf("%d", mar[3]);

	free(mar);
	return(0);
}
