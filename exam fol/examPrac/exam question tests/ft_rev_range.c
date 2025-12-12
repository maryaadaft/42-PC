#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int     *ft_rrange(int start, int end)
{
	int i;
	int *wiss;
	int count;
	i = 0;
			// i < count for all the while loops
// 2 loops and malloc for 3 cases.
// when end is less than 0, end will increment to start
	if (end < 0)
	{
		count = start + (end * -1) + 1;
		wiss = malloc(sizeof(int) * count);
		while (i < count)
		{
			wiss[i] = end;
			i++;
			end++;
		}
		return (wiss);
	}
//both cases of start is less than 0 and other normal cases use the same loop where end increments
	else if (start < 0)
	{
		count = end + (start * -1) + 1;
	}
	else
	{
		count = (end - start) + 1;
	}

	wiss = malloc(sizeof(int) * count);
	if (wiss == NULL)
	{
		return (NULL);
	}
	while (i < count)
	{
		wiss[i] = end;
		i++;
		end--;
	}
	return (wiss);
}
int	main(void)
{
	int i;
	int *wiss;
	int start;
	int end;

	i = 0;
	start = 0;
	end = -3;
	wiss = ft_rrange(start, end);
	while (i < 4)
	{
		printf("%d", wiss[i]);
		i++;
	}
	free(wiss);
	return (0);
}