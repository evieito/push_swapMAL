#include "push_swap.h"
#include <stdlib.h>
#include <errno.h>

void	free_tokens(char **tokens, int argc)
{
	int	i;

	if (!tokens)
		return ;
	if (argc == 2)
	{
		i = 0;
		while (tokens[i])
		{
			free(tokens[i]);
			i++;
		}
	}
	free(tokens);
}

int	count_words(char *s)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		if (!s[i])
			break ;
		count++;
		while (s[i] && s[i] != ' ')
			i++;
	}
	return (count);
}

void	fill_stack_from_tokens(t_node **a, char **tokens, int argc)
{
	int i;

	i = 0;
	while (tokens[i])
	{
		process_token(a, tokens[i], tokens, argc);
		i++;
	}
	free_tokens(tokens, argc);
}

void	process_token(t_node **a, char *token, char **tokens, int argc)
{
	errno = 0;
	if (!is_number(token))
	{
		free_tokens(tokens, argc);
		print_error();
	}
	long val;

	val = ft_atol_error(token);
	if (errno == ERANGE)
	{
		free_tokens(tokens, argc);
		print_error();
	}
	if (!push_back(a, (int)val))
	{
		free_tokens(tokens, argc);
		free_stack(a);
		print_error();
	}
}
