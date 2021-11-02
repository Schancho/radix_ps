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
    t_stack *head;

	ft_putstr(str);
    tmp = p;
    head = p->next;
    while (tmp->next)
        tmp = tmp->next;
    p->next = NULL;
    tmp->next = p;
    return (head);
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
    t_stack *tmp;

	ft_putstr(str);
    tmp = a;
    while (tmp->next->next)
        tmp = tmp->next;
    tmp->next->next =a;
    a = tmp->next;
    tmp->next = NULL; 
    return (a);
}