#include "push_swap.h"


static void	rotate_a_to_pos(t_node **a, int pos)
{
    if (pos <= stack_size(*a) / 2)
    {
        while (pos > 0)
        {
            ra(a);
            pos--;
        }
    }
    else
    {
        pos = stack_size(*a) - pos;
        while (pos > 0)
        {
            rra(a);
            pos--;
        }
    }
}

static void	rotate_b_to_pos(t_node **b, int pos)
{
    if (pos <= stack_size(*b) / 2)
    {
        while (pos > 0)
        {
            rb(b);
            pos--;
        }
    }
    else
    {
        pos = stack_size(*b) - pos;
        while (pos > 0)
        {
            rrb(b);
            pos--;
        }
    }
}

/* push_chunks_to_b: mueve elementos de A a B por chunks definidos
    usando min_idx/max_idx y chunk_size. */
void	push_chunks_to_b(t_node **a, t_node **b, int chunk_size, int size)
{
    int min_idx;
    int max_idx;
    int pos;

    min_idx = 0;
    max_idx = chunk_size - 1;
    while (*a)
    {
        pos = find_pos_in_range(*a, min_idx, max_idx);
        if (pos == -1)
        {
            min_idx += chunk_size;
            max_idx += chunk_size;
            if (max_idx > size - 1)
                max_idx = size - 1;
            continue;
        }
        rotate_a_to_pos(a, pos);
        pb(a, b);
        if ((*b)->index < min_idx + (chunk_size / 2))
            rb(b);
    }
}

/* rebuild_a_from_b: popula A desde B ordenando por máximo índice. */
void	rebuild_a_from_b(t_node **a, t_node **b)
{
    int pos;

    while (stack_size(*b) > 0)
    {
        pos = find_pos_max(*b);
        rotate_b_to_pos(b, pos);
        pa(a, b);
    }
}

/* search helpers moved to radix_search.c */
