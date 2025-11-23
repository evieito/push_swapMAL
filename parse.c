#include "push_swap.h"
#include <stdlib.h>

static int	count_words(char *s)
{
	int	i;
	int	count;

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

static char	**split_spaces(char *s)
{
	char	**res;
	int		words;
	int		i;
	int		j;
	int		start;

	words = count_words(s);
	res = malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		if (!s[i])
			break ;
		start = i;
		while (s[i] && s[i] != ' ')
			i++;
		res[j] = strndup(&s[start], i - start);
		if (!res[j])
			return (NULL);
		j++;
	}
	res[j] = NULL;
	return (res);
}

static char	**get_tokens(int argc, char **argv)
{
	if (argc == 2)
	{
		return (split_spaces(argv[1]));
	}
	char **tokens = malloc(sizeof(char *) * argc);
	int i = 1;

	if (!tokens)
		return (NULL);
	while (i < argc)
	{
		tokens[i - 1] = argv[i];
		i++;
	}
	tokens[i - 1] = NULL;
	return (tokens);
}

void	parse_args(t_node **a, int argc, char **argv)
{
	char	**tokens;
	int		i;

	if (argc < 2)
		return ;

	tokens = get_tokens(argc, argv);
	if (!tokens)
		print_error();
	if (has_duplicates(tokens))
		print_error();
	i = 0;
	while (tokens[i])
	{
		if (!is_number(tokens[i]))
			print_error();
		long val = ft_atol_error(tokens[i]);
		push_back(a, (int)val);
		i++;
	}
	if (argc == 2)
	{
		i = 0;
		while (tokens[i])
			free(tokens[i++]);
	}
	free(tokens);
}
