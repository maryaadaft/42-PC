#include <unistd.h>

int main(int ac, char **av)
{
	(void)av;
	char nums[50] = {0};
	int counter = 0;
	ac--;
	if (ac == 0)
	{
		write(1, "0\n", 2);
		return 0;
	}
	while (ac > 0) {
		int n = ac % 10;
		ac /= 10;
		nums[counter++] = n + '0';
	}
	while (counter != 0)
	{
		write(1, nums + counter - 1, 1);
		counter--;
	}
	write(1, "\n", 1);
	return 0;

}
