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

void	sort_last(t_stack *stx)
{
	while (stx->a_len > stx->lis_len)
	{
		if (in_set(top(stx), stx->lis, stx->lis_len))
			ra(stx);
		else
			pb(stx);
	}
}

// int	get_low_nums(t_stack *stx)
// {
// 	int	i;
// 	int	res;

// 	i = 0;
// 	res = 0;
// 	while (i < stx->split_nums_len)
// 	{
// 		if (find_pos(stx->sorted, stx->split_nums[i], stx->sorted_len)
// 			< stx->total_nums - (stx->total_nums / 3))
// 			res++;
// 		i++;
// 	}
// 	return (res);
// }

void	ft_pre_sort_a(t_stack *stx)
{
	int	sort_pos;
	int	nums_div_3;

	nums_div_3 = stx->split_nums_len / 3;
	while (stx->a_len > (stx->lis_len + nums_div_3))
	{
		if (in_set(top(stx), stx->lis, stx->lis_len))
		{
			ra(stx);
			continue ;
		}
		sort_pos = find_pos(stx->split_nums, top(stx), stx->split_nums_len);
		if (sort_pos < stx->split_nums_len / 3)
			ra (stx);
		else if (sort_pos > (stx->split_nums_len - (stx->split_nums_len / 3)))
		{
			pb (stx);
			rb (stx);
		}
		else
			pb(stx);
	}
	sort_last(stx);
}

void	ft_pre_sort_b(t_stack *stx)
{
	int	sort_pos;

	while (stx->a_len > (stx->lis_len + stx->split_nums_len / 3))
	{
		if (in_set(top(stx), stx->lis, stx->lis_len))
		{
			ra(stx);
			continue ;
		}
		sort_pos = find_pos(stx->split_nums, top(stx), stx->split_nums_len);
		if (sort_pos < stx->split_nums_len / 3)
		{
			pb(stx);
			rb(stx);
		}
		else if (sort_pos > (stx->split_nums_len - (stx->split_nums_len / 3)))
		{
			ra(stx);
		}
		else
			pb(stx);
	}
	sort_last(stx);
}
