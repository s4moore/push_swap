/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:56:14 by samoore           #+#    #+#             */
/*   Updated: 2023/12/19 14:45:49 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	clean_tail(t_stack *stx)
{
	int	up_down;

	while (stx->a_len > 3)
	{
		up_down = up_or_down(stx->a, &stx->sorted[3], stx->a_len, 2);
		if (up_down == 0)
			pb(stx);
		else if (up_down == UP)
		{
			while (top(stx) != stx->sorted[4] && top(stx) != stx->sorted[3])
				rra(stx);
			pb(stx);
		}
		else
		{
			while (top(stx) != stx->sorted[4] && top(stx) != stx->sorted[3])
				ra(stx);
			pb(stx);
		}
	}
}

void	sort_last(t_stack *stx)
{
	while (stx->a_len > 5)
	{
		if (in_set(top(stx), stx->sorted, 5))
			ra(stx);
		else
			pb(stx);
	}
	if (stx->a_len == 5)
		clean_tail(stx);
}

void	push_to_b(t_stack *stx, int target, int third, int rem)
{
	int	sort_pos;

	while (stx->a_len > target)
	{
		sort_pos = find_sorted_pos(stx, top(stx));
		if (in_set(top(stx), stx->sorted, min(5, stx->a_len)))
			ra(stx);
		else if (sort_pos >= (stx->sorted_len - third - 1 - rem))
		{
			pb (stx);
			rb (stx);
		}
		else if (sort_pos >= (stx->sorted_len - (2 * third) - 1 - rem))
			pb (stx);
		else
			ra(stx);
	}
	sort_last(stx);
}
