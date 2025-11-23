#include "push_swap.h"
#include <unistd.h>

static void	write_op(char *op)
{
	write(1, op, 2);
	write(1, "\n", 1);
}

void	sa(t_node **a)
{
	int	tmp;

	if (!a || !*a || !(*a)->next)
		return ;
	tmp = (*a)->value;
	(*a)->value = (*a)->next->value;
	(*a)->next->value = tmp;
	write_op("sa");
}

void	sb(t_node **b)
{
	int	tmp;

	if (!b || !*b || !(*b)->next)
		return ;
	tmp = (*b)->value;
	(*b)->value = (*b)->next->value;
	(*b)->next->value = tmp;
	write_op("sb");
}

void	ss(t_node **a, t_node **b)
{
	sa(a);
	sb(b);
	write_op("ss");
}
