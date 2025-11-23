/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evieito- <evieito-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:43:37 by evieito-          #+#    #+#             */
/*   Updated: 2025/11/23 18:36:42 by evieito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_indices(t_node *a)
{
	t_node	*i;
	t_node	*j;
	int		count;

	i = a;
	while (i)
	{
		count = 0;
		j = a;
		while (j)
		{
			if (j->value < i->value)
				count++;
			j = j->next;
		}
		i->index = count;
		i = i->next;
	}
}

void	radix_pass(t_node **a, t_node **b, int bit, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (((*a)->index >> bit) & 1)
			ra(a);
		else
			pb(a, b);
		i++;
	}
	while (*b)
		pa(a, b);
}

void	radix_sort(t_node **a, t_node **b)
{
	int		size;
	int		max;
	int		max_bits;
	int		bit;
	t_node	*tmp;

	size = stack_size(*a);
	max = 0;
	max_bits = 0;
	tmp = *a;
	assign_indices(*a);
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	bit = 0;
	while (bit < max_bits)
	{
		radix_pass(a, b, bit, size);
		bit++;
	}
}
