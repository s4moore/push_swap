/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:54:37 by samoore           #+#    #+#             */
/*   Updated: 2023/12/19 14:47:48 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	free_stack(t_stack *stx)
{
	free (stx->a);
	free (stx->b);
	free (stx->sorted);
}

void	putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
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
