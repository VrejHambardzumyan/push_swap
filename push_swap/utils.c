#include "push_swap.h"

/*ete taza nod enq kpcnum orinka stack_a in, petqa amenaverjin 
nody update anenq vor nayi taza kcac nodi vra, te arden mer verjin 
nody samo saboy nayuma headin, menka heady poxenq klni ok
*/


static void sa(t_node **stack_a, bool print)
{
	t_node *first;
	t_node *second;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	first = *stack_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
	if (print)
		ft_printf("sa\n");
}
static void sb(t_node **stack_b, bool print)
{
	t_node *first;
	t_node *second;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	first = *stack_b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_b = second;
	if (print)
		ft_printf("sb\n");
}
static void ss(t_node **stack_a, t_node **stack_b, bool print)
{
	sa(stack_a, false);
	sb(stack_b, false);
	if (print)
		ft_printf("ss\n");
}
static void pa(t_node **stack_a, t_node **stack_b, bool print)
{
	t_node *temp;

	if (*stack_b == NULL)
		return ;
	if ((*stack_b)->next == *stack_b) // mi node a stack_b-um
	{
		temp = *stack_b;
		if (*stack_a == NULL) //u ete stack_a-n datark a
		{
			temp->next = temp;
			*stack_a = temp;
		}
		else//ete stack_a-n datark chi
		{
			t_node *curr;

			curr = *stack_a;
			while (curr->next != *stack_a)
				curr = curr->next;
			temp->next = *stack_a;
			curr->next = temp;
			*stack_a = temp;
		}

	}
	else//mi node chi stack_b-um
	{
		t_node *curr;

		curr = *stack_b;
		while (curr->next != *stack_b)
			curr = curr->next;
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		
		temp->next = *stack_a;
		*stack_a = temp;
	}
	
	if (print)
		ft_printf("pa\n");
}
static void pb(t_node **stack_a, t_node **stack_b, bool print)
{
	t_node *temp;

	if (*stack_a == NULL)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
	if (print)
		ft_printf("pb\n");
}
static void ra(t_node **stack_a, bool print)
{
	t_node *first;
	t_node *last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	first = *stack_a;
	last = *stack_a;
	while (last->next != *stack_a)
		last = last->next;
	*stack_a = first->next;
	last->next = first;
	first->next = *stack_a;
	if (print)
		ft_printf("ra\n");
}
static void rb(t_node **stack_b, bool print)
{
	t_node *first;
	t_node *last;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	first = *stack_b;
	last = *stack_b;
	while (last->next != *stack_b)
		last = last->next;
	*stack_b = first->next;
	last->next = first;
	first->next = *stack_b;
	if (print)
		ft_printf("rb\n");
}
static void rr(t_node **stack_a, t_node **stack_b, bool print)
{
	ra(stack_a, false);
	rb(stack_b, false);
	if (print)
		ft_printf("rr\n");
}
static void rra(t_node **stack_a, bool print)
{
	t_node *first;
	t_node *last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	first = *stack_a;
	last = *stack_a;
	while (last->next->next != *stack_a)
		last = last->next;
	*stack_a = last->next;
	last->next = first;
	first->next = *stack_a;
	if (print)
		ft_printf("rra\n");
}
static void rrb(t_node **stack_b, bool print)
{
	t_node *first;
	t_node *last;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	first = *stack_b;
	last = *stack_b;
	while (last->next->next != *stack_b)
		last = last->next;
	*stack_b = last->next;
	last->next = first;
	first->next = *stack_b;
	if (print)
		ft_printf("rrb\n");
}
static void rrr(t_node **stack_a, t_node **stack_b, bool print)
{
	rra(stack_a, false);
	rrb(stack_b, false);
	if (print)
		ft_printf("rrr\n");
}

static int stack_length(t_node *stack)
{
	int count;
	t_node *current;

	count = 0;
	current = stack;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}