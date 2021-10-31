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
void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;

	while (str[i])
	{
		ft_putchar(str[i]);
		i += 1;
	}
}

int     is_digit(char *str)
{
    int i;

    i = 0;   

    if(str[i]== '-' || str[i] == '+')
        i++;
    while(str[i])
    {
        if(!(str[i] >= '0' && str[i] <= '9'))
        {
            ft_putstr("INVALID arguments\n");
            exit(1);
        }
        i++;
    }
    return(1);
}
int    valid_parse(char **str)
{
    int i;

    i = 1;
    while(str[i] && is_digit(str[i]))
        i++;
    return(i-1);
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
    tab = malloc(sizeof(int) *size);
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

t_op    *addop(t_op *queue, char *str)
{
    t_op *new;
    t_op *tmp;

    new = (t_op*)malloc(sizeof(t_op));
    if (new)
    {
        new->next = NULL;
        new->oper    = str;
        if (queue == NULL)
            return new;
        else
        {
            tmp = queue;
            while (tmp->next)
                tmp = tmp->next;
            tmp->next = new;
        }
    }
    return (queue);
}

t_stack      *ft_push(t_stack *pile, int data)
{
    t_stack *new;

    new = (t_stack *)malloc(sizeof(t_stack));
    if(new)
    {
        new->val = data;
        new->next = pile;
        return new;
    }
    return NULL;
}

t_stack  *rotate_ab(t_stack *p)
{
    t_stack  *tmp;
    t_stack  *new;
    int     val;

    val = p->val;
    p = p->next;
    
    tmp = p;
    new = (t_stack*)malloc(sizeof (t_stack)); 
    if (new)
    {
        new->next = NULL;
        new->val = val;
        while (p->next)
        {
            p = p->next;
        }
        p->next = new;
    }
    return tmp;
}

void      ft_push_ab(t_stack **a, t_stack **b)
{
    t_stack *mem;
    int value;
    if (a)
    {
        value = (*a)->val;
        //printf("=> %d\n", val);
        *b = ft_push(*b, value);
        *a = (*a)->next;
        //free(*a);
        //*a = mem;
    }
}

int     b_is_empty(t_stack *b)
{
    if(!b)
        return(1);
    return(0);
}

int     stack_size(t_stack *a)
{
    int i;

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
    while(i < maxbits)
    {
        j = 0;
        k = 0;
       
        while(j < size)
        {
            if((((a->val >> i) % 2) && 1) == 1)
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
    return(queue);
}

t_stack   *fill(t_stack *a, int *tab, int size)
{
    int i;
    t_stack *tmp;

    
    i = 0;
    //printf("size %d\n",size);
    while(i <= size)
    {
        a = ft_push(a, tab[size]);
        size--;
    }
// tmp = a;
// while (a)
//     {
//         printf("check %d ",a->val);
//         a = a->next;
//     }
//     printf("\n");
    return(a);
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
    // while (i < size)
    // {
    //     printf("%d ", tab[i]);
    //     i++;
    // }
    //printf("\n");
    a = fill(a, tab, size - 1);
    // tmp = a;
    // while (tmp)
    // {
    //     printf("%d ",tmp->val);
    //     tmp = tmp->next;
    // }
    q = pushswap(size, a, b);
    while (q)
    {
        printf("%s\n", q->oper);
        q = q->next;
    }
}