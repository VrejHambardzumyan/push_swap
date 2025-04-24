#include "push_swap.h"
#include "libft.h"

int main(int argc, char *argv[])
{
    t_node *stack_a;
    t_node *stack_b;

    stack_a = NULL;
    stack_b = NULL;

    char **arr = NULL;
    if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
        return (1);
    else if (argc == 2)
        arr = ft_split(argv[1], ' ');

    stack_init(*stack_a,arr);
    if (!is_sorted(stack_a))
    {
        if(stack_length(stack_a) == 2)
            sa(&stack_a,false);
        else if(stack_length(stack_a) == 3)
            sort_three(&stack_a);
        else 
            sort_stacks(&stack_a, &stack_b);
    }

    free_stack(stack_a);
}