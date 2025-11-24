#include "push_swap.h"
#include <unistd.h>

static void	write_op(char *op)
{
	write(1, op, 2);
	write(1, "\n", 1);
}

static void	swap_nodes(t_node **stack)
{
	int	tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
}

void	sa(t_node **a)
{
	swap_nodes(a);
	write_op("sa");
}

void	sb(t_node **b)
{
	swap_nodes(b);
	write_op("sb");
}

void	ss(t_node **a, t_node **b)
{
	swap_nodes(a);
	swap_nodes(b);
	write_op("ss");
}
