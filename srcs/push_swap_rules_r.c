/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rules_r.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 09:25:05 by samoore           #+#    #+#             */
/*   Updated: 2023/12/18 19:37:50 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stx)
/* Shift up all elements of stack a by 1.
The first element becomes the last one.*/
{
	int	swap;
	int	i;

	if (stx->a_len < 2)
		return ;
	i = stx->a_len - 1;
	swap = stx->a[i];
	while (i > 0)
	{
		stx->a[i] = stx->a[i - 1];
		i--;
	}
	stx->a[i] = swap;
	putstr("ra\n");
	stx->moves++;
}

void	rb(t_stack *stx)
/* Shift up all elements of stack b by 1.
The first element becomes the last one.*/
{
	int	swap;
	int	i;

	if (stx->b_len < 2)
		return ;
	i = stx->b_len - 1;
	swap = stx->b[i];
	while (i > 0)
	{
		stx->b[i] = stx->b[i - 1];
		i--;
	}
	stx->b[i] = swap;
	putstr("rb\n");
	stx->moves++;
}

void	rr(t_stack *stx)
/* ra and rb at the same time.*/
{
	int	swap;
	int	i;

	if (stx->a_len < 2 || stx->b_len < 2)
		return ;
	i = stx->a_len - 1;
	swap = stx->a[i];
	while (i > 0)
	{
		stx->a[i] = stx->a[i - 1];
		i--;
	}
	stx->a[i] = swap;
	putstr("rr\n");
	i = stx->b_len - 1;
	swap = stx->b[i];
	while (i > 0)
	{
		stx->b[i] = stx->b[i - 1];
		i--;
	}
	stx->b[i] = swap;
	stx->moves++;
}
