#include "push_swap.h"
#include <stdlib.h>

t_node	*new_node(int value)
{
	t_node	*node;
	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->next = NULL;
	return (node);
}

int	push_back(t_node **stack, int value)
{
	t_node	*node;
	t_node	*tmp;

	node = new_node(value);
	if (!node)
		return (0);
	if (!*stack)
	{
		*stack = node;
		return (1);
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	return (1);
}

int	push_front(t_node **stack, int value)
{
	t_node	*node;

	node = new_node(value);
	if (!node)
		return (0);
	node->next = *stack;
	*stack = node;
	return (1);
}

int	stack_size(t_node *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
