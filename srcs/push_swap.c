/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:38:45 by samoore           #+#    #+#             */
/*   Updated: 2023/12/19 16:17:08 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	smallest_to_top(t_stack *stx)
{
	int	i;
	int	low;

	i = find_low(stx);
	low = stx->a[i];
	if (i < stx->a_len / 2)
		while (top(stx) != low)
			rra(stx);
	else
		while (top(stx) != low)
			ra(stx);
}

void	quick_sort(t_stack *stx)
{
	while (stx->a_len > 3)
		pb(stx);
	if (!ft_nearly_sorted(stx))
		sa(stx);
}

void	choose_and_sort(t_stack *stx)
{
	int	a;
	int	b;

	stx->final = 0;
	ft_pre_sort_a(stx);
	ft_sort(stx);
	a = stx->moves;
	stx->moves = 0;
	copy_nums(stx);
	ft_pre_sort_b(stx);
	ft_sort(stx);
	b = stx->moves;
	copy_nums(stx);
	stx->final = 1;
	if (a < b)
		ft_pre_sort_a(stx);
	else
		ft_pre_sort_b(stx);
	ft_sort(stx);
}

void	sort_nums(t_stack *stx)
{
	stx->moves = 0;
	stx->final = 1;
	if (stx->total_nums > 3)
	{
		if (stx->a_len <= 5)
		{
			quick_sort(stx);
			ft_sort(stx);
		}
		else
			choose_and_sort(stx);
	}
	else
		if (!ft_nearly_sorted(stx))
			sa(stx);
}

int	main(int argc, char **argv)
{
	t_stack	stx;

	if (argc == 1)
		exit (1);
	get_nums(argc, argv, &stx);
	if (ft_sorted(&stx))
	{
		free_stack(&stx);
		exit (0);
	}
	sort_nums(&stx);
	smallest_to_top(&stx);
	free_stack(&stx);
}
