#include "pushswap.h"

int     *file_tab(int *t, char **av)
{
    int i;

    i = 1;
    while(av[i])
    {
        t[i-1] = ft_atoi(av[i]);
        i++;
    }
    return (t);
}

int     valid_parse(char **str)
{
    int i;

    i = 1;
    while(str[i] && is_digit(str[i]) && in_range_int(str[i]))
        i++;
    return (i - 1);
}

int     *indexxx(int *t, int size, int min, int max)
{
    int *tab;
    int i;
    int j;
    int s;

    i = -1;
    s = 0;
    tab = malloc(sizeof(int)*size);
    while(++i < size)
    {
        j = -1;
		max = 2147483647;
        while(++j < size)
        {
            if(t[j] < max && t[j] > min)
            {
                max = t[j];
                s = j;
            }
        }
        tab[s] = i;
        min = max;  
    }
    free(t);
    return(tab);
}

void    pushswap(int size, t_stack *a, t_stack *b)
{
    int maxbits;
    int i;
    int j;
    t_op *tp;

    maxbits = 0;
    while ((size) >> maxbits != 0)
        maxbits++;
    i = -1;
    while (++i < maxbits)
    {
        j = -1;
        while (++j < size)
        {
            if (((a->val >> i) & 1 ) == 1)
                a = rotate_ab(a, "ra\n");
            else
                ft_push_ab(&a, &b, "pb\n");
        }
        while(!(b_is_empty(b)))
            ft_push_ab(&b, &a, "pa\n");
    }
}

int     main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    int     size;
    int     *tab;

    a = NULL;
    b = NULL;
    size = valid_parse(argv);
    tab = malloc(sizeof(int) *size);
    tab = file_tab(tab, argv);
    tab = indexxx(tab, size, -2147483648, 2147483647);
    a = fill(a, tab, size - 1);
    check_duplicate(a, size);
    if(size == 3)
        a = sort3(tab, size);
    else if (size == 5)
        a = sort5(a, tab, size);
    else 
        pushswap(size, a, b);
    //system("leaks push_swap");
}