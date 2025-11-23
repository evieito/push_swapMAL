/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evieito- <evieito-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:43:43 by evieito-          #+#    #+#             */
/*   Updated: 2025/11/23 18:18:52 by evieito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_pos(t_node *a)
{
	int		min;
	int		pos;
	int		i;

	min = a->value;
	pos = 0;
	i = 0;
	while (a)
	{
		if (a->value < min)
		{
			min = a->value;
			pos = i;
		}
		i++;
		a = a->next;
	}
	return (pos);
}

static void	sort_three(t_node **a)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->value;
	y = (*a)->next->value;
	z = (*a)->next->next->value;
	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && y < z && x > z)
		ra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x < y && y > z && x > z)
		rra(a);
}

static void	reduce_to_three(t_node **a, t_node **b)
{
	int	pos;
	int	n;

	while (stack_size(*a) > 3)
	{
		pos = find_min_pos(*a);
		n = stack_size(*a);
		if (pos == 0)
			pb(a, b);
		else if (pos <= n / 2)
			while (pos--)
				ra(a);
		else
		{
			pos = n - pos;
			while (pos--)
				rra(a);
		}
		if (stack_size(*a) > 3)
			pb(a, b);
	}
}

void	small_sort(t_node **a, t_node **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a);
		return ;
	}
	if (size == 3)
		return (sort_three(a));
	reduce_to_three(a, b);
	sort_three(a);
	while (*b)
	{
		/* insertar cada elemento de b en la posicion correcta de a con menos movimientos */
	int n = stack_size(*a);
		t_node *tmp = *a;
		int val = (*b)->value;

		/* buscar el lugar entre tmp y tmp->next donde val debe ir */
		if (!tmp || !tmp->next)
		{
			pa(a, b);
			continue;
		}
		/* caso donde val es menor que todos o mayor que todos -> insert after max element */
		int i = 0;
		int insert_pos = -1;
		int max = tmp->value;
		t_node *t = tmp;
		while (t)
		{
			if (t->value > max)
				max = t->value;
			t = t->next;
		}
		if (val < (*a)->value || val > max)
		{
			/* insertar despues del max (pos of max + 1) */
			t = *a;
			i = 0;
			while (t->value != max)
			{
				i++;
				t = t->next;
			}
			insert_pos = (i + 1) % n;
		}
		else
		{
			t = *a;
			i = 0;
			while (t->next)
			{
				if (t->value < val && val < t->next->value)
				{
					insert_pos = i + 1;
					break;
				}
				i++;
				t = t->next;
			}
		}

		if (insert_pos == -1)
		{
			pa(a, b);
			continue;
		}

		/* rotar a el minimo de pasos para dejar la posicion de insercion en la cima */
		if (insert_pos <= n / 2)
		{
			while (insert_pos--)
				ra(a);
		}
		else
		{
			insert_pos = n - insert_pos;
			while (insert_pos--)
				rra(a);
		}
		pa(a, b);
	}
}
