#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int i = 0;
        int len = ft_strlen(argv[1]) - 1;
        int w_start = 0;
        int w_end = 0;
		int in_word = 1;

		while (len >= 0)
		{
			while(len >= 0 && (argv[1][len] == ' ' || argv[1][len] == '\t'))
				len--;
			if (len < 0)
				break;
			w_end = len;
			while (argv[1][len] > 32 && argv[1][len] < 127)
				len--;
			w_start = len + 1;

			if(in_word == 0)
				write(1, " ", 1);
			in_word = 0;
			while(w_start <= w_end)
			{
				write(1, &argv[1][w_start], 1);
				w_start++;
			}
		}
    }
    write(1, "\n", 1);
}

