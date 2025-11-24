/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evieito- <evieito-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:41:34 by evieito-          #+#    #+#             */
/*   Updated: 2025/11/23 15:41:35 by evieito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	/* perform swaps without calling sa/sb to avoid duplicate output
	 * (sa/sb already write their own op). */
	if (a && *a && (*a)->next)
	{
		int tmp = (*a)->value;
		(*a)->value = (*a)->next->value;
		(*a)->next->value = tmp;
	}
	if (b && *b && (*b)->next)
	{
		int tmp = (*b)->value;
		(*b)->value = (*b)->next->value;
		(*b)->next->value = tmp;
	}
	write_op("ss");
}
