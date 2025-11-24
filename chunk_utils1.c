#include "push_swap.h"

int		size_to_chunks(int size)
{
	if (size <= 50)
		return (3);
	if (size <= 150)
		return (4);
	if (size <= 500)
		return (11);
	return (20);
}
static int	compute_min_index(t_node *a)
{
	t_node *t;
	int min;

	if (!a)
		return (0);
	t = a;
	min = a->index;
	while (t)
	{
		if (t->index < min)
			min = t->index;
		t = t->next;
	}
	return (min);
}

static int	compute_max_index(t_node *b)
{
	t_node *t;
	int max;

	if (!b)
		return (0);
	t = b;
	max = b->index;
	while (t)
	{
		if (t->index > max)
			max = t->index;
		t = t->next;
	}
	return (max);
}

int		find_pos_in_a(t_node *a, int index)
{
	int min;
	t_node *t;
	int i;

	if (!a)
		return (0);
	min = compute_min_index(a);
	if (index < min)
	{
		t = a;
		i = 0;
		while (t && t->index != min)
		{
			i++;
			t = t->next;
		}
		return (i);
	}
	t = a;
	i = 0;
	while (t && t->next)
	{
		if (t->index < index && index < t->next->index)
			return (i + 1);
		i++;
		t = t->next;
	}
	return (0);
}

int		find_pos_in_b(t_node *b, int index)
{
	int max;
	int min;
	t_node *t;
	int pos_max;
	int i;

	if (!b)
		return (0);
	max = compute_max_index(b);
	min = compute_min_index(b);
	pos_max = 0;
	i = 0;
	t = b;
	while (t)
	{
		if (t->index == max)
			pos_max = i;
		t = t->next;
		i++;
	}
	if (index > max)
		return (pos_max);
	if (index < min)
	{
		t = b;
		i = 0;
		while (t && t->index != min)
		{
			i++;
			t = t->next;
		}
		return ((i + 1) % (stack_size(b)));
	}
	t = b;
	i = 0;
	while (t && t->next)
	{
		if (t->index > index && index > t->next->index)
			return (i + 1);
		i++;
		t = t->next;
	}
	return (0);
}
