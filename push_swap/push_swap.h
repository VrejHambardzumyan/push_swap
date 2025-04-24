#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <../Libft/libft.h>
#include <../Printf/ft_printf.h>


typedef struct s_node
{
    int value;
    int index;
    int push_cost;
    bool median;
    bool  cheapest;

    struct s_node   *target_node;
    struct s_node   *next;
}   t_node;

//error handling

//stack initialization

//node initialization

//stack operations

//command operations

//algorithm 

#endif