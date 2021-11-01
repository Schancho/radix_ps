#include "pushswap.h"

long	ft_atoi(char *str)
{
	long	nbr;
	 int	sign;

	nbr = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + *str - 48;
		str++;
	}
	return (nbr * sign);
}

int     in_range_int(char *str)
{
    if (ft_atoi(str) > 2147483647 || ft_atoi(str) < -2147483648)
    {
        printf("One of elements is out of range\n");
        exit(1);
    }
    return (1);
}

int     is_digit(char *str)
{
    int i;

    i = 0;
    if(str[i] == '-' || str[i] == '+')
        i++;
    while(str[i])
    {
        if(!(str[i] >= '0' && str[i] <= '9'))
        {
            ft_putstr("INVALID ARGUMENTS\n");
            exit(1);
        }
        i++;
    }
    return (1);
}

void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        ft_putchar(str[i]);
        i += 1;
    }
}

void    ft_putchar(char c)
{
    write(1, &c, 1);
}