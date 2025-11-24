#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

t_node	*new_node(int value);
int	push_back(t_node **stack, int value);
int	push_front(t_node **stack, int value);
void	free_stack(t_node **stack);
int		stack_size(t_node *stack);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);
void	push_swap(t_node **a, t_node **b);
void	small_sort(t_node **a, t_node **b);
void	radix_sort(t_node **a, t_node **b);
void	best_move_sort(t_node **a, t_node **b);
void	assign_indices_local(t_node *a);
int	find_insert_pos_b(t_node *b, int idx);
int	get_pos_of_node(t_node *s, t_node *target);
int	compute_cost(int a_pos, int a_size, int b_pos, int b_size);
int	find_and_handle_best_node(t_node **a, t_node **b, int min_idx, int max_idx);
t_node	*pick_best_node(t_node *a, t_node *b, int min_idx, int max_idx);
void	perform_moves_for_node(t_node **a, t_node **b, t_node *best_node);
int	get_chunk_target(int size);
int	node_cost(t_node *b, t_node *cur, int pos, int a_sz, int b_sz);
void	handle_both_positive(t_node **a, t_node **b, int i, int cur_bpos);
void	handle_both_negative(t_node **a, t_node **b, int i, int cur_bpos);
int		is_sorted(t_node *a);
void	print_error(void);
int		is_number(const char *s);
long	ft_atol_error(const char *s);
int		has_duplicates(char **tokens);
void	parse_args(t_node **a, int argc, char **argv);
void	free_tokens(char **tokens, int argc);
int	count_words(char *s);
int	find_min_pos(t_node *a);
void	push_min_to_b(t_node **a, t_node **b);
void	fill_stack_from_tokens(t_node **a, char **tokens, int argc);
void	process_token(t_node **a, char *token, char **tokens, int argc);
void	push_chunks_to_b(t_node **a, t_node **b, int chunk_size, int size);
void	rebuild_a_from_b(t_node **a, t_node **b);
int	find_pos_in_range(t_node *a, int min, int max);
int	find_pos_max(t_node *b);

#endif
