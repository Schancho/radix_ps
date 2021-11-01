#include "pushswap.h"

int     b_is_empty(t_stack *b)
{
    if(!b)
        return (1);
    return (0);
}

int     is_sorted(t_stack *a)
{   int i;

    i = 0;
    while (a)
    {
        if (a->val != i)
            return (0);
        i++;
        a = a->next;
    }
    return (1);
}

int is_min(t_stack *a)
{   
    t_stack *tmp;

    int min;
    min = a->val;
    tmp = a->next;
    while (tmp)
    {
        if (tmp->val < min)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

int is_max(t_stack *a)
{   
    t_stack *tmp;

    int max;
    max = a->val;
    tmp = a->next;
    while (tmp)
    {
        if (tmp->val > max)
            return (0);
        tmp = tmp->next;
    }
    return (0);
}

void    check_duplicate(t_stack *a, int size)
{
    t_stack *tmp;
    int i;
    int check;

    i = 0;
    while (i < size)
    {
        tmp = a;
        check = 0;
        while (tmp)
        {
            if (tmp->val == i)
                check++;
            tmp = tmp->next;
        }
        if (check == 0)
        {
            ft_putstr("Error duplication\n");
            exit(1);
        }
        i++;
    } 
}