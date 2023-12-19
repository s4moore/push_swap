/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_pre_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 07:47:13 by samoore           #+#    #+#             */
/*   Updated: 2023/12/19 11:10:05 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(int *nums, int a_len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < a_len)
	{
		if (nums[i] > nums[j])
			j = i;
		i++;
	}
	return (j);
}

void	ft_pre_sort(t_stack *stx, int num)
{
	int	rem;
	int	target;
	int	third;

	third = (stx->a_len) / 3;
	rem = stx->a_len % 3;
	if (third < 5)
		target = 5;
	else
		target = third;
	push_to_b(stx, target, third, rem);
	if (stx->a_len == 2)
	{
		if (top(stx) > stx->a[stx->a_len - 2])
			sa(stx);
		return ;
	}
	if (stx->a[stx->a_len - 2] == stx->sorted[2])
		rra(stx);
	else if (top(stx) == stx->sorted[2])
		ra(stx);
	if (top(stx) > stx->a[stx->a_len - 2])
		sa(stx);
}
