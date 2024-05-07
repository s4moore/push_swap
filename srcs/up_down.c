/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:56:14 by samoore           #+#    #+#             */
/*   Updated: 2023/12/19 17:04:43 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	up_up(t_stack *stx)
{
	while (stx->move_a > stx->move_b)
	{
		ra(stx);
		stx->move_a -= 1;
	}
	while (stx->move_b > stx->move_a)
	{
		rb(stx);
		stx->move_b -= 1;
	}
	while (stx->move_a > 0)
	{
		rr(stx);
		stx->move_a -= 1;
		stx->move_b -= 1;
	}
}

void	down_down(t_stack *stx)
{
	while (stx->move_a > stx->move_b)
	{
		rra(stx);
		stx->move_a -= 1;
	}
	while (stx->move_b > stx->move_a)
	{
		rrb(stx);
		stx->move_b -= 1;
	}
	while (stx->move_a > 0)
	{
		rrr(stx);
		stx->move_a -= 1;
		stx->move_b -= 1;
	}
}

int	up_or_down(int *nums, int *set, int len, int size)
{
	int	up;
	int	down;

	if (len == 0 || size == 0)
		return (0);
	up = 0;
	down = len - 1;
	if (in_set(nums[down], set, size))
		return (0);
	if (in_set(nums[down], set, size) == 1)
		return (down);
	while (up < len - 1 && (!in_set(nums[up], set, size)))
		up++;
	if (up == len - 1)
		return (0);
	while (!in_set(nums[down], set, size))
		down--;
	if (up < (len - 1 - down))
		return (UP);
	return (DOWN);
}
