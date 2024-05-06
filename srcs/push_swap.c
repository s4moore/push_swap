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

int	top(t_stack *stx)
{
	return (stx->a[stx->a_len - 1]);
}

int	find_pos(int *array, int num, int len)
{
	int	i;

	i = 0;
	while (i < len && array[i] != num)
		i++;
	return (i);
}

void	push_to_a(t_stack *stx)
{
	if (stx->a_up_down == UP && stx->b_up_down == UP)
		up_up(stx);
	if (stx->a_up_down == DOWN && stx->b_up_down == DOWN)
		down_down(stx);
	while (stx->move_a > 0)
	{
		if (stx->a_up_down == UP)
			ra(stx);
		else if (stx->a_up_down == DOWN)
			rra(stx);
		stx->move_a -= 1;
	}
	while (stx->move_b > 0)
	{
		if (stx->b_up_down == UP)
			rb(stx);
		else if (stx->b_up_down == DOWN)
			rrb(stx);
		stx->move_b -= 1;
	}
	pa(stx);
}

void	ft_sort(t_stack *stx)
{
	t_move	mov;
	
	while (stx->b_len > 0)
	{
		find_best(stx, &mov);
		push_to_a(stx);
	}
}

int	ft_nearly_sorted(t_stack *stx)
{
	int	i;
	int	j;

	//print_arr(stx->a, stx->a_len);
	j = find_high(stx);
	i = j + 1;
	if (i == stx->a_len)
		i = 0;
	while (i != j)
	{
		if (i > 0 && stx->a[i] > stx->a[i - 1])
			return (0);
		else if (stx->a[i] > stx->a[stx->a_len - 1])
			return (0);
		i++;
		if (i == stx->a_len)
			i = 0;
	}
	return (1);
}

void	print_arr(int *arr, int len)
{
	int i = 0;
	while (i < len)
		printf("%d ", arr[i++]);
	printf ("\n");
}

int	main(int argc, char **argv)
{
	t_stack	stx;
	int		i;
	int		low;

	get_nums(argc, argv, &stx);
	if (ft_sorted(&stx))
		exit (0);
	stx.moves = 0;
	if (stx.total_nums > 3)
	{
		ft_pre_sort(&stx);
		ft_sort(&stx);
	}
	else
		if (!ft_nearly_sorted(&stx))
			sa(&stx);
	i = find_low(&stx);
	low = stx.a[i];
	if (i < stx.a_len / 2)
		while (top(&stx) != low)
			rra(&stx);
	else
		while (top(&stx) != low)
			ra(&stx);
	// print_arr(stx.a, stx.a_len);
	// print_arr(stx.b, stx.b_len);
	free_stack(&stx);
}
