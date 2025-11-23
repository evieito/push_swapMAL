/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evieito- <evieito-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:42:15 by evieito-          #+#    #+#             */
/*   Updated: 2025/11/23 17:21:35 by evieito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	write_op(char *op)
{
	write(1, op, 2);
	write(1, "\n", 1);
}

void	ra(t_node **a)
{
	t_node	*first;
	t_node	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	last = *a;
	while (last->next)
		last = last->next;
	*a = first->next;
	first->next = NULL;
	last->next = first;
	write_op("ra");
}

void	rb(t_node **b)
{
	t_node	*first;
	t_node	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	last = *b;
	while (last->next)
		last = last->next;
	*b = first->next;
	first->next = NULL;
	last->next = first;
	write_op("rb");
}

void	rr(t_node **a, t_node **b)
{
	ra(a);
	rb(b);
	write_op("rr");
}
