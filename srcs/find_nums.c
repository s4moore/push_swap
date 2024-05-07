/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_pre_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 07:47:13 by samoore           #+#    #+#             */
/*   Updated: 2023/12/19 16:56:11 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_high(t_stack *stx)
{
	int	i;
	int	high;

	i = 0;
	high = 0;
	while (i < stx->a_len)
	{
		if (stx->a[i] > stx->a[high])
			high = i;
		i++;
	}
	return (high);
}

int	find_low(t_stack *stx)
{
	int	i;
	int	low;

	i = 0;
	low = 0;
	while (i < stx->a_len)
	{
		if (stx->a[i] < stx->a[low])
			low = i;
		i++;
	}
	return (low);
}

int	find_target_a(t_stack *stx, int j)
{
	int	i;
	int	low;

	i = find_low(stx);
	low = stx->a[i];
	if (stx->b[j] < stx->a[i])
		return (i);
	if (i == 0)
		i = stx->a_len - 1;
	else
		i -= 1;
	while (stx->a[i] != low && stx->a[i] < stx->b[j])
	{
		i--;
		if (i == -1)
			i = stx->a_len - 1;
	}
	return (i);
}

int	top(t_stack *stx)
{
	return (stx->a[stx->a_len - 1]);
}

int	find_pos(int *array, int num, int len)
{
	int	i;

	i = 0;
	while (i < len && array[i] != num)
		i++;
	return (i);
}
