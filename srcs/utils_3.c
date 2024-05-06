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

// void	clean_tail(t_stack *stx)
// {
// 	int	up_down;

// 	while (stx->a_len > 3)
// 	{
// 		up_down = up_or_down(stx->a, &stx->sorted[3], stx->a_len, 2);
// 		if (up_down == 0)
// 			pb(stx);
// 		else if (up_down == UP)
// 		{
// 			while (top(stx) != stx->sorted[4] && top(stx) != stx->sorted[3])
// 				rra(stx);
// 			pb(stx);
// 		}
// 		else
// 		{
// 			while (top(stx) != stx->sorted[4] && top(stx) != stx->sorted[3])
// 				ra(stx);
// 			pb(stx);
// 		}
// 	}
// }

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

int	get_low_nums(t_stack *stx)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i < stx->nums_to_split_len)
	{
		if (find_pos(stx->sorted, stx->nums_to_split[i], stx->sorted_len) > stx->total_nums - (stx->total_nums / 3))
			res++;
		i++;
	}
	return (res);
}

void	ft_pre_sort(t_stack *stx)
{
	int	sort_pos;
	int	low_nums;

	low_nums = get_low_nums(stx);
	while (stx->a_len > stx->lis_len + low_nums)
	{
		if (in_set(top(stx), stx->lis, stx->lis_len))
		{
			ra(stx);
			continue ;
		}
		sort_pos = find_pos(stx->sorted, top(stx), stx->sorted_len);
		if (sort_pos < stx->sorted_len / 3)
		{
			pb(stx);
			rb(stx);
		}
		else if (sort_pos > (stx->sorted_len - (stx->sorted_len / 3)))
		{
			ra(stx);
		}
		else 
		{
			pb(stx);
		}
	}
	sort_last(stx);
}

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