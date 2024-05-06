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
/*
void	ft_pre_sort(t_stack *stx, int num)
{
	int	target;
	int	third;

	third = (stx->a_len) / 3;
	third = max(1, third);
	if (third < 5)
		target = 5;
	else
		target = third + rem;
	push_to_b(stx, target, third);
	sort_last(stx);
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

int	get_low_nums(t_stack *stx)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i < stx->lis_len)
	{
		if (find_sorted_pos(stx, stx->lis[i]) <= stx->total_nums - stx->total_nums / 3)
			res++;
		i++;
	}
	return (res);
}

void	ft_pre_sort(t_stack *stx)
{
	int	low_nums;

	//print_arr(stx->lis, stx->lis_len);
	//read(1, NULL, 1);
	low_nums = get_low_nums(stx);
	//target = max(stx->lis_len, (stx->total_nums - stx->total_nums / 3) + low_nums);
	push_to_b(stx, low_nums);
	//print_arr(stx->sorted, stx->sorted_len);
}
*/