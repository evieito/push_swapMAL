#include "push_swap.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/* free_tokens and count_words moved to parse_utils.c to keep
   this file within Norminette limits. */

static char	**split_spaces(char *s)
{
	char	**res;
	int		i; 
	int		j; 
	int		start; 
	int		words; 

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
		{
			int k;

			k = 0;
			while (k < j)
			{
				free(res[k]);
				k++;
			}
			free(res);
			return (NULL);
		}
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
	char **tokens;
	int i;

	tokens = malloc(sizeof(char *) * argc);
	if (!tokens)
		return (NULL);
	i = 1;
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

	if (argc < 2)
		return ;

	tokens = get_tokens(argc, argv);
	if (!tokens)
		print_error();
	{
		int	dup_res;

		dup_res = has_duplicates(tokens);
		if (dup_res == -1)
		{
			free_tokens(tokens, argc);
			print_error();
		}
		if (dup_res == 1)
		{
			free_tokens(tokens, argc);
			print_error();
		}
	}
	fill_stack_from_tokens(a, tokens, argc);
}
