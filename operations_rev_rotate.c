#include "push_swap.h"
#include <unistd.h>

static void	write_op(char *op)
{
	write(1, op, 3);
	write(1, "\n", 1);
}

static void	rev_rotate_nodes(t_node **stack)
{
	t_node	*prev;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_node **a)
{
	rev_rotate_nodes(a);
	write_op("rra");
}

void	rrb(t_node **b)
{
	rev_rotate_nodes(b);
	write_op("rrb");
}

void	rrr(t_node **a, t_node **b)
{
	rev_rotate_nodes(a);
	rev_rotate_nodes(b);
	write_op("rrr");
}
