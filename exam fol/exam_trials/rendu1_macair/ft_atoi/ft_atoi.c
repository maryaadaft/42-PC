#include <unistd.h>

int	ft_atoi(const char *str)
{
    int i = 0;
    int numb = 0;
    int sign = 1;

    while (str[i] <= 32)
        i++;
    if (str[i] == '+')
        i++;
    if(str[i] == '-')
    {
        sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        numb = numb * 10 + str[i] - '0';
        i++;
    }
    return (sign * numb);
}

/*
#include <stdio.h>
int main(void)
{
    printf("%d\n", ft_atoi("13268"));
}*/
