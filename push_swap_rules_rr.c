/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rules_rr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 09:27:48 by samoore           #+#    #+#             */
/*   Updated: 2023/12/18 19:13:50 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stx)
/* Shift down all elements of stack a by 1.
The last element becomes the first one.*/
{
	int	swap;
	int	i;

	if (stx->a_len < 2)
		return ;
	i = 0;
	swap = stx->a[i];
	while (i < stx->a_len - 1)
	{
		stx->a[i] = stx->a[i + 1];
		i++;
	}
	stx->a[i] = swap;
	putstr("rra\n");
	stx->moves++;
}

void	rrb(t_stack *stx)
/* Shift down all elements of stack b by 1.
The last element becomes the first one.*/
{
	int	swap;
	int	i;

	if (stx->b_len < 2)
		return ;
	i = 0;
	swap = stx->b[i];
	while (i < stx->b_len - 1)
	{
		stx->b[i] = stx->b[i + 1];
		i++;
	}
	stx->b[i] = swap;
	putstr("rrb\n");
	stx->moves++;
}

void	rrr(t_stack *stx)
/* rra and rrb at the same time.*/
{
	int	swap;
	int	i;

	if (stx->a_len < 2 || stx->b_len < 2)
		return ;
	i = 0;
	swap = stx->a[i];
	while (i < stx->a_len - 1)
	{
		stx->a[i] = stx->a[i + 1];
		i++;
	}
	stx->a[i] = swap;
	i = 0;
	swap = stx->b[i];
	while (i < stx->b_len - 1)
	{
		stx->b[i] = stx->b[i + 1];
		i++;
	}
	stx->b[i] = swap;
	putstr("rrr\n");
	stx->moves++;
}
