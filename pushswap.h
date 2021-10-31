#ifndef PUSHSWAP_H
#define PUSHSWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>


typedef struct s_stack
{
    int val;
    struct s_stack *next;
} t_stack;

typedef struct s_op
{
    char *oper;
    struct s_op *next;
} t_op;
#endif