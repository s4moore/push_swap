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

void	print_arr(int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
		printf("%d ", arr[i++]);
	printf ("\n");
}

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

void	sort_nums(t_stack *stx)
{
	if (ft_sorted(stx))
	{
		free_stack(stx);
		exit (0);
	}
	stx->moves = 0;
	if (stx->total_nums > 3)
	{
		ft_pre_sort(stx);
		ft_sort(stx);
	}
	else
		if (!ft_nearly_sorted(stx))
			sa(stx);
}

int	main(int argc, char **argv)
{
	t_stack	stx;

	if (argc == 1)
	{
		putstr("Error\n");
		exit (1);
	}
	get_nums(argc, argv, &stx);
	sort_nums(&stx);
	smallest_to_top(&stx);
	free_stack(&stx);
}
