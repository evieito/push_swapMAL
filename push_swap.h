#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

t_node	*new_node(int value);
void	push_back(t_node **stack, int value);
void	push_front(t_node **stack, int value);
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
int		is_sorted(t_node *a);
void	print_error(void);
int		is_number(const char *s);
long	ft_atol_error(const char *s);
int		has_duplicates(char **tokens);
void	parse_args(t_node **a, int argc, char **argv);

#endif
