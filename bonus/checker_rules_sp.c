/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rules_sp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:36:18 by samoore           #+#    #+#             */
/*   Updated: 2023/12/18 19:48:25 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_stack *stx)
/* Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements. */
{
	int	swap;

	if (stx->a_len < 2)
		return ;
	swap = stx->a[stx->a_len - 1];
	stx->a[stx->a_len - 1] = stx->a[stx->a_len - 2];
	stx->a[stx->a_len - 2] = swap;
}

void	sb(t_stack *stx)
/* Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.*/
{
	int	swap;

	if (stx->b_len < 2)
		return ;
	swap = stx->b[stx->b_len - 1];
	stx->b[stx->b_len - 1] = stx->b[stx->b_len - 2];
	stx->b[stx->b_len - 2] = swap;
}

void	ss(t_stack *stx)
/* sa and sb at the same time.*/
{
	int	swap;

	if (stx->a_len < 2 || stx->b_len < 2)
		return ;
	swap = stx->a[stx->a_len - 1];
	stx->a[stx->a_len - 1] = stx->a[stx->a_len - 2];
	stx->a[stx->a_len - 2] = swap;
	swap = stx->b[stx->b_len - 1];
	stx->b[stx->b_len - 1] = stx->b[stx->b_len - 2];
	stx->b[stx->b_len - 2] = swap;
}

void	pa(t_stack *stx)
/* Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty*/
{
	if (stx->b_len == 0)
		return ;
	stx->a[stx->a_len] = stx->b[stx->b_len - 1];
	stx->b_len--;
	stx->a_len++;
}

void	pb(t_stack *stx)
/* Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty*/
{
	if (stx->a_len == 0)
		return ;
	stx->b[stx->b_len] = stx->a[stx->a_len - 1];
	stx->a_len--;
	stx->b_len++;
}
