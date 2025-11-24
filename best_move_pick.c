#include "push_swap.h"

/* pick_best_node: encuentra el mejor nodo dentro del rango [min_idx,max_idx]
   según la métrica de compute_cost. */
t_node	*pick_best_node(t_node *a, t_node *b, int min_idx, int max_idx)
{
    t_node *cur;
    t_node *best_node;
    int i;
    int a_sz;
    int b_sz;
    int best_cost;

    best_cost = -1;
    best_node = NULL;
    cur = a;
    i = 0;
    a_sz = stack_size(a);
    b_sz = stack_size(b);
    while (cur)
    {
        if (cur->index >= min_idx && cur->index <= max_idx)
        {
            int cost;

            cost = node_cost(b, cur, i, a_sz, b_sz);
            if (best_cost == -1 || cost < best_cost)
            {
                best_cost = cost;
                best_node = cur;
            }
        }
        i++;
        cur = cur->next;
    }
    return (best_node);
}

/* perform_moves_for_node: ejecuta las rotaciones necesarias para llevar
   best_node a la cima de A y posicionar B correctamente, luego hace pb. */
void	perform_moves_for_node(t_node **a, t_node **b, t_node *best_node)
{
    int cur_pos;
    int cur_bpos;
    int a_sz;
    int b_sz;
    int i;

    cur_pos = get_pos_of_node(*a, best_node);
    cur_bpos = find_insert_pos_b(*b, best_node->index);
    a_sz = stack_size(*a);
    b_sz = stack_size(*b);
    if (cur_pos <= a_sz / 2)
        i = cur_pos;
    else
        i = cur_pos - a_sz;
    if (cur_bpos > b_sz / 2)
        cur_bpos = cur_bpos - b_sz;
    if ((i >= 0 && cur_bpos >= 0) || (i <= 0 && cur_bpos <= 0))
    {
        if (i > 0)
        {
            handle_both_positive(a, b, i, cur_bpos);
        }
        else
        {
            handle_both_negative(a, b, i, cur_bpos);
        }
    }
    else
    {
        if (i > 0)
            while (i-- > 0)
                ra(a);
        else
            while (i++ < 0)
                rra(a);
        if (cur_bpos > 0)
            while (cur_bpos-- > 0)
                rb(b);
        else
            while (cur_bpos++ < 0)
                rrb(b);
    }
    pb(a, b);
}

int	node_cost(t_node *b, t_node *cur, int pos, int a_sz, int b_sz)
{
    int cur_bpos;

    cur_bpos = find_insert_pos_b(b, cur->index);
    return (compute_cost(pos, a_sz, cur_bpos, b_sz));
}

void	handle_both_positive(t_node **a, t_node **b, int i, int cur_bpos)
{
    while (i > 0 && cur_bpos > 0)
    {
        rr(a, b);
        i--;
        cur_bpos--;
    }
    while (i > 0)
    {
        ra(a);
        i--;
    }
    while (cur_bpos > 0)
    {
        rb(b);
        cur_bpos--;
    }
}

void	handle_both_negative(t_node **a, t_node **b, int i, int cur_bpos)
{
    while (i < 0 && cur_bpos < 0)
    {
        rrr(a, b);
        i++;
        cur_bpos++;
    }
    while (i < 0)
    {
        rra(a);
        i++;
    }
    while (cur_bpos < 0)
    {
        rrb(b);
        cur_bpos++;
    }
}
