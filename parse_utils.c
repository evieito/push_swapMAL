/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evieito- <evieito-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:42:37 by evieito-          #+#    #+#             */
/*   Updated: 2025/11/23 17:40:01 by evieito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static char	*get_word(char *s, int *i)
{
	int		start;
	char	*word;

	start = *i;
	while (s[*i] && s[*i] != ' ')
		(*i)++;
	word = strndup(&s[start], *i - start);
	return (word);
}

static char	**split_spaces(char *s)
{
	char	**res;
	int		words;
	int		i;
	int		j;

	words = count_words(s);
	i = 0;
	j = 0;
	res = malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		if (!s[i])
			break ;
		res[j] = get_word(s, &i);
		if (!res[j])
			return (NULL);
		j++;
	}
	res[j] = NULL;
	return (res);
}

char	**get_tokens(int argc, char **argv)
{
	int		i;
	char	**tokens;

	i = 1;
	if (argc == 2)
	{
		return (split_spaces(argv[1]));
	}
	tokens = malloc(sizeof(char *) * argc);
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
