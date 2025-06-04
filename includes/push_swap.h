/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourlogin <your@email.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 00:00:00 by yourlogin         #+#    #+#             */
/*   Updated: 2025/05/05 00:00:00 by yourlogin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				curr_position;
	int				final_index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_node	*target_node;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

// Argument handling
char	*merge_arg(int argc, char *argv[]);
int		validate_arguments(int argc, char *argv[]);
int		calculate_total_length(int argc, char *argv[]);

// Error handling
void	free_arr(char *argv[]);
void	free_stack(t_node **stack);
void	free_error(t_node **stack, char *argv[], bool flag);
int		error_arg(char *arg);
int		error_duplicate(t_node *stack, int value);

// Stack handling
void	create_stack(t_node **stack, char **arr, bool flag);
void	set_curr_position(t_node *stack);
void	init_nodes(t_node *stack_a, t_node *stack_b);

// Stack initialization
t_node	*find_the_tail(t_node *stack);
t_node	*return_cheapest(t_node *stack);
t_node	*find_min(t_node *stack);
bool	stack_sorted(t_node *stack);
void	add_node(t_node **stack, int value);
void	finish_rotate(t_node **stack, t_node *top_node, char stack_name);
int		stack_length(t_node *stack);

// Commands
void	ra(t_node **stack_a, bool print);
void	rb(t_node **stack_b, bool print);
void	rr(t_node **stack_a, t_node **stack_b, bool print);

void	rra(t_node **stack_a, bool print);
void	rrb(t_node **stack_b, bool print);
void	rrr(t_node **stack_a, t_node **stack_b, bool print);

void	sb(t_node **stack_b, bool print);
void	sa(t_node **stack_a, bool print);
void	ss(t_node **stack_a, t_node **stack_b, bool print);

void	pa(t_node **stack_a, t_node **stack_b, bool print);
void	pb(t_node **stack_a, t_node **stack_b, bool print);

// Algorithm
void	sort_three(t_node **stack);
void	handle_five(t_node **stack_a, t_node **stack_b);
void	sort_stacks(t_node **stack_a, t_node **stack_b);

#endif
