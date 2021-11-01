#include "pushswap.h"
//malloc
int     *file_tab(int *t, char **av)
{
    int i;

    i = 1;
    while(av[i])
    {
        t[i-1] = atoi(av[i]);
        i++;
    }
    return (t);
}

void    ft_putchar(char c)
{
    write(1, &c, 1);
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

int     in_range_int(char *str)
{
    if (atoi(str) > 2147483647 || atoi(str) < -2147483648)
    {
        printf("One of elements is out of range\n");
        exit(1);
    }
    return (1);
}

int     valid_parse(char **str)
{
    int i;

    i = 1;
    while(str[i] && is_digit(str[i]) && in_range_int(str[i]))
        i++;
    return (i - 1);
}

int     *indexxx(int *t, int size)
{
    int *tab;
    int i;
    int j;
    int s;
    int min;
    int max;

    i = 0;
    j = 0;
    s = 0;
    min = -2147483648;
    tab = malloc(sizeof(int)*size);
    while(i < size)
    {
        j = 0;
        max = 2147483647;
        while(j < size)
        {
            if(t[j] < max && t[j] > min)
            {
                max = t[j];
                s = j;
            }
            j++;
        }
        //printf("%d\n", max);
        tab[s] = i;
        min = max;
        i++;    
    }
    free(t);
    return(tab);
}

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

t_stack     *rotate_ab(t_stack *p)
{
    t_stack *tmp;
    t_stack *new;
    int     val;

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

void       ft_push_ab(t_stack **a, t_stack **b)
{
    t_stack *tmp;
    int value;
    if(a)
    {
        tmp = (*a)->next;
        (*a)->next = *b;
        *b = (*a);
        *a = (tmp);
    }
}


// void       ft_push_ab(t_stack **a, t_stack **b)
// {
//     t_stack *mem;
//     int value;
//     if(a)
//     {
//         value = (*a)->val;
//         //printf("%d\n", val);
//         *b = ft_push(*b, value);
//         mem = *a;
//         *a = (*a)->next;
//         free(mem);
//     }
// }

int     b_is_empty(t_stack *b)
{
    if(!b)
        return (1);
    return (0);
}

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

void    pushswap(int size, t_stack *a, t_stack *b)
{
    int maxbits;
    int i;
    int j;
    int k;
    int s;
    t_stack *tmp;
    t_op *tp;

    maxbits = 0;
    while ((size) >> maxbits != 0)
        maxbits++;
    i = 0;
    while (i < maxbits)
    {
        j = 0;
        k = 0;

        while (j < size)
        {
            if (((a->val >> i) & 1 ) == 1)
            {
                a = rotate_ab(a);
                
                printf("ra\n");
                
            }
            else
            {
               
                ft_push_ab(&a, &b);
                printf("pb\n");
                
            }
            j++;
        }
        while(!(b_is_empty(b)))
        {
            ft_push_ab(&b, &a);
            printf("pa\n");
        }
        i++;
    }
//     tmp = a;
//     while (tmp)
//     {
//        printf("%d ", tmp->val);
//        tmp = tmp->next; 
//     }
// printf("\n");
    //return (queue);
}

t_stack     *fill(t_stack *a, int *tab, int size)
{
    int i;
    t_stack *tmp;

    i = 0;
    //printf("size %d\n", size);
    while (i <= size)
    {
        a = ft_push(a, tab[size]);
        size--;
    }
    return (a);
}

t_stack    *sort3(int *tab, int size)
{
    int tmp;
    t_stack *a;
    a = NULL;

    if(tab[0] > tab[1] && tab[0] < tab[2] && tab[1] < tab[2])
    {
        printf("sa\n");
        tmp = tab[0];
        tab[0] = tab[1];
        tab[1] = tmp;
    }
    else if(tab[0] > tab[1] && tab[0] > tab[2] && tab[1] > tab[2])
    {
        printf("sa\nrra\n");
        tmp = tab[0];
        tab[0] = tab[1];
        tab[1] = tmp;
        tmp = tab[2];
        tab[2] = tab[1];
        tab[1] = tab[0];
        tab[0] = tmp;
        
    }
    else if(tab[0] > tab[1] && tab[0] > tab[2] && tab[1] < tab[2])
    {
        printf("ra\n");
        tmp = tab[0];
        tab[0] = tab[1];
        tab[1] = tab[2];
        tab[2] = tmp;

    }
    else if(tab[0] < tab[1] && tab[0] < tab[2] && tab[1] > tab[2])
    {
        printf("sa\nra\n");
        tmp = tab[0];
        tab[0] = tab[1];
        tab[1] = tmp;
        tmp = tab[0];
        tab[0] = tab[1];
        tab[1] = tab[2];
        tab[2] = tmp;
    }
    else if(tab[0] < tab[1] && tab[0] > tab[2] && tab[1] > tab[2])
    {
        printf("rra\n");
        tmp = tab[2];
        tab[2] = tab[1];
        tab[1] = tab[0];
        tab[0] = tmp;
     }
     a = fill(a, tab, size - 1);
    return (a);
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


int     last(t_stack *a)
{
    t_stack *tmp;

    tmp = a;
    while (tmp->next)
        tmp = tmp->next;
    return (tmp->val);
}

// int     is_min(t_stack *a)
// {
//     t_stack *tmp;ƒaddopƒƒ

//     int min;
//     min = a->val;
//     tmp = a->next;
//     while (tmp->next)
//     {
//         if (tmp->val < min)
//             min = tmp->val;
//         tmp = tmp->next;
//     }
//     if (tmp->val < min)
//         min = tmp->val;
//     if (a->val == min)
//         return (min);
//     return (0);
// }

t_stack     *reverse_rotate(t_stack *a)
{
    t_stack *new;
    t_stack *tmp;

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

void    sort_5_init(t_stack **a, t_stack **b, int *tab)
{
    *b = NULL;
    *b = ft_push(*b, tab[0]);
    *b = ft_push(*b, tab[1]);
    printf("pb\npb\n");
    
    *a = sort3(tab + 2, 3);
    if ((*b)->val < (*b)->next->val)
    {
        printf("rb\n");
        *b = rotate_ab(*b);
    }
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
t_stack    *sort5(t_stack *a, int *tab, int size)
{
    t_stack *b;
    t_stack *tmp;
    int j;

    j = 0;
    sort_5_init(&a, &b, tab);
    while (b)
    {
        if (is_min(a) && (b->val == 4))
        {
            ft_push_ab(&b, &a);
            printf("pa\n");
        }
        else if (b->val == a->val - 1)
        {
            ft_push_ab(&b, &a);
            printf("pa\n");
        }
        else
        {
            if (b->val <= 3)
            {
                j = check_pos(a, b->val + 1);
                if (j > 2)
                {
                    printf("rra\n");
                    a = reverse_rotate(a);
                }
                else
                {
                    printf("ra\n");
                    a = rotate_ab(a);
                }
            }
            else
            {
                printf("ra\n");
                a = rotate_ab(a);
            }
        }
    }
    j = check_pos(a, 0);
    while (is_sorted(a) == 0)
    {
        if (j > 2)
        {
            printf("rra\n");
            a = reverse_rotate(a);
        }
        else
        {
            printf("ra\n");
            a = rotate_ab(a);
        }
    }
    return (a);
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
            printf("Error duplication\n");
            exit(1);
        }
        i++;
    }
    
}

int     main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    t_stack *tmp;
    t_op    *q;
    t_op    *tp;
    int     i;
    int     size;
    int     *tab;

    a = NULL;
    b = NULL;
    q = NULL;
    i = 0;

    size = valid_parse(argv);
    tab = malloc(sizeof(int) *size);
    tab = file_tab(tab, argv);
    tab = indexxx(tab, size);
    a = fill(a, tab, size - 1);
    check_duplicate(a, size);
    if(size == 3)
        a = sort3(tab, size);
    else if (size == 5)
        a = sort5(a, tab, size);
    else 
    {
        pushswap(size, a, b);
        // while (q)
        // {
        //     printf("%s\n", q->oper);
        //     q = q->next;
        // }
    }

    // tmp = a;
    // while (a != NULL)
    // {
    //     tmp = a;
    //     a = a->next;
    //     free(tmp);
    // }
    // free(a);
    // free(tab);
    // while (q)
    // {
    //     tp = q;
    //     q = q->next;
    //     free(tp);
    // }
    system("leaks push_swap");
    //while(1);
}