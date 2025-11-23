/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evieito- <evieito-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:43:07 by evieito-          #+#    #+#             */
/*   Updated: 2025/11/23 18:36:42 by evieito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_node **a, t_node **b)
{
	int	size;

	if (is_sorted(*a))
		return ;
	size = stack_size(*a);
	if (size <= 5)
		small_sort(a, b);
	else
		chunk_sort(a, b);
}
