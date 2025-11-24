#include "push_swap.h"
#include <unistd.h>

static void	write_op(char *op)
{
	write(1, op, 2);
	write(1, "\n", 1);
}

static void	rotate_nodes(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_node **a)
{
	rotate_nodes(a);
	write_op("ra");
}

void	rb(t_node **b)
{
	rotate_nodes(b);
	write_op("rb");
}

void	rr(t_node **a, t_node **b)
{
	rotate_nodes(a);
	rotate_nodes(b);
	write_op("rr");
}
