/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evieito- <evieito-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 17:12:48 by evieito-          #+#    #+#             */
/*   Updated: 2025/11/23 17:40:01 by evieito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_tokens(t_node **a, char **tokens)
{
	int		i;
	long	val;

	i = 0;
	while (tokens[i])
	{
		if (!is_number(tokens[i]))
			print_error();
		val = ft_atol_error(tokens[i]);
		push_back(a, (int)val);
		i++;
	}
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
	process_tokens(a, tokens);
	if (argc == 2)
	{
		i = 0;
		while (tokens[i])
			free(tokens[i++]);
	}
	free(tokens);
}
