#include "pushswap.h"

t_stack     *ft_push(t_stack *pile, int data)
{
    t_stack *new;

    new = (t_stack *)malloc(sizeof(t_stack));
    if(new)
    {
        new->val = data;
        new->next = pile;
        return (new);
    }
    return (NULL);
}


t_stack     *rotate_ab(t_stack *p, char *str)
{
    t_stack *tmp;
    t_stack *new;
    int     val;

	ft_putstr(str);
    val = p->val;
    tmp = p;
    p = p->next;
    tmp->next = NULL;
    free(tmp);
    tmp = p;
    new = (t_stack*)malloc(sizeof(t_stack));
    if(new)
    {
        new->next = NULL;
        new->val = val;
        while (p->next)
        {
            p = p->next;
        }
        p->next = new;
    }
    return (tmp);
}

void       ft_push_ab(t_stack **a, t_stack **b, char *str)
{
    t_stack *tmp;
    int value;

	ft_putstr(str);
    if(a)
    {
        tmp = (*a)->next;
        (*a)->next = *b;
        *b = (*a);
        *a = (tmp);
    }
}

t_stack     *reverse_rotate(t_stack *a, char *str)
{
    t_stack *new;
    t_stack *tmp;

	ft_putstr(str);
    tmp = a;
    new = (t_stack *)malloc(sizeof(t_stack));
    while (tmp->next->next)
        tmp = tmp->next;
    new->val = tmp->next->val;
    new->next = a;
    free(tmp->next);
    tmp->next = NULL; 
    return (new);
}