int	    is_power_of_2(unsigned int n)
{
	int power = 1; //doesn't start at 0

	while (power <= n) //if multiplying by 2 goes over the n input, then it wont enter the loop. It's not a power of 2.
	{
		if (power == n) //if the checker is the number itself, that means its a prime number
			return (1);
		power *= 2; //increment, powers of 2 are 1, 2, 4, 8, 16..etc (all n * 2)
	}
	return (0);
}
