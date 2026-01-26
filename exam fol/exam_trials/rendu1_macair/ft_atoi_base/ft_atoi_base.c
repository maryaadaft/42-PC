int	ft_atoi_base(const char *str, int str_base)
{
    int i = 0;
    int sign = 1;
    int numb = 0;
    int v = 0;

    while (str[i] <= 32)
        i++;
    if (str[i] == '+')
        i++;
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    while (str[i] != '\0')
    {
        if (str[i] >= '0' && str[i] <= '9')
            v = str[i] - '0';
        else if (str[i] >= 'a' && str[i] <= 'f')
            v = str[i] - 'a' + 10;
        else if (str[i] >= 'A' && str[i] <= 'F')
            v = str[i] - 'A' + 10;
        else
            break;

        if (v >= str_base)
            break;;

        numb = numb * str_base + v;
        i++;
    }
    return (numb * sign);
}

/*

#include <stdio.h>
int main(void)
{
    printf("%d\n", ft_atoi_base("-16", 2));
}

*/
