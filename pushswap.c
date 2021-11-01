#include "pushswap.h"

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

int     valid_parse(char **str)
{
    int i;

    i = 1;
    while(str[i] && is_digit(str[i]))
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
    return(tab);
}

t_op        *addop(t_op *queue, char *str)
{
    t_op    *new;
    t_op    *tmp;

    new = (t_op*)malloc(sizeof(t_op));
    if (new)
    {
        new->next = NULL;
        new->oper = str;
        if(queue == NULL)
            return(new);
        else
        {
            tmp = queue;
            while (tmp->next)
                tmp = tmp->next;
            tmp->next = new;
        }
    }
    return(queue);
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
    p = p->next;

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
    t_stack *mem;
    int value;
    if(a)
    {
        value = (*a)->val;
        //printf("%d\n", val);
        *b = ft_push(*b, value);
        *a = (*a)->next;
        //free(*a);
        //*a = mem;
    }
}

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

t_op    *pushswap(int size, t_stack *a, t_stack *b)
{
    int maxbits;
    int i;
    int j;
    int k;
    int s;
    t_stack *tmp;
    t_op *queue;

    queue = NULL;
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
            if ((((a->val >> i) %2 ) && 1 ) == 1)
            {
                a = rotate_ab(a);
                queue = addop(queue, "ra");
            }
            else
            {
                ft_push_ab(&a, &b);
                queue = addop(queue, "pb");
            }
            j++;
        }
        while(!(b_is_empty(b)))
        {
            ft_push_ab(&b, &a);
            queue = addop(queue, "pa");
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
    return (queue);
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
//     t_stack *tmp;

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
    tmp->next = NULL; 
    return (new);
}

t_stack    *sort5(t_stack *a, int *tab, int size)
{
    t_stack *b;
    t_stack *tmp;
    int j;

    b = NULL;
    b = ft_push(b, tab[0]);
    b = ft_push(b, tab[1]);
    printf("pb\npb\n");
    
    a = sort3(tab + 2, 3);
    if (b->val < b->next->val)
    {
        printf("rb\n");
        b = rotate_ab(b);
    }
    while (b)
    {   //printf(" a.val %d b.val %d\n", a->val, b->val);
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
            j=0;
            if (b->val <= 3)
            {
                tmp = a;
                while (tmp)
                {
                    if (tmp->val == b->val + 1)
                        break;
                    j++;
                    tmp = tmp->next;
                }
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
    j=0;
    tmp = a;
    while (tmp)
    {
        if (tmp->val == 0)
            break;
        j++;
        tmp = tmp->next;
    }
    while (is_sorted(a) == 0)
    {
        if (j > 2)
        {
            // tmp = a;
            // while (tmp)
            // {
            //     printf("a: %d\n", tmp->val);
            //     tmp = tmp->next;
            // }
            // printf("\n");
            printf("rra\n");
            a = reverse_rotate(a);
            // tmp = a;
            // while (tmp)
            // {
            //     printf("a: %d\n", tmp->val);
            //     tmp = tmp->next;
            // }
            // printf("\n");
            // exit(1);
        }
        else
        {
            printf("ra\n");
            a = rotate_ab(a);
        }
    }
    return (a);
}

int     main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    t_stack *tmp;
    t_op    *q;
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
    if(size == 3)
        a = sort3(tab, size);
    else if (size == 5)
        a = sort5(a, tab, size);
    else 
    {
        q = pushswap(size, a, b);
        while (q)
        {
        printf("%s\n", q->oper);
        q = q->next;
        }
    }
}