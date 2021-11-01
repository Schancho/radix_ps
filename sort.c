#include "pushswap.h"



int *case1(int *tab)
{
	int tmp;

	ft_putstr("sa\n");
	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tmp;
	return (tab);
}

int *case2(int *tab)
{
	int tmp;

	ft_putstr("sa\nrra\n");
	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tmp;
	tmp = tab[2];
	tab[2] = tab[1];
	tab[1] = tab[0];
	tab[0] = tmp;
	return (tab);
}

int *case3(int *tab)
{
	int tmp;

	ft_putstr("ra\n");
	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tab[2];
	tab[2] = tmp;
	return (tab);
}

int *case4(int *tab)
{
	int tmp;

	ft_putstr("sa\nra\n");
	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tmp;
	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tab[2];
	tab[2] = tmp;
	return (tab);
}

int *case5(int *tab)
{
	int tmp;

	ft_putstr("rra\n");
	tmp = tab[2];
	tab[2] = tab[1];
	tab[1] = tab[0];
	tab[0] = tmp;
	return (tab);
}


t_stack    *sort3(int *tab, int size)
{
    t_stack *a;
    a = NULL;

    if(tab[0] > tab[1] && tab[0] < tab[2] && tab[1] < tab[2])
		tab = case1(tab);
    else if(tab[0] > tab[1] && tab[0] > tab[2] && tab[1] > tab[2])
		tab = case2(tab);
    else if(tab[0] > tab[1] && tab[0] > tab[2] && tab[1] < tab[2])
		tab = case3(tab);
    else if(tab[0] < tab[1] && tab[0] < tab[2] && tab[1] > tab[2])
		tab = case4(tab);
    else if(tab[0] < tab[1] && tab[0] > tab[2] && tab[1] > tab[2])
		tab = case5(tab);
    a = fill(a, tab, size - 1);
    return (a);
}

void    sort_5_init(t_stack **a, t_stack **b, int *tab)
{
    *b = NULL;
    *b = ft_push(*b, tab[0]);
    *b = ft_push(*b, tab[1]);
    ft_putstr("pb\npb\n");
    
    *a = sort3(tab + 2, 3);
    if ((*b)->val < (*b)->next->val)
        *b = rotate_ab(*b, "rb\n");
}

void	sort5_2(t_stack **a, t_stack **b, int j)
{
	if (is_min(*a) && ((*b)->val == 4))
		ft_push_ab(b, a, "pa\n");
	else if ((*b)->val == (*a)->val - 1)
		ft_push_ab(b, a, "pa\n");
	else
	{
		if ((*b)->val <= 3)
		{
			j = check_pos(*a, (*b)->val + 1);
			if (j > 2)
				*a = reverse_rotate(*a, "rra\n");
			else
				*a = rotate_ab(*a, "ra\n");
		}
		else
			*a = rotate_ab(*a, "ra\n");
	}
}


t_stack    *sort5(t_stack *a, int *tab, int size)
{
    t_stack *b;
    t_stack *tmp;
    int j;

    j = 0;
    sort_5_init(&a, &b, tab);
    while (b)
    {
		sort5_2(&a , &b, j);
    }
    j = check_pos(a, 0);
    while (is_sorted(a) == 0)
    {
        if (j > 2)
            a = reverse_rotate(a, "rra\n");
        else
            a = rotate_ab(a, "ra\n");
    }
    return (a);
}