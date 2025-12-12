// Write a program that takes two strings and displays, without doubles, the
// characters that appear in both strings, in the order they appear in the first
// one.

// The display will be followed by a \n.

// If the number of arguments is not 2, the program displays \n.

// Examples:

// $>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
// padinto$
// $>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
// df6ewg4$
// $>./inter "rien" "cette phrase ne cache rien" | cat -e
// rien$
// $>./inter | cat -e
// $

#include <unistd.h>


int hasChar(char *set, char c)
{
	if (!set)
		return 0;
	while (*set) {
		if (*set == c)
			return 1;
		set++;
	}
	return 0;
}

int main(int ac, char **av) {
	int counter = 0;
	if (ac != 3)
	{
		write(1, "\n", 1);
		return 1;
	}
	char set[255] = {0};

	while (av[1][0]) {
		char c = av[1][0];
		if (hasChar(av[2], c) && !hasChar(set, c))
			set[counter++] = c;
		av[1]++;
	}
	while (av[2][0]) {
		char c = av[2][0];
		if (hasChar(av[1], c) && !hasChar(set, c))
			set[counter++] = c;
		av[2]++;
	}
	write(1, set, counter);
	write(1, "\n", 1);
	return 0;
}
