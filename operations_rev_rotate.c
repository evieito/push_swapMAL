/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rev_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evieito- <evieito-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:41:24 by evieito-          #+#    #+#             */
/*   Updated: 2025/11/23 15:41:26 by evieito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	write_op(char *op)
{
	write(1, op, 3);
	write(1, "\n", 1);
}

void	rra(t_node **a)
{
	t_node	*prev;
	t_node	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	prev = NULL;
	last = *a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *a;
	*a = last;
	write_op("rra");
}

void	rrb(t_node **b)
{
	t_node	*prev;
	t_node	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	prev = NULL;
	last = *b;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *b;
	*b = last;
	write_op("rrb");
}

void	rrr(t_node **a, t_node **b)
{
	/* perform reverse rotations inline to avoid duplicate outputs from
	 * rra/rrb and emit only one "rrr" */
	if (a && *a && (*a)->next)
	{
		t_node *prev = NULL;
		t_node *last = *a;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = *a;
		*a = last;
	}
	if (b && *b && (*b)->next)
	{
		t_node *prev = NULL;
		t_node *last = *b;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = *b;
		*b = last;
	}
	write_op("rrr");
}
