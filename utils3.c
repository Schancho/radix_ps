#include "pushswap.h"

int     stack_size(t_stack *a)
{
    int     i;

    i = 0;
    while (a)
    {
        a = a->next;
        i++;
    }
    return (i);
}

int         check_pos(t_stack *a, int value)
{
    t_stack *tmp;
    int j;

    j = 0;
    tmp = a;
    while (tmp)
    {
        if (tmp->val == value)
            break;
        j++;
        tmp = tmp->next;
    }
    return (j);
}

int     last(t_stack *a)
{
    t_stack *tmp;

    tmp = a;
    while (tmp->next)
        tmp = tmp->next;
    return (tmp->val);
}

t_stack     *fill(t_stack *a, int *tab, int size)
{
    int i;
    t_stack *tmp;

    i = 0;
    while (i <= size)
    {
        a = ft_push(a, tab[size]);
        size--;
    }
    return (a);
}
